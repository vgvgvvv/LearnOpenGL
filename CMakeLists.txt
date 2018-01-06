PROJECT("LearningOpenGL")

cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

find_package(OpenGL REQUIRED)

add_subdirectory(libs)

include_directories(
		libs/glew/include/GL/
		libs/glfw/include/GLFW/
		libs/glm/
		libs/stb/
		Common/
		OpenGLHelper/
		GameSystem/
		.
)

# opengl常用库
file(GLOB_RECURSE opengl_helper_script
		OpenGLHelper/*.cpp
		OpenGLHelper/*.hpp
		)

#通用C++组件
file(GLOB_RECURSE common_script
		Common/*.cpp
		Common/*.hpp)

#游戏引擎底层
file(GLOB_RECURSE game_system_script
		GameSystem/*.cpp
		GameSystem/*.hpp)

set(All_Scripts
		${common_script}
		${opengl_helper_script}
		${game_system_script}
		)

#所有库集合
set(ALL_LIBS
		${OPENGL_LIBRARY}
		${STB}
		glfw
		GLEW_1130
		STB
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

# tutorial 01 窗口
add_executable(HelloWindows
		LearnOpenGL/turtorial01/HelloWindows.cpp
		)
target_link_libraries(HelloWindows
		${ALL_LIBS}
		)

## turtorial 02 三角面片
add_executable(HelloTriangle
		LearnOpenGL/turtorial02/HelloTriangle.cpp
		${All_Scripts}
		)
target_link_libraries(HelloTriangle
		${ALL_LIBS}
		)

## turtorial 03 着色器
add_executable(HelloShader
		LearnOpenGL/turtorial03/HelloShader.cpp
		${All_Scripts}
		)
target_link_libraries(HelloShader
		${ALL_LIBS}
		)

# turtorial 04 纹理
add_executable(HelloTexture
		LearnOpenGL/turtorial04/HelloTexture.cpp
		${All_Scripts}
		)
target_link_libraries(HelloTexture
		${ALL_LIBS}
)
