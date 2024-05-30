#include "Spot.h"
#include "Influence.h"
#include "Assists.h"
#include "Persona.h"
#include "Snare.h"
#include "Play.h"

#include <iostream>

int main(){

    int matrixWidth = 100;
    int matrixHeight = 100;

    Spot mySpot(0,0,'X');

    std::cout << "Current Location: x: " << std::get<0>(mySpot.getLoc()) << ", y: " << std::get<1>(mySpot.getLoc()) << std::endl;
    std::cout << "Current Category: " << mySpot.getCategory() << std::endl;

    auto randomloc = Assists::createRandomLoc(matrixWidth,matrixHeight);
    mySpot.setLoc(randomloc);
    mySpot.setCategory('Y');

    std::cout << "Updated Location: x: " << std::get<0>(mySpot.getLoc()) << ", y: " << std::get<1>(mySpot.getLoc()) << std::endl;
    std::cout << "Updated Category: " << mySpot.getCategory() << std::endl;

    auto randomloc2 = Assists::createRandomLoc(matrixWidth,matrixHeight);
    mySpot.setLoc(randomloc2);
    std::cout << "Updated Location: x: " << std::get<0>(mySpot.getLoc()) << ", y: " << std::get<1>(mySpot.getLoc()) << std::endl;
    std::cout << "Euclidean distance from previous location to current location: " << Assists::evaluateDistance(randomloc,randomloc2) << std::endl;


    Play game;




    

    


}