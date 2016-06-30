cmake_minimum_required(VERSION 2.8)
project(OpenGL_test)

set(SRC
	src/main.cpp)

include_directories(include)

add_executable(OpenGL_test_engine ${SRC})
