#include <stdio.h>
#include <stdlib.h>

#include "glew.h"

#include "glfw3.h"

#include "glm/glm.hpp"

using namespace glm;

GLFWwindow* window;
int main( void )
{
	// Initialise GLFW
	// 初始化GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);// 4倍反锯齿
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);// 使用3.3版本的OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);// 使用3.3版本的OpenGL
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Mac系统需要加上这一句
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);// 我们使用核心模式

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		getchar();
		glfwTerminate();
		return -1;
	}
	//设置该窗口为当前上下文
	glfwMakeContextCurrent(window);

	// 初始化 GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.4f, 0.4f, 0.4f, 0.0f);

	do{
		// Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
		// 目前只关心颜色缓存
		glClear( GL_COLOR_BUFFER_BIT );

		// Draw nothing, see you in tutorial 2 !

		
		// Swap buffers
		//双缓冲
		glfwSwapBuffers(window);
		//获取键盘鼠标事件
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   !glfwWindowShouldClose(window));

	// Close OpenGL window and terminate GLFW
	//释放GLFW获取的内存
	glfwTerminate();

	return 0;
}

