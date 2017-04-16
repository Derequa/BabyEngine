/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameObject.cpp
 * Author: dsbatts
 * 
 * Created on April 15, 2017, 9:11 PM
 */

#include "GameObject.h"

namespace baby {
    GameObject::GameObject(Engine* instance, long guid, std::string typeID) : GameObject(instance, guid, typeID, NULL) {}
    GameObject::GameObject(ObjectInit& init) : GameObject(init.engine, init.guid, init.typeID, NULL) {}
    GameObject::GameObject(ObjectInit& init, EngineComponent* parent) : GameObject(init.engine, init.guid, init.typeID, parent) {}
    GameObject::GameObject(Engine* instance, long guid, std::string typeID, EngineComponent* parent) : EngineComponent(instance, guid, typeID, parent), transform(instance, instance->getNewGUID(), this)
    {
        this->attachedToParent = false;
    }
}
