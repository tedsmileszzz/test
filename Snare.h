#ifndef SNARE_H
#define SNARE_H

#include "Spot.h"
#include "Influence.h"

class Snare : public Spot, Influence {
    protected:
    bool operative;
    public:
    Snare(int x, int y) : Spot(std::get<0>(location),std::get<1>(location), 'S') {}

    bool isOperative() { return operative;}

    void implement(Spot& spot) override {
        category = 'S';
        operative = false;
    }

};

#endif