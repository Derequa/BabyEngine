/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Engine.h
 * Author: dsbatts
 *
 * Created on April 15, 2017, 6:37 AM
 */

#ifndef ENGINE_H
#define ENGINE_H

#include "HashMap.h"
#include "EngineObject.h"
#include <string>
#include <stdlib.h>
#include <GL/freeglut.h>

namespace baby
{
    class EngineObject;

    class Engine
    {
    public:
        ~Engine();
        static void run(int thing);
        static void setup(int argc, char** argv);
        static void draw();
        void removeObject(long guid);
        static EngineObject* getObject(long guid);
        static void addObject(long guid, EngineObject* object);
        static long getNewGUID();
        static float getDeltaT();

    protected:
        Engine();
    private:
        static HashMap<long, EngineObject> objects;
        static Engine* instance;
        static long guidCounter;
        static float deltaT;
        static float lastTime;

    };
}


#endif /* ENGINE_H */

