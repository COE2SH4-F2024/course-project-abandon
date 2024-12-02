#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
using namespace std;

#define DELAY_CONST 100000
int boardSizeX;
int boardSizeY;
bool exitFlag;
GameMechs* gameMechs;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    boardSizeX = 30; 
    boardSizeY = 15;
    gameMechs = new GameMechs(boardSizeX, boardSizeY);
    objPos playerPos;
    gameMechs->generateFood(playerPos);
    gameMechs->generateFood(playerPos);
    delete playerPos.pos;
    exitFlag = false;
}

void GetInput(void)
{
   if (MacUILib_hasChar()) {
        char userInput = MacUILib_getChar();
        gameMechs->setInput(userInput);
        if (userInput == ' ') {
            exitFlag = true;
        }
    }
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    if (gameMechs) {
        gameMechs->Draw(boardSizeX, boardSizeY);
        std::cout << "Score: " << gameMechs->getScore() << std::endl;
        std::cout << "Input: " << gameMechs->getInput() << std::endl;
    }
        
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    delete gameMechs;
    gameMechs = nullptr;
    MacUILib_uninit();
}
