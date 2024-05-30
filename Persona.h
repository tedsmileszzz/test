#ifndef PERSONA_H
#define PERSONA_H

#include "Spot.h"

class Persona : public Spot {
    private:
    public:
    Persona(int x, int y) : Spot(std::get<0>(location),std::get<1>(location),'P') {}

    void shift(int dx, int dy) {
        std::get<0>(location) += dx;
        std::get<1>(location) += dy;
    }
};

#endif