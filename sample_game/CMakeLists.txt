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

if(MSVC)
	# Need to add SDL2
	include_directories(../tewi/lib/msvc/sdl2/include)
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
