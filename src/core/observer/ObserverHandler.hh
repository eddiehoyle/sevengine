//
// Created by Eddie Hoyle on 17/09/16.
//

#ifndef SEV_OBSERVERHANDLER_HH
#define SEV_OBSERVERHANDLER_HH

#include <vector>
#include "ObserverContext.hh"

class ObserverHandler {

public:
    ObserverHandler() {}
    ~ObserverHandler() {}

    void addContext( ObserverContext* context );
    void setActiveContext( ObserverContext* context );
    ObserverContext* getActiveContext() const;

private:
    std::vector< ObserverContext* > m_contexts;
    ObserverContext* m_active;

};


#endif //SEV_OBSERVERHANDLER_HH
