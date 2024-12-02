#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"

class Food {
private:
    objPos * foodPos; 

public:
    Food();
    ~Food(); 

    void generateFood(const objPos& obstacle, int boardSizeX, int boardSizeY);
    objPos getFoodPos() const;
};
#endif
