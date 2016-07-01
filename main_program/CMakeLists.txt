cmake_minimum_required(VERSION 2.8)
project(OpenGL_test)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" -std=c++14)

set(SRC
	src/main.cpp)


include_directories(include)

add_executable(${PROJECT_NAME} ${SRC})


if(MSVC)
	include_directories(lib/msvc/sdl2/include)
	set(SDL2_LIBRARIES
		lib/msvc/sdl2/lib/x64/SDL2
		lib/msvc/sdl2/lib/x64/SDL2main)
else()
	INCLUDE(FindPkgConfig)

	pkg_search_module(SDL2 REQUIRED sdl2)
	include_directories(${SDL2_INCLUDE_DIRS})
endif()

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
