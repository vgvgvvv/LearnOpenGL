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

    GLOldMesh mesh(vertices, 4, indices, 2);
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

        // create transformations
        glm::mat4 transform;
        transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
        transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        transform = glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.5f));

        texture.Use(GL_TEXTURE0);
        shader.Use();

        unsigned int transformLoc = glGetUniformLocation(shader.GetProgramID(), "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

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