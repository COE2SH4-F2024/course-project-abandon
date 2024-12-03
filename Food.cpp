#include "Food.h"
#include <cstdlib>
#include <ctime>

Food::Food(){
    foodPos = new objPos{-1,-1,'x'};
    
}

Food::~Food(){
        delete foodPos;
        
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
            foodPos->pos->x = x;
            foodPos->pos->y = y;
            valid = true;
        }
    }
}

objPos Food::getFoodPos() const {
    return *foodPos;
}