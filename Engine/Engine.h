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

namespace baby
{
    class EngineObject;

    class Engine
    {
    public:
        ~Engine();
        static const Engine* getInstance();
        void run();
        void setup();
        void removeObject(long guid);
        EngineObject* getObject(long guid);
        void addObject(long guid, EngineObject* object);
        long getNewGUID();
        int getTypeID(std::string className);

    protected:
        Engine();
    private:
        HashMap<long, EngineObject> objects;
        HashMap<std::string, int> idMap;
        static Engine* instance;
        long guidCounter;
        int idCounter;

    };
}


#endif /* ENGINE_H */

