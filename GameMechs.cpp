#include "GameMechs.h"

//Default constructor
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

//Constructor
GameMechs::GameMechs(int boardX, int boardY):input(0),exitFlag(false),loseFlag(false),score(0),boardSizeX(boardX),boardSizeY(boardY)
{
food = new Food();
}

// do you need a destructor?
//Destructor
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
    
//Returns the most recent input character
char GameMechs::getInput() const
{
    return input;
}
//Returns current score
int GameMechs::getScore() const
{
    return score;
}
//Increments score by 1
void GameMechs::incrementScore()
{
    score++;
}
//Returns width
int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}
//Returns height
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
//Clear current input
void GameMechs::clearInput()
{
    input = 0;
}

//More methods should be added here
//Generate a new random position
void GameMechs::generateFood(const objPos& playerPos) {
    food->generateFood(playerPos, boardSizeX, boardSizeY);
}
objPos GameMechs::getFoodPos() const {
    return food->getFoodPos();
}
