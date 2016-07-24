cmake_minimum_required(VERSION 3.1)
project(OpenGL_test)

if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pipe")
endif()

set(SRC
	src/main.cpp
	src/MainGame.cpp
	src/Video/Sprite.cpp
	src/Video/Shader.cpp)

include_directories(include)

add_executable(${PROJECT_NAME} ${SRC})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)

message(STATUS "The Flags are: ${CMAKE_CXX_FLAGS}")

if(MSVC)
	# Add SDL
	set(SDL2_LIBRARIES
		${PROJECT_SOURCE_DIR}/lib/msvc/sdl2/lib/x64/SDL2.lib
		${PROJECT_SOURCE_DIR}/lib/msvc/sdl2/lib/x64/SDL2main.lib)

	include_directories(lib/msvc/sdl2/include)

	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${PROJECT_SOURCE_DIR}/lib/msvc/sdl2/lib/x64/SDL2.dll"
	$<TARGET_FILE_DIR:${PROJECT_NAME}>)

	# Add GLEW
	set(GLEW_LIBRARIES
		${PROJECT_SOURCE_DIR}/lib/msvc/glew/lib/Release/x64/glew32.lib)

	include_directories(lib/msvc/glew/include)

	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${PROJECT_SOURCE_DIR}/lib/msvc/glew/bin/Release/x64/glew32.dll"
	$<TARGET_FILE_DIR:${PROJECT_NAME}>)

	set(WIN32_OPENGL_LIBS
		opengl32.lib)

else()
	INCLUDE(FindPkgConfig)

	pkg_search_module(SDL2 REQUIRED sdl2)
	pkg_search_module(GLEW REQUIRED glew)
	include_directories(${SDL2_INCLUDE_DIRS})
	include_directories(${GLEW_INCLUDE_LIBRARIES})
endif()

include_directories(lib/universal)

# Add shaders
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${PROJECT_SOURCE_DIR}/shaders
	$<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${GLEW_LIBRARIES} ${WIN32_OPENGL_LIBS})
