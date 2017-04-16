/* 
 * File:   EngineComponent.h
 * Author: dsbatts
 *
 * Created on April 15, 2017, 7:13 AM
 */

#ifndef ENGINECOMPONENT_H
#define ENGINECOMPONENT_H

#include "EngineObject.h"
#include <vector>
#include <iterator>
#include <string>

namespace baby {
    
    class EngineComponent;
    
    typedef std::vector<EngineComponent*> EngineComponentList;


    class EngineComponent : public EngineObject {

    public:

        ~EngineComponent();
        virtual void update()=0;
        virtual void setup()=0;
        EngineComponent* getParent();
        EngineComponent* getComponent(std::string typeID);
        const EngineComponentList& getComponents();
        EngineComponentList* getComponents(std::string typeID);
        EngineComponent* getComponentInChildren(std::string typeID);
        EngineComponentList* getComponentsInChildren(std::string typeID);
        EngineComponent* getComponentInParent(std::string typeID);
        EngineComponentList* getComponentsInParent(std::string typeID);
        void addComponent(EngineComponent* e);
        EngineComponent* removeComponent(EngineComponent* e);
        void updateAll();

    protected:
        EngineComponent(Engine* instance, long guid, std::string typeID);
        EngineComponent(ObjectInit& init);
        EngineComponent(Engine* instance, long guid, std::string typeID, EngineComponent* parent);
        EngineComponent(ObjectInit& init, EngineComponent* parent);
        std::vector<EngineComponent*> children;
        EngineComponent* parent;
    };
}
#endif /* ENGINECOMPONENT_H */

