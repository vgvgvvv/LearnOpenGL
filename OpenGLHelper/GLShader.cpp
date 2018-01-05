//
// Created by 董宸 on 05/01/2018.
//
#include "glew.h"
#include "glfw3.h"

#include "GLShader.hpp"
#include "GLShaderLoader.hpp"


namespace OpenGLHelper{

    GLShader::GLShader(const char *vertexShaderPath, const char *fragmentShaderPath) {
        this->programID = LoadProgram(vertexShaderPath, fragmentShaderPath);
    }

    void GLShader::Use() {
        glUseProgram(this->programID);
    }

    void GLShader::SetBool(const std::string name, bool value) {
        glUniform1i(glGetUniformLocation(this->programID, name.c_str()), (int)value);
    }

    void GLShader::SetInt(const std::string name, int value) {
        glUniform1i(glGetUniformLocation(this->programID, name.c_str()), value);
    }

    void GLShader::SetFloat(const std::string name, float value) {
        glUniform1i(glGetUniformLocation(this->programID, name.c_str()), value);
    }

    GLuint GLShader::GetProgramID() const {
        return programID;
    }

}

