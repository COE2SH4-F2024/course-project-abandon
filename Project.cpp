#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000
#define Y_SIZE 20
#define X_SIZE 20

bool exitFlag;
Player player(NULL);


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
    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    player.updatePlayerDir();
    player.movePlayer();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int xx,yy,found = 0;
    int k;
    objPosArrayList * a;
    a = player.getPlayerPos();
    for(yy = 0; yy < Y_SIZE; yy++){
        for(xx= 0; xx < X_SIZE; xx++){
            found = 0;
            for(k = 0; k<a->getSize(); k++){
                
                if((xx == a->getElement(k).pos->x) && (yy == a->getElement(k).pos->y)){
                    found = 1;
                    break;
                }
            }
            if ((xx == 0) || (yy == 0) || (xx == X_SIZE - 1) || (yy == Y_SIZE -1)){
                MacUILib_printf("#");                
            }
            else if(found == 1){
                MacUILib_printf("%c",a->getElement(k).getSymbol());
            }
            else{
                MacUILib_printf(" ");
            }
            
        }
        MacUILib_printf("\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
