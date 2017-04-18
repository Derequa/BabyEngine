/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EventManager.cpp
 * Author: dsbatts
 * 
 * Created on April 16, 2017, 5:20 PM
 */

#include "EventManager.h"
#include <iterator>

namespace baby {
    
    EventManager::EventManager() {}

    EventManager::~EventManager() {}
    
    void EventManager::hanldeEvents()
    {
        std::vector<Event>::iterator it;
        for (it = this->events.begin() ; it < this->events.end() ; it++) {
            std::vector<EventListener> *typedEvents = this->listeners.get(&(it->eventType));
            std::vector<EventListener>::iterator j;
            for (j = typedEvents->begin() ; j < typedEvents->end() ; j++) {
                j->handleEvent(*it);
            }
        }
        this->clearEvents();
    }
    void EventManager::addEvent(Event& e) { this->events.push_back(e); }
    void EventManager::addListenerFor(long eventType, EventListener& listener)
    {
        long* id = new long(eventType);
        if (this->listeners.containsKey(id)) {
            std::vector<EventListener> *listenerList = this->listeners.get(id);
            listenerList->push_back(listener);
        }
        else {
            std::vector<EventListener> *listenerList = new std::vector<EventListener>();
            this->listeners.put(id, listenerList);
            listenerList->push_back(listener);
        }
    }
    void EventManager::removeListenerFor(long eventType, EventListener& listener){}
    void EventManager::clearEvents(){}
    void EventManager::clearListenersFor(long eventType){}
    void EventManager::clearAllListeners(){}

}