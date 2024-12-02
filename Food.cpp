#include "Food.h"
#include <cstdlib>
#include <ctime>

Food::Food(){
    foodPos.pos = new Pos{-1,-1};
    foodPos.symbol = '*';
}

Food::~Food(){
        delete foodPos.pos;
}

void Food::generateFood(const objPos& obstacle, int boardSizeX, int boardSizeY) {
    srand(static_cast<unsigned>(time(nullptr)));
    bool valid = false;

    while (!valid) {
        int x = rand() % boardSizeX;
        int y = rand() % boardSizeY;

        if (x != obstacle.pos->x || y != obstacle.pos->y) {
            foodPos.pos->x = x;
            foodPos.pos->y = y;
            valid = true;
        }
    }
}

objPos Food::getFoodPos() const {
    return foodPos;
}