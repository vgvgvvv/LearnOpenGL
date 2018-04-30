//
// Created by 董宸 on 07/01/2018.
//

/**
 * ECS中的E，作为游戏世界的主体
 */
#ifndef LEARNINGOPENGL_GAMEOBJECT_HPP
#define LEARNINGOPENGL_GAMEOBJECT_HPP

#include <Components/Component.hpp>
#include <Utility/IReusable.hpp>
#include <vector>
#include <string>
#include "Components/Transform.hpp"

namespace ReEngine{

    class Entity;
    typedef Entity* EntityPtr;
    class Entity {
    public:

        EntityPtr AddComponent(const Component& component);
        EntityPtr RemoveComponent(std::string name);
        bool HasComponent(std::string name);

    protected:
        virtual void Awake();
        virtual void Start();
        virtual void Update();
        virtual void OnDestroy();
    private:
        std::vector<Component&> components;
        Transform transform;
    };
}



#endif //LEARNINGOPENGL_GAMEOBJECT_HPP
