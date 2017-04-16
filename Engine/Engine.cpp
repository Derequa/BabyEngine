#include "Engine.h"

namespace baby {

    Engine* Engine::instance = NULL;

    Engine::Engine()
    {
        this->guidCounter = 0;
        this->idCounter = 0;
    }
    Engine::~Engine(){}
    const Engine* Engine::getInstance()
    {
        if (Engine::instance == NULL) {
           Engine::instance = new Engine();
        }
        return Engine::instance;
    }
    void Engine::run(){}
    void Engine::setup(){}
    void Engine::removeObject(long guid) {}
    long Engine::getNewGUID() { return this->guidCounter++; }
    int Engine::getTypeID(std::string className)
    {
        if (this->idMap.containsKey(&className))
            return *this->idMap.get(&className);
        else {
            int* id = static_cast<int*>(malloc(sizeof(int)));
            *id = this->idCounter++;
            std::string* s = new std::string(className);
            this->idMap.put(s, id);
            return *id;
        }
    }
    EngineObject* Engine::getObject(long guid)
    {
        return NULL;
    }
    void Engine::addObject(long guid, EngineObject* object) {}

}