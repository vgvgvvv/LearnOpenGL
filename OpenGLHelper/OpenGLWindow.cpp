//
// Created by 董宸 on 05/01/2018.
//

#include <cstdio>
#include <glew.h>
#include "OpenGLWindow.hpp"

namespace OpenGLHelper{

    OpenGLWindow::OpenGLWindow() :
            width(800),
            height(600),
            callback(nullptr)
    {

    }

    OpenGLWindow::OpenGLWindow(int width, int height){
        this->width = width;
        this->height = height;
    }


    void OpenGLWindow::Show() {

        if( !glfwInit() )
        {
            fprintf( stderr, "Failed to initialize GLFW\n" );
            getchar();
            return;
        }
        //基本设置
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Mac系统需要加上这一句
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        //创建窗口
        window = glfwCreateWindow(width, height, "LearnOpenGL", nullptr, nullptr);
        if( window == NULL ){
            fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
            getchar();
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);

        //设置回调
        if(callback)
            glfwSetKeyCallback(window, callback);

        //
        glewExperimental = GL_TRUE;
        //初始化glew
        glewInit();

        //定义viewport
        int portWidth, portHeight;
        glfwGetFramebufferSize(window, &portWidth, &portHeight);
        glViewport(0, 0, portWidth, portHeight);

    }

    GLFWwindow *OpenGLWindow::getWindow() const {
        return window;
    }

    int OpenGLWindow::getWidth() const {
        return width;
    }

    void OpenGLWindow::setWidth(int width) {
        OpenGLWindow::width = width;
    }

    int OpenGLWindow::getHeight() const {
        return height;
    }

    void OpenGLWindow::setHeight(int height) {
        OpenGLWindow::height = height;
    }

    void OpenGLWindow::setCallback(GLFWkeyfun const) {
        OpenGLWindow::callback = callback;
    }
}

