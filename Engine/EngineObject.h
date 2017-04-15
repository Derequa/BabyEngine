/* 
 * File:   EngineObject.h
 * Author: dsbatts
 *
 * Created on April 15, 2017, 6:30 AM
 */

#ifndef ENGINEOBJECT_H
#define ENGINEOBJECT_H

#include "Engine.h"
#include <cstddef>
#include <functional>

struct ObjectInit {
    Engine* engine;
    long guid;
    int typeID;
};

class EngineObject {
public:
    long guid;
    int typeID;
    Engine* engine;
    
    virtual ~EngineObject()=0;
    virtual void update()=0;
    virtual void setup()=0;
    
    size_t operator()( const EngineObject & key ) const;
    bool operator==(const EngineObject & other ) const;
    
protected:
    EngineObject(Engine* instance, long guid, int typeID);
    EngineObject(ObjectInit& init);
    
    
};



#endif /* ENGINEOBJECT_H */

