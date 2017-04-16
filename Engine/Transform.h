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
#pragma once
//#ifndef TRANSFORM_H
//#define TRANSFORM_H

#define TRANSFORM_TYPE "Transform"

#include "EngineComponent.h"
#include "Vector.h"
#include <functional>

namespace baby {
    class Transform : public EngineComponent {
        
    public:
        Vector position;
        Vector velocity;
        Vector acceleration;
        Vector scale;
        Vector orientation;
        float angle;
        float angularVelocity;
        float angularAcceleration;
        static const std::string transform_id;
        
        Transform(long guid);
        Transform(long guid, EngineComponent* parent);
        ~Transform();
        
        void update();
        void setup();
        
        //std::size_t operator()(const Transform& v) const;
        bool operator==(const Transform& t) const;
        bool operator!=(const Transform& t) const;
        Transform& operator=(const Transform& t);
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
            res = 37 * res + vecHasher(t.scale);
            res = 37 * res + vecHasher(t.orientation);
            res = 37 * res + fHasher(t.angle);
            res = 37 * res + fHasher(t.angularVelocity);
            res = 37 * res + fHasher(t.angularAcceleration);
            return res;
        }
    };
}
//#endif /* TRANSFORM_H */

