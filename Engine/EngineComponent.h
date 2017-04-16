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
namespace baby {
    
    class EngineComponent;
    
    typedef std::vector<EngineComponent*> EngineComponentList;


    class EngineComponent : public EngineObject {

    public:

        ~EngineComponent();
        virtual void update()=0;
        virtual void setup()=0;
        EngineComponent* getParent();
        EngineComponent* getComponent(int typeID);
        const EngineComponentList& getComponents();
        EngineComponentList* getComponents(int typeID);
        EngineComponent* getComponentInChildren(int typeID);
        EngineComponentList* getComponentsInChildren(int typeID);
        EngineComponent* getComponentInParent(int typeID);
        EngineComponentList* getComponentsInParent(int typeID);
        void addComponent(EngineComponent* e);
        EngineComponent* removeComponent(EngineComponent* e);
        void updateAll();

    protected:
        EngineComponent(Engine* instance, long guid, int typeID);
        EngineComponent(ObjectInit& init);
        EngineComponent(Engine* instance, long guid, int typeID, EngineComponent* parent);
        EngineComponent(ObjectInit& init, EngineComponent* parent);

    private:
        std::vector<EngineComponent*> children;
        EngineComponent* parent;
    };
}
#endif /* ENGINECOMPONENT_H */

