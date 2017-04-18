/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.cpp
 * Author: dsbatts
 * 
 * Created on April 16, 2017, 5:21 PM
 */

#include "Event.h"

namespace baby {
    
    Event::Event(long triggeredGUID, long eventType)
    {
        this->eventType = eventType;
        this->triggeredByGUID = triggeredGUID;
    }
    Event::~Event(){}

}