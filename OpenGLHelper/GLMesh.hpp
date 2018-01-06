//
// Created by 董宸 on 07/01/2018.
//

#ifndef LEARNINGOPENGL_GLMESH_HPP
#define LEARNINGOPENGL_GLMESH_HPP

#include "OpenGLAllInOne.hpp"

namespace ReOpenGL{

    //TODO 封装Mesh！！！
    class GLMesh {
    public:
        GLMesh(GLfloat vertices[], GLuint indices[]);
        ~GLMesh();

        void Render();

        GLuint getVAO_ID() const;

        GLuint getVBO_ID() const;

        GLuint getEBO_ID() const;

    private:

        GLuint VAO_ID;
        GLuint VBO_ID;
        GLuint EBO_ID;

        GLfloat vertices[];
        GLuint indices[];

        GLenum drawType;
    };
}

#endif //LEARNINGOPENGL_GLMESH_HPP
