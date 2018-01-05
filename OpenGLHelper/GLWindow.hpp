//
// Created by 董宸 on 05/01/2018.
//

#ifndef LEARNINGOPENGL_WINDOW_HPP
#define LEARNINGOPENGL_WINDOW_HPP

#include <glfw3.h>

namespace OpenGLHelper{

    class GLWindow {
    public:

        GLWindow();
        GLWindow(int width, int height);

        void Show();

        int getWidth() const;

        void setWidth(int width);

        int getHeight() const;

        void setHeight(int height);

        void setCallback(GLFWkeyfun const);

        GLFWwindow *getWindow() const;

        bool ShouldClose();


    private:
        int width;
        int height;
        GLFWkeyfun callback;
        GLFWwindow* window;
    };

}



#endif //LEARNINGOPENGL_WINDOW_HPP
