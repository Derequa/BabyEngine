#include "EngineObject.h"

namespace baby {
    
    EngineObject::EngineObject(Engine* instance, long guid, int typeID)
    {
        this->engine = instance;
        this->guid;
        this->typeID;
    }

    EngineObject::EngineObject(ObjectInit& init) : EngineObject(init.engine, init.guid, init.typeID) {}

    EngineObject::~EngineObject() { this->engine->removeObject(this->guid); }

    size_t EngineObject::operator()( const EngineObject & key ) const
    {
        std::hash<long> hasher;
        auto hash = hasher(key.guid);
        return hash;
    }

    bool EngineObject::operator==(const EngineObject & other ) const
    {
        return (this->guid == other.guid);
    }

}