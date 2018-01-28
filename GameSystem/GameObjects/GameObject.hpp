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

namespace ReEngine{

    class GameObject;
    typedef std::shared_ptr<GameObject> GameObjectPtr;
    class GameObject : IReusable{
    public:

        template <typename T, typename... TArgs> auto AddComponent(TArgs&&... args)->GameObjectPtr;

        template <typename T> auto RemoveComponent() -> GameObjectPtr;

        template<typename T> bool HasComponent<T>();

    protected:
        virtual void Awake() = 0;
        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void OnDestroy() = 0;
    private:
        std::vector<Component*> components;
    };
}



#endif //LEARNINGOPENGL_GAMEOBJECT_HPP
