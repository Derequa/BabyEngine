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

namespace baby {
    
    typedef std::vector<EngineComponent*> EngineComponentList;
    EngineComponent::EngineComponent(long guid, std::string typeID) : EngineComponent(guid, typeID, NULL) {}
    EngineComponent::EngineComponent(long guid, std::string typeID, EngineComponent* parent) : EngineObject(guid, typeID) { this->parent = parent; }
    
    EngineComponent::~EngineComponent()
    {
        EngineComponentList::iterator it;
        for (it = this->children.begin() ; it < this->children.end() ; it++) {
            delete *it;
        }
    }
    
    EngineComponent* EngineComponent::getParent()
    {
        return this->parent;
    }

    EngineComponent* EngineComponent::getComponent(std::string typeID)
    {
        EngineComponentList::iterator it;
        for (it = this->children.begin() ; it < this->children.end() ; it++) {
            if ((*it)->typeID == typeID)
                return *it;
        }
        return NULL;
    }

    const EngineComponentList& EngineComponent::getComponents()
    {
        return this->children;
    }

    EngineComponentList* EngineComponent::getComponents(std::string typeID)
    {
        EngineComponentList* ret = new EngineComponentList();
        EngineComponentList::iterator it;
        for (it = this->children.begin() ; it < this->children.end() ; it++) {
            if ((*it)->typeID == typeID)
                ret->push_back(*it);
        }
        return ret;
    }

    EngineComponent* EngineComponent::getComponentInChildren(std::string typeID)
    {
        EngineComponent* res = this->getComponent(typeID);
        if (res != NULL)
            return res;
        EngineComponentList::iterator it;
        for (it = this->children.begin() ; it < this->children.end() ; it++) {
            if ((*it)->typeID == typeID)
                return (*it);
        }
    }

    EngineComponentList* EngineComponent::getComponentsInChildren(std::string typeID)
    {
        EngineComponentList* myList = this->getComponents(typeID);
        EngineComponentList::iterator it;
        for (it = this->children.begin() ; it < this->children.end() ; it++) {
            EngineComponentList* childList = (*it)->getComponentsInChildren(typeID);
            myList->insert(myList->end(), childList->begin(), childList->end());
            delete childList;
        }
        return myList;
    }

    EngineComponent* EngineComponent::getComponentInParent(std::string typeID)
    {
        throw "DONT DO THIS";
        return NULL;
    }

    EngineComponentList* getComponentsInParent(std::string typeID)
    {
        throw "DONT DO THIS";
        return NULL;
    }

    void EngineComponent::addComponent(EngineComponent* e)
    {
        if (e->parent != NULL) {
            e->parent->removeComponent(this);
        }
        e->parent = this;
        this->children.push_back(e);
    }

    EngineComponent* EngineComponent::removeComponent(EngineComponent* e)
    {
        EngineComponentList::iterator it;
        for (it = this->children.begin() ; it < this->children.end() ; it++) {
            if ((**it) == *e){
                EngineComponent* val = *it;
                this->children.erase(it);
                return val;
            }
        }
        return NULL;
    }

    void EngineComponent::updateAll()
    {
        EngineComponentList::iterator it;
        for (it = this->children.begin() ; it < this->children.end() ; it++) {
            (*it)->update();
        }
    }
}
