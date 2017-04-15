#include "Engine.h"

Engine::Engine()
{
    this->instance = *this;
}
Engine::~Engine(){}
const Engine& Engine::getInstance(){}
void Engine::run(){}
void Engine::setup(){}

