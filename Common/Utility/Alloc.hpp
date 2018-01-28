//
// Created by 董宸 on 07/01/2018.
//

#ifndef LEARNINGOPENGL_ALLOC_HPP
#define LEARNINGOPENGL_ALLOC_HPP

#define NEW_OBJECT(obj) \
        new obj();
#define NEW_OBJECT1(obj, arg1) \
        new obj(arg1);
#define NEW_OBJECT2(obj, arg1, arg2) \
        new obj(arg1, arg2);



#define DELETE_OBJECT(obj) \
        delete obj;

#endif //LEARNINGOPENGL_ALLOC_HPP
