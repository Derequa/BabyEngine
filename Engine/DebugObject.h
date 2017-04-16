/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DebugObject.h
 * Author: dsbatts
 *
 * Created on April 16, 2017, 2:19 AM
 */
#pragma once
//#ifndef DEBUGOBJECT_H
//#define DEBUGOBJECT_H

#define DEBUGOBJ_TYPE "DebugObject"

#include "GameObject.h"
#include <GL/freeglut.h>

namespace baby {
    class DebugObject : public GameObject {
    public:
        static const std::string debugobject_type;
        static const float material[];
        
        DebugObject(long guid);
        DebugObject(long guid, EngineComponent* parent);
        ~DebugObject();
        
        void update();
        void setup();
        void draw();
        
    private:

    };
}
//#endif /* DEBUGOBJECT_H */

