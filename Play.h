#ifndef PLAY_H
#define PLAY_H

#include "Spot.h"
#include "Assists.h"
#include "Snare.h"
#include "Persona.h"

#include <vector>
#include <iostream>

class Play {
    private:
    std::vector<Spot*> matrix;
    public:
    Play() {}

    std::vector<Spot*>& getMatrix() { return matrix;}

    //Init Game with objects and random locations
    void initPlay(int numPersonas, int numSnares, int matrixWidth, int matrixHeight) {
        for (int i = 0; i < numPersonas; i++) {
            auto location = Assists::createRandomLoc(matrixWidth,matrixHeight);

            matrix.push_back(new Spot(std::get<0>(location),std::get<1>(location),'X'));

        }

        for (int i = 0; i < numSnares; i++){
            auto location = Assists::createRandomLoc(matrixWidth,matrixHeight);
            matrix.push_back(new Snare(std::get<0>(location),std::get<1>(location)));
        }
    }

    void playCycle(int maxCycles, double snareTriggerDistance) {
        for (int i = 0; i < maxCycles; i++) {
            for (Spot* spot : matrix) {
                if (Persona* persona = static_cast<Persona*>(spot)) {
                    persona->shift(1, 0);
                    for (Spot* otherSpot : matrix) {
                        if (Snare* snare = static_cast<Snare*>(otherSpot)) {
                            double distance = Assists::evaluateDistance(persona->getLoc(), snare->getLoc());
                            if (distance <= snareTriggerDistance)
                                snare->implement(*persona);
                        }
                    }
                    std::tuple<int, int> loc = persona->getLoc();
                    if (std::get<0>(loc) >= 10) {
                        std::cout << "Persona Won" << std::endl;
                        return;
                    }
                }


            }
        }
    }
        



};

#endif

