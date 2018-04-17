//
// Created by 董宸 on 18/01/2018.
//

#include <Utility/Alloc.hpp>
#include "GameObjectPool.hpp"

namespace ReEngine{
    GameObjectPtr GameObjectPool::GetObject() {
        //TODO 暂时使用New 后面再使用池子
        GameObjectPtr newObj = NEW_OBJECT(GameObject);
        return newObj;
    }
}