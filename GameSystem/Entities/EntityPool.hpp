//
// Created by 董宸 on 18/01/2018.
//

#ifndef LEARNINGOPENGL_GAMEOBJECTPOOL_HPP
#define LEARNINGOPENGL_GAMEOBJECTPOOL_HPP


#include <vector>
#include "Entity.hpp"

namespace ReEngine{
    class GameObjectPool {
    public:
        static EntityPtr GetObject();
    private:

    };
}



#endif //LEARNINGOPENGL_GAMEOBJECTPOOL_HPP
