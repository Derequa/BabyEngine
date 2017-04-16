/* 
 * File:   Transform.cpp
 * Author: dsbatts
 * 
 * Created on April 15, 2017, 9:11 PM
 */

#include "Transform.h"
#include "Engine.h"

namespace baby {
    
    const std::string Transform::transform_id = TRANSFORM_TYPE;
    
    Transform::Transform(long guid) : Transform(guid, NULL){}
    Transform::Transform(long guid, EngineComponent* parent) : EngineComponent(guid, Transform::transform_id, parent)
    {
        this->angle = 0;
        this->angularVelocity = 0;
        this->angularAcceleration = 0;
        this->scale.set(1.0f, 1.0f, 1.0f);
    }

    Transform::~Transform()
    {
        this->position.~Vector();
        this->velocity.~Vector();
        this->acceleration.~Vector();
        this->scale.~Vector();
        this->orientation.~Vector();
    }

    void Transform::update()
    {
        this->position += (this->velocity * Engine::getDeltaT());
        this->velocity += (this->acceleration * Engine::getDeltaT());
        this->angle += (this->angularVelocity * Engine::getDeltaT());
        this->angularVelocity += (this->angularAcceleration * Engine::getDeltaT());
        if (this->angle >= 360.0f)
            this->angle -= 360.0f;
        
    }
    void Transform::setup(){}

    //std::size_t Transform::operator()(const Transform& v) const;
    bool Transform::operator==(const Transform& t) const
    {
        return (this->position == t.position) && (this->velocity == t.velocity) &&
               (this->acceleration == t.acceleration) && (this->orientation == t.orientation) &&
                (this->scale == t.scale) && (this->angle == t.angle) &&
               (this->angularVelocity == t.angularVelocity) && (this->angularAcceleration == t.angularAcceleration);
    }
    
    bool Transform::operator!=(const Transform& t) const {return !(*this == t);}
    Transform& Transform::operator=(const Transform& t)
    {
        if (this == &t)
            return *this;
        Transform* newT = new Transform(this->guid, this->parent);
        newT->children = this->children;
        newT->position = this->position;
        newT->velocity = this->velocity;
        newT->acceleration = this->acceleration;
        newT->orientation = this->orientation;
        newT->scale = this->scale;
        newT->angle = this->angle;
        newT->angularVelocity = this->angularVelocity;
        newT->angularAcceleration = this->angularAcceleration;
        return *newT;
    }
}
