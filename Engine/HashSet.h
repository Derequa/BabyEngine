/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashSet.h
 * Author: dsbatts
 *
 * Created on April 15, 2017, 6:10 AM
 */

#ifndef HASHSET_H
#define HASHSET_H

#include "HashMap.h"

template <typename E> class HashSet
{
public:
    HashSet(){ this->ref = 0;}
    ~HashSet(){}
    
    int size() { return this->map.getSize(); }
    void add(E& e) {this->map.put(e, e); }
    bool contains(E& e) { return this->map.containsKey(e); }
    E remove(E& e) { return this->map.remove(e); }
    
private:
    HashMap<E, E> map;
    int ref;
};


#endif /* HASHSET_H */

