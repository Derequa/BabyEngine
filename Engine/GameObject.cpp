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
#include "Engine.h"

namespace baby {
    GameObject::GameObject(long guid, std::string typeID) : GameObject(guid, typeID, NULL) {}
    GameObject::GameObject(long guid, std::string typeID, EngineComponent* parent) : EngineComponent(guid, typeID, parent), transform(Engine::getNewGUID(), this)
    {
        
        this->attachedToParent = false;
    }
    
    GameObject::~GameObject(){}
}
