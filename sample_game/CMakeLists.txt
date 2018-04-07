cmake_minimum_required(VERSION 3.9)
cmake_policy(SET CMP0069 NEW)
project(OpenGL_test)

include(CheckIPOSupported)

set(SRC
	src/main.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
add_executable(${PROJECT_NAME} ${SRC})

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON)

check_ipo_supported(RESULT lto_supported)
if (lto_supported)
    set_target_properties(${PROJECT_NAME}
        PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

if(MSVC)
	target_compile_options(${PROJECT_NAME}
		PRIVATE
        /W4 /std:c++latest /permissive- /GR-)

	# Release
 	target_compile_options(${PROJECT_NAME} 
 		PRIVATE
 		$<$<CONFIG:RELEASE>:/Ob2 /Ot /GL /sdl- /LTCG>)
else()
	target_compile_options(${PROJECT_NAME}
		PRIVATE
		-Wall -pipe -Wno-pragma-once-outside-header -fno-rtti -fno-omit-frame-pointer)

	# Release
	target_compile_options(${PROJECT_NAME}
		PRIVATE
		$<$<CONFIG:RELEASE>:-O3>)
endif()


if(WIN32)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${CMAKE_SOURCE_DIR}/tewi/lib/msvc/glew/bin/Release/x64/glew32.dll"
	$<TARGET_FILE_DIR:${PROJECT_NAME}>)

	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${CMAKE_SOURCE_DIR}/tewi/lib/msvc/glew/bin/Release/x64/glew32.dll"
	$<TARGET_FILE_DIR:${PROJECT_NAME}>)

	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${CMAKE_SOURCE_DIR}/tewi/lib/msvc/vulkan/bin/vulkan-1.dll"
	$<TARGET_FILE_DIR:${PROJECT_NAME}>)

endif()

target_include_directories(${PROJECT_NAME} PRIVATE include)

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}")

set_target_properties(tewi
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}")

set_target_properties(glfw
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}")

target_link_libraries(${PROJECT_NAME} tewi)

# Add shaders
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${PROJECT_SOURCE_DIR}/shaders
	$<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${PROJECT_SOURCE_DIR}/textures
	$<TARGET_FILE_DIR:${PROJECT_NAME}>/textures)

