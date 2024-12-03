#include "Food.h"
#include <cstdlib>
#include <ctime>
// Constructor
Food::Food(){
    foodPos = new objPos{-1,-1,'x'};
    //initializes food's position to an invalid position (-1, -1) with default symbol 'x'
}
// Destructor
Food::~Food(){
        delete foodPos;
        
}
// Generate a random food position and avoiding the player position
void Food::generateFood(const objPos& obstacle, int boardSizeX, int boardSizeY) {
    srand(static_cast<unsigned>(time(nullptr)));
    bool valid = false;
    //Keep generating until find a valid place
    while (!valid) {
        //Random x,y coordinates within board
        int x = rand() % (boardSizeX-2);
        int y = rand() % (boardSizeY-2);
        x++;
        y++;
        // Check that the food position doesn't overlap
        if (x != obstacle.pos->x || y != obstacle.pos->y) {
            foodPos->pos->x = x;
            foodPos->pos->y = y;
            valid = true;
        }
    }
}
// Return the current food position
objPos Food::getFoodPos() const {
    return *foodPos;
}