#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000
Player * player;
GameMechs * game;

bool exitFlag;
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while((false == game->getExitFlagStatus()) && (false == game->getLoseFlagStatus()))
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
    objPos foodpos(5,5,'x');
    exitFlag = false;
    game = new GameMechs();
    player = new Player(game);
    game->generateFood(foodpos);
}

void GetInput(void)
{
if (MacUILib_hasChar() != 0){
        game->setInput(MacUILib_getChar());

    }
    
}

void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer();
    

}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int xx,yy,found = 0;
    int k;
    int xsize = game->getBoardSizeX();
    int ysize = game->getBoardSizeY();
    objPosArrayList * a;
    a = player->getPlayerPos();
    //draw function checks what to display for each character on the game board 
    for(yy = 0; yy < ysize; yy++){
        for(xx= 0; xx < xsize; xx++){
            found = 0;
            //checks if we need to display snake body
            for(k = 0; k<a->getSize(); k++){
                
                if((xx == a->getElement(k).pos->x) && (yy == a->getElement(k).pos->y)){
                    found = 1;
                    break;
                }
            }
            //checks if we need to display the border
            if ((xx == 0) || (yy == 0) || (xx == xsize - 1) || (yy == ysize -1)){
                MacUILib_printf("#");                
            }
            //checks if we need to display the food
            else if (xx == game->getFoodPos().pos->x && yy == game->getFoodPos().pos->y) {
                MacUILib_printf("%c",game->getFoodPos().symbol);
            }
            //if found display the snake body
            else if(found == 1){
                MacUILib_printf("%c",a->getElement(k).getSymbol());
            }
            else{
                MacUILib_printf(" ");
            }
            
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("score: %d\n",game->getScore());

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();
    MacUILib_printf("your score was:%d",game->getScore());
    if(game->getLoseFlagStatus() == true){
        MacUILib_printf("\nyour snake ate its body");

    }
    delete player; 
    delete game;
    MacUILib_uninit();
}
