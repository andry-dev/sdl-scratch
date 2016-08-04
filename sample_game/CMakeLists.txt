cmake_minimum_required(VERSION 3.1)
project(OpenGL_test)

if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pipe")
endif()

set(SRC
	src/main.cpp
	src/MainGame.cpp)

include_directories(include)

add_executable(${PROJECT_NAME} ${SRC})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)

message(STATUS "The Flags are: ${CMAKE_CXX_FLAGS}")

include_directories(../tewi/include)

message(STATUS "CMAKE_CURRENT_LIST_DIR:         " ${CMAKE_CURRENT_LIST_DIR})
message(STATUS "CMAKE_BINARY_DIR:         " ${CMAKE_BINARY_DIR})
message(STATUS "CMAKE_CURRENT_BINARY_DIR:         " ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS "CMAKE_SOURCE_DIR:         " ${CMAKE_SOURCE_DIR})
message(STATUS "CMAKE_CURRENT_SOURCE_DIR:         " ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "PROJECT_BINARY_DIR:         " ${PROJECT_BINARY_DIR})
message(STATUS "PROJECT_SOURCE_DIR:         " ${PROJECT_SOURCE_DIR})

if(MSVC)
	include_directories(${CMAKE_SOURCE_DIR}/tewi/lib/msvc/sdl2/include)
	include_directories(${CMAKE_SOURCE_DIR}/tewi/lib/msvc/glew/include)

	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${CMAKE_SOURCE_DIR}/tewi/lib/msvc/glew/bin/Release/x64/glew32.dll"
	$<TARGET_FILE_DIR:OpenGL_test>)

	add_custom_command(TARGET OpenGL_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${CMAKE_SOURCE_DIR}/tewi/lib/msvc/sdl2/lib/x64/SDL2.dll"
	$<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()

# Add shaders
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${PROJECT_SOURCE_DIR}/shaders
	$<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${PROJECT_SOURCE_DIR}/textures
	$<TARGET_FILE_DIR:${PROJECT_NAME}>/textures)

target_link_libraries(${PROJECT_NAME} tewi)
