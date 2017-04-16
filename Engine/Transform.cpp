/* 
 * File:   Transform.cpp
 * Author: dsbatts
 * 
 * Created on April 15, 2017, 9:11 PM
 */

#include "Transform.h"

namespace baby {
    
    const std::string Transform::transform_id = TRANSFORM_TYPE;
    
    Transform::Transform(Engine* instance, long guid) : Transform(instance, guid, NULL){}
    Transform::Transform(Engine* instance, long guid, EngineComponent* parent) : EngineComponent(instance, guid, Transform::transform_id, parent)
    {
        this->orientation = 0;
        this->angularVelocity = 0;
        this->angularAcceleration = 0;
    }

    Transform::~Transform()
    {
        this->position.~Vector();
        this->velocity.~Vector();
        this->acceleration.~Vector();
    }

    void Transform::update()
    {
        this->position += (this->velocity * this->engine->getDeltaT());
        this->velocity += (this->acceleration * this->engine->getDeltaT());
        this->orientation += this->angularVelocity;
        this->angularVelocity += this->angularAcceleration;
        if (this->orientation >= 360.0f)
            this->orientation -= 360.0f;
        
    }
    void Transform::setup(){}

    //std::size_t Transform::operator()(const Transform& v) const;
    bool Transform::operator==(const Transform& t) const
    {
        return (this->position == t.position) && (this->velocity == t.velocity) &&
               (this->acceleration == t.acceleration) && (this->orientation == t.orientation) &&
               (this->angularVelocity == t.angularVelocity) && (this->angularAcceleration == t.angularAcceleration);
    }
    
    bool Transform::operator!=(const Transform& t) const {return !(*this == t);}
    Transform& Transform::operator=(const Transform& t)
    {
        if (this == &t)
            return *this;
        Transform* newT = new Transform(this->engine, this->guid, this->parent);
        newT->children = this->children;
        newT->position = this->position;
        newT->velocity = this->velocity;
        newT->acceleration = this->acceleration;
        newT->orientation = this->orientation;
        newT->angularVelocity = this->angularVelocity;
        newT->angularAcceleration = this->angularAcceleration;
        return *newT;
    }
}
