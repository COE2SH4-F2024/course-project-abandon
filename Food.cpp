#include "Food.h"
#include <cstdlib>
#include <ctime>

Food::Food(){
    foodPos.pos = new Pos{-1,-1};
    foodPos.symbol = 'x';
}

Food::~Food(){
        delete foodPos.pos;
}

void Food::generateFood(const objPos& obstacle, int boardSizeX, int boardSizeY) {
    srand(static_cast<unsigned>(time(nullptr)));
    bool valid = false;

    while (!valid) {
        int x = rand() % (boardSizeX-2);
        int y = rand() % (boardSizeY-2);
        x++;
        y++;

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