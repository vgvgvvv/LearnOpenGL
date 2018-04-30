//
// Created by 董宸 on 19/01/2018.
//

#include <memory>
#include <Entities/EntityPool.hpp>
#include "EntitySystem.hpp"

namespace ReEngine{

    bool GameObjectSystem::Init() {
        return true;
    }

    void GameObjectSystem::Update() {

    }

    void GameObjectSystem::Uninit() {

    }

    auto GameObjectSystem::CreateGameObject() -> EntityPtr {
        return GameObjectPool::GetObject();
    }
}