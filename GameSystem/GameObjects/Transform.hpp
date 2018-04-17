//
// Created by 董宸 on 2018/4/15.
//

#ifndef LEARNINGOPENGL_TRANSFORM_HPP
#define LEARNINGOPENGL_TRANSFORM_HPP


#include <glm/vec3.hpp>

class Transform {
public:
    Transform* parent;
    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 eulerAngle;
};


#endif //LEARNINGOPENGL_TRANSFORM_HPP
