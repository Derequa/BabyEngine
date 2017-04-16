/* 
 * File:   EngineObject.h
 * Author: dsbatts
 *
 * Created on April 15, 2017, 6:30 AM
 */
#pragma once
//#ifndef ENGINEOBJECT_H
//#define ENGINEOBJECT_H

#include <cstddef>
#include <functional>
#include <string>

namespace baby {
    
    class EngineObject {
    public:
        long guid;
        std::string typeID;

        virtual ~EngineObject();
        virtual void update()=0;
        virtual void setup()=0;

        bool operator==(const EngineObject & other ) const;

    protected:
        EngineObject(long guid, std::string typeID);


    };
}

namespace std
{
    template<> struct hash<baby::EngineObject>
    {
        std::size_t operator()(baby::EngineObject const& o) const
        {
            std::hash<long> hasher;
            std:size_t res = hasher(o.guid);
            return res;
        }
    };
}


//#endif /* ENGINEOBJECT_H */

