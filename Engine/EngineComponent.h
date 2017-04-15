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
    EngineComponent* getComponent(int typeID);
    const HashSet<EngineComponent>& getComponents();
    HashSet<EngineComponent>* getComponents(int typeID);
    EngineComponent* getComponentInChildren(int typeID);
    HashSet<EngineComponent>* getComponentsInChildren(int typeID);
    EngineComponent* getComponentInParent(int typeID);
    HashSet<EngineComponent>* getComponentsInParent(int typeID);
    void addComponent(EngineComponent* e);
    EngineComponent* removeComponent(EngineComponent* e);
    void updateAll();
    
protected:
    EngineComponent(Engine* instance, long guid, int typeID);
    EngineComponent(ObjectInit& init);
    EngineComponent(Engine* instance, long guid, int typeID, EngineComponent* parent);
    EngineComponent(ObjectInit& init, EngineComponent* parent);
    
private:
    HashSet<EngineComponent> children;
    EngineComponent* parent;
};

#endif /* ENGINECOMPONENT_H */

