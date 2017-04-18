/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EventManager.h
 * Author: dsbatts
 *
 * Created on April 16, 2017, 5:20 PM
 */

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Event.h"
#include "EventListener.h"
#include "HashMap.h"
#include <vector>

namespace baby {
    
    class EventManager {
    public:
        EventManager();
        ~EventManager();

        void hanldeEvents();
        void addEvent(Event& e);
        void addListenerFor(long eventType, EventListener& listener);
        void removeListenerFor(long eventType, EventListener& listener);
        void clearEvents();
        void clearListenersFor(long eventType);
        void clearAllListeners();
        
    private:
        HashMap<long, std::vector<EventListener>> listeners;
        std::vector<Event> events;
    };
}
#endif /* EVENTMANAGER_H */

