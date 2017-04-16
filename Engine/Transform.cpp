/* 
 * File:   Transform.cpp
 * Author: dsbatts
 * 
 * Created on April 15, 2017, 9:11 PM
 */

#include "Transform.h"

namespace baby {
    
    Transform::Transform(Engine* instance, long guid) : Transform(instance, guid, NULL){}
    Transform::Transform(Engine* instance, long guid, EngineComponent* parent) : EngineComponent(instance, guid, instance->getTypeID(TRANSFORM_TYPE), parent)
    {
    }

    Transform::~Transform(){}

    void Transform::update(){}
    void Transform::setup(){}

    //std::size_t Transform::operator()(const Transform& v) const;
    bool Transform::operator==(const Transform& v) const {return true;}
    bool Transform::operator!=(const Transform& v) const {return false;}
    Transform& Transform::operator=(const Transform& v) {return *this;}
}
