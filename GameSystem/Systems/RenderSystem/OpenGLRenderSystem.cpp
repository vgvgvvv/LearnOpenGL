//
// Created by 董宸 on 07/01/2018.
//

#include <Utility/ObjectPool.hpp>
#include "OpenGLRenderSystem.hpp"
#include "World.hpp"

namespace ReEngine{


    bool OpenGLRenderSystem::Init() {

        window =  NEW_OBJECT2(GLWindow, 800, 600);
        window->Show();

        return true;
    }

    void OpenGLRenderSystem::Update() {

        GLWindow::DefaultProcessInput(window->getWindow());

        // render
        // ------
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        glfwSwapBuffers(window->getWindow());
        glfwPollEvents();
    }

    void OpenGLRenderSystem::Uninit() {
        glfwTerminate();
        DELETE_OBJECT(window);
    }

    bool OpenGLRenderSystem::GetShouldCloseWindow() {
        if(World::GetInstance().ShouldQuit()){
            return true;
        }
        return false;
    }
}