/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DebugObject.cpp
 * Author: dsbatts
 * 
 * Created on April 16, 2017, 2:19 AM
 */

#include "DebugObject.h"

namespace baby {
    const std::string DebugObject::debugobject_type = DEBUGOBJ_TYPE;
    const float DebugObject::material[] = {0.0f, 1.0f, 1.0f, 0.0f};
    
    DebugObject::DebugObject(long guid) : DebugObject(guid, NULL) {}
    DebugObject::DebugObject(long guid, EngineComponent* parent) : GameObject(guid, "", parent) {}

    DebugObject::~DebugObject() {}
    
    void DebugObject::update(){}
    void DebugObject::setup()
    {
        this->transform.scale.set(0.1f, 0.1f, 0.1f);
        this->transform.angularVelocity = 0.2f;
        this->transform.orientation.x = 1.0f;
    }
    void DebugObject::draw()
    {
        glTranslatef(this->transform.position.x, this->transform.position.y, this->transform.position.z);
        glRotatef(this->transform.angle, this->transform.orientation.x, this->transform.orientation.y, this->transform.orientation.z);
        glScalef(this->transform.scale.x, this->transform.scale.y, this->transform.scale.z);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, DebugObject::material);
        glutSolidTeapot(1.0f);
    }

}