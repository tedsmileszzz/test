#ifndef ASSISTS_H
#define ASSISTS_H

#include <tuple>
#include <random>
#include <cmath>

class Assists {
    private:
    public:
    static std::tuple<int,int> createRandomLoc(int matrixWidth, int matrixHeight) {
        //random num generator
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> disX(0,matrixWidth - 1);
        std::uniform_int_distribution<> disY(0,matrixHeight - 1);

        int x = disX(gen);
        int y = disY(gen);

        return std::make_tuple(x,y);
    }

    static double evaluateDistance(std::tuple<int, int> loc1, std::tuple<int, int> loc2) {
        int x1, x2, y1, y2;

        std::tie(x1,y1) = loc1;
        std::tie(x2,y2) = loc2;

        int dx = x2 - x1;
        int dy = y2 - y1;

        return sqrt(dx * dx + dy * dy);
    }
};

#endif