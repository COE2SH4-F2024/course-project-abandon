#include "GameMechs.h"


GameMechs::GameMechs()  
{
food = new Food();
 input = 0;
 exitFlag = false;
 loseFlag = false;
 score = 0;
 boardSizeX = 30;
 boardSizeY = 15;
}


GameMechs::GameMechs(int boardX, int boardY):input(0),exitFlag(false),loseFlag(false),score(0),boardSizeX(boardX),boardSizeY(boardY)
{
food = new Food();
}



// do you need a destructor?
GameMechs::~GameMechs()
{
delete food;
}

bool GameMechs::getExitFlagStatus() const
{
return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
 return loseFlag;
}
    

char GameMechs::getInput() const
{
return input;
}

int GameMechs::getScore() const
{
return score;
}

void GameMechs::incrementScore()
{
score++;
}

int GameMechs::getBoardSizeX() const
{
return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
return boardSizeY;
}


void GameMechs::setExitTrue()
{
exitFlag = true;
}

void GameMechs::setLoseFlag()
{
loseFlag = true; 
}

void GameMechs::setInput(char this_input)
{
 input = this_input;

}

void GameMechs::clearInput()
{
input = 0;
}

// More methods should be added here
void GameMechs::generateFood(const objPos& playerPos) {
    food->generateFood(playerPos, boardSizeX, boardSizeY);
}
objPos GameMechs::getFoodPos() const {
    return food->getFoodPos();
}