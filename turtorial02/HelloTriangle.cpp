#include <stdio.h>
#include <stdlib.h>

#include "glew.h"

#include "glfw3.h"

#include "glm/glm.hpp"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

const GLuint WIDTH = 800;
const GLuint HEIGHT = 600;

int main(){
    
    glfwInit();
    //基本设置
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    //创建窗口
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    //设置回调
    glfwSetKeyCallback(window, key_callback);

    //
    glewExperimental = GL_TRUE;
    //初始化glew
    glewInit();
}