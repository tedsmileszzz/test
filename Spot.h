#ifndef SPOT_H
#define SPOT_H

#include <tuple>

class Spot {
    protected:
    std::tuple<int, int> location; //spots location
    char category; //type of entity
    public:
    Spot(int x, int y, char category) : location(x,y), category(category) {}

    //getters
    std::tuple<int,int> getLoc() { return location; }
    char getCategory() {return category; }

    //setters
    void setLoc(std::tuple<int,int> newLocation) {location = newLocation;}
    void setCategory(char newCategory) {category = newCategory;}

};

#endif
