#include "EngineObject.h"
#include "Engine.h"

namespace baby {
    
    EngineObject::EngineObject(long guid, std::string typeID)
    {
        this->guid = guid;
        this->typeID = typeID;
        Engine::addObject(this);
    }

    EngineObject::~EngineObject() { Engine::removeObject(this->guid); }

    bool EngineObject::operator==(const EngineObject & other ) const
    {
        return (this->guid == other.guid);
    }

}