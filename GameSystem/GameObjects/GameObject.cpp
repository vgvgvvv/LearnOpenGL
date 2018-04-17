//
// Created by 董宸 on 07/01/2018.
//

#include <memory>
#include "GameObject.hpp"


namespace ReEngine{

    //TODO 实现Component工具函数
    template<typename T, typename... TArgs>
    auto GameObject::AddComponent(TArgs &&... args) -> GameObjectPtr {

        return this;
    }

    template<typename T>
    auto GameObject::RemoveComponent() -> GameObjectPtr {
        return this;
    }

    template<typename T>
    bool GameObject::HasComponent() {
        return false;
    }

    void GameObject::Awake() {

    }

    void GameObject::Start() {

    }

    void GameObject::Update() {

    }

    void GameObject::OnDestroy() {

    }
}