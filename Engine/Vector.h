/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector.h
 * Author: dsbatts
 *
 * Created on April 15, 2017, 9:12 PM
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <cstddef>
#include <functional>

namespace baby {
    class Vector {
    public:
        float x, y, z;
        Vector();
        Vector(float x, float y, float z);
        Vector(const Vector& orig);
        ~Vector();

        float mag();
        void normalize();
        void mult(const float num);
        void div(const float num);
        void add(const Vector& v);
        void sub(const Vector& v);
        float dot(const Vector& v);
        Vector* cross(Vector& v);

        static float dot(Vector& v0, Vector& v1);
        static Vector* cross(Vector& v0, Vector& v1);
        static Vector* add(const Vector& v0, const Vector& v1);
        static Vector* sub(const Vector& v0, const Vector& v1);
        static Vector* mult(const Vector& v, const float num);
        static Vector* div(const Vector& v, const float num);

        //std::size_t operator()(const Vector& v) const;
        bool operator==(const Vector& v) const;
        bool operator!=(const Vector& v) const;
        Vector& operator=(const Vector& v);
        Vector& operator+(const Vector& v) const;
        Vector& operator-(const Vector& v) const;
        Vector& operator*(const float& num) const;
        Vector& operator/(const float& num) const;
        Vector& operator+=(const Vector& v);
        Vector& operator-=(const Vector& v);
        Vector& operator*=(const float& num);
        Vector& operator/=(const float& num);
    };
}


namespace std
{
    template<> struct hash<baby::Vector>
    {
        std::size_t operator()(baby::Vector const& v) const
        {
            std::hash<float> hasher;
            std::size_t res = -1;
            res = 37 * res + hasher(v.x);
            res = 37 * res + hasher(v.y);
            res = 37 * res + hasher(v.z);
            return res;
        }
    };
}

#endif /* VECTOR_H */

