/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EngineComponent.h
 * Author: dsbatts
 *
 * Created on April 15, 2017, 7:13 AM
 */

#ifndef ENGINECOMPONENT_H
#define ENGINECOMPONENT_H

#include "EngineObject.h"
#include "HashSet.h"

class EngineComponent : public EngineObject {
public:
    virtual ~EngineComponent()=0;
    virtual void update()=0;
    virtual void setup()=0;
    EngineComponent* getParent();
    const HashSet<EngineComponent> getChildren();
    EngineComponent* getFirstChildOfType(int typeID);
    HashSet<EngineComponent>* getAllChildrenOfType(int typeID);
    
protected:
    EngineComponent(Engine* instance, long guid, int typeID);
    EngineComponent(ObjectInit& init);
    EngineComponent(Engine* instance, long guid, int typeID, EngineComponent& parent);
    EngineComponent(ObjectInit& init, EngineComponent& parent);
    
private:
    HashSet<EngineComponent> children;
};

#endif /* ENGINECOMPONENT_H */

