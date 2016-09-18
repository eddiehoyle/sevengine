//
// Created by Eddie Hoyle on 17/09/16.
//

#ifndef SEV_OBSERVERCONTEXT_HH
#define SEV_OBSERVERCONTEXT_HH

//#include "../Entity.hh"
#include <vector>

#include "../Entity.hh"

typedef std::vector< Entity* > Entities;

class ObserverContext {

public:
    ObserverContext() {}
    virtual ~ObserverContext() {}

    void addEntity( Entity* entity )
    {
        m_entities.push_back( entity );
    };

    Entities getEntities() const
    {
        return m_entities;
    };

private:
    Entities m_entities;
};


#endif //SEV_OBSERVERCONTEXT_HH
