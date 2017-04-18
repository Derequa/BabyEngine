/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EventListener.h
 * Author: dsbatts
 *
 * Created on April 16, 2017, 5:29 PM
 */

#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "Event.h"

namespace baby {
    
    class EventListener {
    
    public:
        ~EventListener();
        void handleEvent(Event& e);
        
    protected:
        EventListener();

    };
}
#endif /* EVENTLISTENER_H */

