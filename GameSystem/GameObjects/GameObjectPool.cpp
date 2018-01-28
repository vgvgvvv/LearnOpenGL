//
// Created by 董宸 on 18/01/2018.
//

#include "GameObjectPool.hpp"

namespace ReEngine{
    GameObjectPtr GameObjectPool::GetObject() {
        //TODO 暂时使用New 后面再使用池子
        GameObjectPtr newObj = std::make_shared<GameObject>();
        return newObj;
    }
}