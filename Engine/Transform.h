/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Transform.h
 * Author: dsbatts
 *
 * Created on April 15, 2017, 9:11 PM
 */

#ifndef TRANSFORM_H
#define TRANSFORM_H

#define TRANSFORM_TYPE "Transform"

#include "Engine.h"
#include "EngineComponent.h"
#include "Vector.h"
#include <functional>

namespace baby {
    class Transform : public EngineComponent {
        
    public:
        Vector position;
        Vector velocity;
        Vector acceleration;
        float orientation;
        float angularVelocity;
        float angularAcceleration;
        
        Transform(Engine* instance, long guid);
        Transform(Engine* instance, long guid, EngineComponent* parent);
        ~Transform();
        
        void update();
        void setup();
        
        //std::size_t operator()(const Transform& v) const;
        bool operator==(const Transform& v) const;
        bool operator!=(const Transform& v) const;
        Transform& operator=(const Transform& v);
    private:
        static int TRANSFORM_ID;
    };
}

namespace std
{
    template<> struct hash<baby::Transform>
    {
        std::size_t operator()(baby::Transform const& t) const
        {
            std::hash<float> fHasher;
            std::hash<baby::Vector> vecHasher;
            std::size_t res = -1;
            res = 37 * res + vecHasher(t.position);
            res = 37 * res + vecHasher(t.velocity);
            res = 37 * res + vecHasher(t.acceleration);
            res = 37 * res + fHasher(t.orientation);
            res = 37 * res + fHasher(t.angularVelocity);
            res = 37 * res + fHasher(t.angularAcceleration);
            return res;
        }
    };
}
#endif /* TRANSFORM_H */
