//
// Created by 董宸 on 05/01/2018.
//

#ifndef LEARNINGOPENGL_GLSHADER_HPP
#define LEARNINGOPENGL_GLSHADER_HPP

#include <string>

namespace OpenGLHelper{

    class GLShader {
    public:

        /**
         * 初始化
         * @param vertexShaderPath
         * @param fragmentShaderPath
         */
        GLShader(const char* vertexShaderPath, const char* fragmentShaderPath);
        /**
         * 使用Shader程序
         */
        void Use();
        /**
         * 设置Bool值
         * @param name
         * @param value
         */
        void SetBool(const std::string name, bool value);
        /**
         * 设置Int值
         * @param name
         * @param value
         */
        void SetInt(const std::string name, int value);
        /**
         * 设置Float值
         * @param name
         * @param value
         */
        void SetFloat(const std::string name, float value);

        /**
         * 获得ID
         * @return
         */
        GLuint GetProgramID() const;

    private:
        GLuint programID;

    };

}



#endif //LEARNINGOPENGL_GLSHADER_HPP
