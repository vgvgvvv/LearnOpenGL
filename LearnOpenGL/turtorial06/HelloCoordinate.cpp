//
// Created by 董宸 on 07/01/2018.
//

#include "OpenGLAllInOne.hpp"

using namespace ReOpenGL;

int main(){

    GLWindow window(800, 600);
    window.Show();

    GLShader shader("vertexShader.glsl", "fragmentShader.glsl");

    GLTexture texture("../Resources/Images/timg.jpeg");
    texture.Build();


    GLfloat vertices[] = {
            // positions          // colors           // texture coords
            0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
            0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left
    };

    GLuint indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
    };

    GLMesh mesh(vertices, 4, indices, 2);
    mesh.AddVertexProperty(3, "aPos", GL_FLOAT, GL_FALSE);
    mesh.AddVertexProperty(3, "aColor", GL_FLOAT, GL_FALSE);
    mesh.AddVertexProperty(2, "aTexCoord", GL_FLOAT, GL_FALSE);
    mesh.Build();


    shader.Use();
    glUniform1i(glGetUniformLocation(shader.GetProgramID(), "texture1"), 0);

    while (!window.ShouldClose())
    {
        // input
        // -----
        GLWindow::DefaultProcessInput(window.getWindow());

        // render
        // ------
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind textures on corresponding texture units

        texture.Use(GL_TEXTURE0);
        shader.Use();

        // create transformations
        glm::mat4 model;
        glm::mat4 view;
        glm::mat4 projection;
        model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        projection = glm::perspective(glm::radians(-45.0f), (float)window.getWidth() / (float)window.getHeight(), 0.1f, 100.0f);
        shader.SetMat4("view", view);
        shader.SetMat4("model", model);
        shader.SetMat4("projection", projection);

        mesh.Render(GL_TRIANGLES);


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window.getWindow());
        glfwPollEvents();
    }

    mesh.Uninit();
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;

}