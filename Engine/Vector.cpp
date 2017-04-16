/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector.cpp
 * Author: dsbatts
 * 
 * Created on April 15, 2017, 9:12 PM
 */

#include "Vector.h"

namespace baby {
    Vector::Vector() : Vector(0.0f, 0.0f, 0.0f){}
    Vector::Vector(const Vector& orig) : Vector(orig.x, orig.y, orig.z){}
    Vector::Vector(float x, float y, float z) { this->set(x, y, z); }
    Vector::~Vector(){}
    
    float Vector::mag() { return (float) sqrt((x * x) + (y * y) + (z * z)); }
    
    void Vector::normalize()
    {
        float m = this->mag();
        this->div(m);
    }
    
     void Vector::set(float x, float y, float z)
     {
        this->x = x;
        this->y = y;
        this->z = z;
     }
    
    void Vector::mult(const float num)
    {
        this->x *= num;
        this->y *= num;
        this->z *= num;
    }
    
    void Vector::div(const float num)
    {
        this->x /= num;
        this->y /= num;
        this->z /= num;
    }
    
    void Vector::add(const Vector& v)
    {
        this->x += v.x;
        this->y += v.y;
        this->z += v.z;
    }
    
    void Vector::sub(const Vector& v)
    {
        this->x -= v.x;
        this->y -= v.y;
        this->z -= v.z;
    }
    
    float Vector::dot(const Vector& v) { return (this->x * v.x) + (this->y * v.y) + (this->z * v.z); }
    
    Vector* Vector::cross(Vector& v)
    {
        float xCross = (this->y * v.z) - (this->z * v.y);
        float yCross = (this->x * v.z) - (this->z * v.x);
        float zCross = (this->x * v.y) - (this->y * v.x);
        return new Vector(xCross, yCross, zCross);
    }

    float Vector::dot(Vector& v0, Vector& v1) { return v0.dot(v1); }
    Vector* Vector::cross(Vector& v0, Vector& v1) { return v0.cross(v1); }
    Vector* Vector::add(const Vector& v0, const Vector& v1) { return new Vector(v0.x + v1.y, v0.y + v1.z, v0.z + v1.z); }
    Vector* Vector::sub(const Vector& v0, const Vector& v1) { return new Vector(v0.x - v1.y, v0.y - v1.z, v0.z - v1.z); }
    Vector* Vector::mult(const Vector& v, const float num) { return new Vector(v.x * num, v.y * num, v.z * num); }
    Vector* Vector::div(const Vector& v, const float num) { return new Vector(v.x / num, v.y / num, v.z / num); }

    /*
    std::size_t Vector::operator()(const Vector& v) const
    {
        std::hash<float> hasher;
        auto res = -1;
        res = 37 * res + hasher(x);
        res = 37 * res + hasher(y);
        res = 37 * res + hasher(z);
        return res;
    }
    */
    
    bool Vector::operator==(const Vector& v) const { return (this->x == v.x) && (this->y == v.y) && (this->z == v.z); }
    bool Vector::operator!=(const Vector& v) const { return !(*this == v); }
    
    Vector& Vector::operator=(const Vector& v)
    {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        return *this;
    }
    
    Vector& Vector::operator+(const Vector& v) const { return *(Vector::add(*this, v)); }
    Vector& Vector::operator-(const Vector& v) const { return *(Vector::sub(*this, v)); }
    Vector& Vector::operator*(const float& num) const { return *(Vector::mult(*this, num)); }
    Vector& Vector::operator/(const float& num) const { return *(Vector::div(*this, num)); }
    
    Vector& Vector::operator+=(const Vector& v)
    {
        this->add(v);
        return *this;
    }
    
    Vector& Vector::operator-=(const Vector& v)
    {
        this->sub(v);
        return *this;
    }
    
    Vector& Vector::operator*=(const float& num)
    {
        this->mult(num);
        return *this;
    }
    
    Vector& Vector::operator/=(const float& num)
    {
        this->div(num);
        return *this;
    }
}

