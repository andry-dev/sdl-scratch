cmake_minimum_required(VERSION 2.8)
project(OpenGL_test)

set(SRC
	src/main.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
add_executable(${PROJECT_NAME} ${SRC})

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON)

if(MSVC)
	target_compile_options(${PROJECT_NAME}
		PRIVATE
		/W4 /std:c++latest)

	# Release
# 	target_compile_options(${PROJECT_NAME} 
# 		PRIVATE
# 		$<$<CONFIG:RELEASE>:/O2 /Ob2 /Ot /GR- /GL /sdl- /LTCG)
else()
	target_compile_options(${PROJECT_NAME}
		PRIVATE
		-Wall -pipe -Wno-pragma-once-outside-header -fno-rtti -fno-omit-frame-pointer)

	# Release
	target_compile_options(${PROJECT_NAME}
		PRIVATE
		$<$<CONFIG:RELEASE>:-O3>)

	if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" AND
		${CMAKE_CXX_COMPILER_VERSION} VERSION_EQUAL 5.0.0)
			message(WARNING "[game] You're using Clang trunk, -flto disabled")
	else()
		target_compile_options(${PROJECT_NAME}
			PRIVATE
			$<$<CONFIG:RELEASE>:-flto>)

		target_compile_options(tewi
			PRIVATE
			$<$<CONFIG:RELEASE>:-flto>)

		target_compile_options(glfw
			PRIVATE
			$<$<CONFIG:RELEASE>:-flto>)
	endif()
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

