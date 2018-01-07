//
// Created by 董宸 on 07/01/2018.
//

#include "GLMesh.hpp"

namespace ReOpenGL{

    GLMesh::GLMesh(GLfloat* vertices, GLint vertexNumber, GLuint indices[], GLint indicesNumber) :
        VAO_ID(0),
        VBO_ID(0),
        EBO_ID(0),
        vertices(vertices),
        vertexNumber(vertexNumber),
        vertexSize(0),
        indices(indices),
        indicesNumber(indicesNumber),
        drawType(GL_STATIC_DRAW)
    {
    }

    GLMesh::~GLMesh() {

    }

    void GLMesh::Build() {
        glGenVertexArrays(1, &VAO_ID);
        glGenBuffers(1, &VBO_ID);
        glGenBuffers(1, &EBO_ID);

        glBindVertexArray(VAO_ID);

        //确定尺寸
        vertexSize = 0;
        for(auto attr : vertexAttrVec){
            vertexSize += attr.size;
        }

        glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertexNumber * vertexSize, vertices, drawType);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indicesNumber * 3, indices, drawType);

        //添加属性
        int index = 0;
        int offset = 0;
        int typeSize = sizeof(GLfloat);
        for(auto attr : vertexAttrVec){
            glVertexAttribPointer(index, attr.size, attr.type, attr.normalized, vertexSize * typeSize, (void*)offset);
            glEnableVertexAttribArray(index);
            index ++;
            offset += attr.size * typeSize;
        }
        //解绑
        glBindBuffer(GL_ARRAY_BUFFER, NULL);
        glBindVertexArray(NULL);
    }

    void GLMesh::Uninit() {
        glDeleteVertexArrays(1, &VAO_ID);
        glDeleteBuffers(1, &VBO_ID);
        glDeleteBuffers(1, &EBO_ID);
    }

    void GLMesh::AddVertexProperty(int size, std::string name, GLenum type, GLboolean normalized) {

        GLVertexAttribute attribute;
        attribute.name = name;
        attribute.type = type;
        attribute.size = size;
        attribute.normalized = normalized;
        vertexAttrVec.push_back(attribute);
    }

    void GLMesh::Render(GLenum renderType) {
        glBindVertexArray(VAO_ID);
        glDrawElements(renderType, indicesNumber * 3, GL_UNSIGNED_INT, 0);

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