#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"

class Food {
private:
// Pointer to store the position and symbol 
    objPos * foodPos; 
public:
    Food();//Constructor
    ~Food(); //Destructor
    // Generates a random position, avoiding obstacle's position
    void generateFood(const objPos& obstacle, int boardSizeX, int boardSizeY);
    // Returns the position of the food
    objPos getFoodPos() const;
};
#endif
