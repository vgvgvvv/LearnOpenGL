//
// Created by 董宸 on 2018/4/17.
//

#include <GLMesh.hpp>
#include "OpenGLAllInOne.hpp"

using namespace ReOpenGL;

int main(){

    GLWindow window(800, 600);
    window.Show();

    GLShader shader("vertexShader.glsl", "fragmentShader.glsl");

    GLModel model("../Resources/nanosuit.obj");


    while (!window.ShouldClose()){

        // input
        // -----
        GLWindow::DefaultProcessInput(window.getWindow());

        // render
        // ------
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        model.Draw(shader);

    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();

}