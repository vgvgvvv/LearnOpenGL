PROJECT("LearningOpenGL")

cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

find_package(OpenGL REQUIRED)

add_subdirectory(libs)

include_directories(
		libs/glew/include/GL/
		libs/glfw/include/GLFW/
		libs/glm/
		Common/
		OpenGLHelper/
		.
)

# opengl常用库
file(GLOB_RECURSE opengl_helper_script
		OpenGLHelper/*.cpp
		OpenGLHelper/*.hpp
		)

file(GLOB_RECURSE common_script
		Common/*.cpp
		Common/*.hpp)

set(All_Scripts
		${common_script}
		${opengl_helper_script}
		)

#所有库集合
set(ALL_LIBS
		${OPENGL_LIBRARY}
		glfw
		GLEW_1130
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)



# 测试GLFW
add_executable(Test
		GLFWTest/Test.c
		)
target_link_libraries(Test
	${ALL_LIBS}
)

# tutorial 01
add_executable(HelloWindows
		turtorial01/HelloWindows.cpp
		)
target_link_libraries(HelloWindows
		${ALL_LIBS}
		)

## turtorial 02
add_executable(HelloTriangle
		turtorial02/HelloTriangle.cpp
		${All_Scripts}
		)
target_link_libraries(HelloTriangle
		${ALL_LIBS}
		)

## turtorial 03
add_executable(HelloShader
		turtorial03/HelloShader.cpp
		${All_Scripts}
		)
target_link_libraries(HelloShader
		${ALL_LIBS}
		)