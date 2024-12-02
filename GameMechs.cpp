#include "GameMechs.h"
#include <iostream>
GameMechs::GameMechs():input(0),exitFlag(false),loseFlag(false),score(0),boardSizeX(30),boardSizeY(15)
{
    food = new Food();
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
void GameMechs::Draw(int boardSizeX, int boardSizeY)
{
    
    for(int i=0;i<boardSizeX;i++)
    {
        std::cout<<"#";
    }
    std::cout<<std::endl;
    for(int j=0;j<boardSizeY;j++)
    {
        for(int i=0;i<boardSizeX;i++)
        {
            if(i==0||i==boardSizeX-1)
            {
                std::cout<<'#';
            }
            else if (i == food->getFoodPos().pos->x && j == food->getFoodPos().pos->y) {
                std::cout << food->getFoodPos().symbol;
            }
            else{
                std::cout<<' ';
            }
        }
        std::cout<<std::endl;
    }
    for(int i=0;i<boardSizeX;i++)
    {
        std::cout<<"#";
    }
    std::cout << std::endl;
}
