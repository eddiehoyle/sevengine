//
// Created by Eddie Hoyle on 5/10/16.
//

#ifndef SEV_QUADRENDERER_HH
#define SEV_QUADRENDERER_HH


#include "AbstractRender.hh"

class QuadRender : public AbstractRender {

public:
    QuadRender() : AbstractRender() {}
    virtual ~QuadRender() {}

public:
    virtual void begin() {};
    virtual void render() {};
    virtual void end() {};

private:
    virtual void flush() {};

};


#endif //SEV_QUADRENDERER_HH
