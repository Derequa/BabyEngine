/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EngineComponent.cpp
 * Author: dsbatts
 * 
 * Created on April 15, 2017, 7:13 AM
 */

#include "EngineComponent.h"

EngineComponent::EngineComponent(Engine* instance, long guid, int typeID) : EngineObject(instance, guid, typeID) {}
EngineComponent::EngineComponent(ObjectInit& init) : EngineComponent(init.engine, init.guid, init.typeID) {}
EngineComponent::EngineComponent(Engine* instance, long guid, int typeID, EngineComponent& parent) : EngineObject(instance, guid, typeID) {}
EngineComponent::EngineComponent(ObjectInit& init, EngineComponent& parent) : EngineComponent(init.engine, init.guid, init.typeID, parent) {}
