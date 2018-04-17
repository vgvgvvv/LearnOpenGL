//
// Created by 董宸 on 19/01/2018.
//

#include <memory>
#include <GameObjects/GameObjectPool.hpp>
#include "GameObjectSystem.hpp"

namespace ReEngine{

    bool GameObjectSystem::Init() {
        return true;
    }

    void GameObjectSystem::Update() {

    }

    void GameObjectSystem::Uninit() {

    }

    auto GameObjectSystem::CreateGameObject() -> GameObjectPtr {
        return GameObjectPool::GetObject();
    }
}