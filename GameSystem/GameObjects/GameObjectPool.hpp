//
// Created by 董宸 on 18/01/2018.
//

#ifndef LEARNINGOPENGL_GAMEOBJECTPOOL_HPP
#define LEARNINGOPENGL_GAMEOBJECTPOOL_HPP


#include <vector>
#include "GameObject.hpp"

namespace ReEngine{
    class GameObjectPool {
    public:
        static GameObjectPtr GetObject();
    private:

    };
}



#endif //LEARNINGOPENGL_GAMEOBJECTPOOL_HPP
