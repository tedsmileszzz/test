#ifndef INFLUENCE_H
#define INFLUENCE_H

#include "Spot.h"

class Influence {
    private:
    public:
    virtual void implement(Spot& spot) = 0;
};

#endif