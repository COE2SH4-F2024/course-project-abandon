#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    // more actions to be included
    objPos playerPos;
    x = mainGameMechsRef->getBoardSizeX();
    y = mainGameMechsRef->getBoardSizeY();
    playerPos.pos->x = x/2;
    playerPos.pos->y = y/2;
    playerPos.symbol = '*'; 
    playerPosList = new(objPosArrayList);
    playerPosList->insertHead(playerPos); 
    
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList * Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
    
}

void Player::updatePlayerDir()
{
// PPA3 input processing logic
    switch(mainGameMechsRef->getInput())
    {                      
        // Add more key processing here
        case 'w':
            if(myDir!=  DOWN){
                myDir = UP;
            }
            break;
        // Add more key processing here
        case 'd':
            if(myDir !=  LEFT){
                myDir = RIGHT;
            }
            break;
        // Add more key processing here
        case 'a':
            if(myDir !=  RIGHT){
                myDir = LEFT;
            }
            break;
        case 's':
            if(myDir !=  UP){
                myDir = DOWN;
            }
            break;
        default:
            break;
    }
    mainGameMechsRef->clearInput();    
}

void Player::movePlayer()
{
    objPos playerPos;
    playerPos = playerPosList->getHeadElement();
    // PPA3 Finite State Machine logic
     if (myDir == UP){
        playerPos.pos->y--;
        if (playerPos.pos->y <= 0){
            playerPos.pos->y = y-2;
        }


    }
    else if (myDir== DOWN){
        playerPos.pos->y ++;
        if (playerPos.pos->y >= y-1){
            playerPos.pos->y = 1;
        }

    }
    else if (myDir == RIGHT){
        playerPos.pos->x ++;
        if (playerPos.pos->x >= x-1){
            playerPos.pos->x = 1;
        }
        
    }
    else if (myDir == LEFT){
        playerPos.pos->x --;
        if (playerPos.pos->x <= 0){
            playerPos.pos->x = x-2;
        }
        
    }
    playerPosList->insertHead(playerPos);
    playerPosList->removeTail();
}

// More methods to be added