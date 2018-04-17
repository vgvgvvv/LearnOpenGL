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
#include "Transform.hpp"

namespace ReEngine{

    class GameObject;
    typedef GameObject* GameObjectPtr;
    class GameObject {
    public:


        template <typename T, typename... TArgs> auto AddComponent(TArgs&&... args)->GameObjectPtr;
        template <typename T> auto RemoveComponent() -> GameObjectPtr;
        template<typename T> bool HasComponent();

        Transform Transfrom();

    protected:
        virtual void Awake();
        virtual void Start();
        virtual void Update();
        virtual void OnDestroy();
    private:
        std::vector<Component*> components;
        Transform transform;
    };
}



#endif //LEARNINGOPENGL_GAMEOBJECT_HPP
