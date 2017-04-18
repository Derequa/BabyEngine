/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.h
 * Author: dsbatts
 *
 * Created on April 16, 2017, 5:21 PM
 */

#ifndef EVENT_H
#define EVENT_H

#include <functional>

namespace baby {
    class Event {
    public:
        long eventType;
        long triggeredByGUID;
        ~Event();
    protected:
        Event(long triggeredGUID, long eventType);
    };
}

namespace std
{
    template<> struct hash<baby::Event>
    {
        std::size_t operator()(baby::Event const& e) const
        {
            std::hash<long> hasher;
            std::size_t res = -1;
            res = 37 * res + hasher(e.eventType);
            res = 37 * res + hasher(e.triggeredByGUID);
            return res;
        }
    };
}
#endif /* EVENT_H */

