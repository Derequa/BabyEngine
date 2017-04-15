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

class Engine
{
public:
    ~Engine();
    static const Engine& getInstance();
    void run();
    void setup();
    
    
    
protected:
    Engine();
    static Engine instance;
};


#endif /* ENGINE_H */

