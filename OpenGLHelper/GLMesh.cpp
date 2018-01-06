//
// Created by 董宸 on 07/01/2018.
//

#include "GLMesh.hpp"

namespace ReOpenGL{

    GLMesh::GLMesh(GLfloat vertices[], GLuint indices[]) :
        VAO_ID(0),
        VBO_ID(0),
        EBO_ID(0),
        vertices(vertices),
        indices(indices),
        drawType(GL_STATIC_DRAW)
    {

        glGenVertexArrays(1, &VAO_ID);
        glGenBuffers(1, &VBO_ID);
        glGenBuffers(1, &EBO_ID);

        glBindVertexArray(VAO_ID);

        glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    }

    GLMesh::~GLMesh() {
        glDeleteVertexArrays(1, &VAO_ID);
        glDeleteBuffers(1, &VBO_ID);
        glDeleteBuffers(1, &EBO_ID);
    }

    void GLMesh::Render() {
        glBindVertexArray(VAO_ID);
    }

    GLuint GLMesh::getVAO_ID() const {
        return VAO_ID;
    }

    GLuint GLMesh::getVBO_ID() const {
        return VBO_ID;
    }

    GLuint GLMesh::getEBO_ID() const {
        return EBO_ID;
    }

}