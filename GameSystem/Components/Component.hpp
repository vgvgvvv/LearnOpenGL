//
// Created by 董宸 on 07/01/2018.
//

/**
 * ECS中的C，游戏实体上的组件
 */
#ifndef LEARNINGOPENGL_COMPONENT_HPP
#define LEARNINGOPENGL_COMPONENT_HPP

namespace ReEngine{
    class Component {
    public:
        virtual void Awake() = 0;
        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void UnInit() = 0;
    };

}


#endif //LEARNINGOPENGL_COMPONENT_HPP
