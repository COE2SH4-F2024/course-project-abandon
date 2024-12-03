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
    //input processing
    switch(mainGameMechsRef->getInput())
    {           
                   
        case '\b':
            mainGameMechsRef->setExitTrue();
            break;
        case 'w':
            if(myDir!=  DOWN){
                myDir = UP;
            }
            break;
        case 'd':
            if(myDir !=  LEFT){
                myDir = RIGHT;
            }
            break;
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
    //Finite State Machine logic
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
    //check if the head of the snake ate the food and increment score
    if((playerPos.pos->x == mainGameMechsRef->getFoodPos().pos->x) && (playerPos.pos->y == mainGameMechsRef->getFoodPos().pos->y)){
        playerPosList->insertHead(playerPos);
        mainGameMechsRef->generateFood(playerPos);
        mainGameMechsRef->incrementScore();
    }
    //else move the head of the snake and remove tail
    else{
       playerPosList->insertHead(playerPos);
       playerPosList->removeTail();  
    }
    //if snake head touches body set lose flag
    for(int j = 1; j < playerPosList->getSize(); j++){
        if((playerPosList->getHeadElement().pos->x == playerPosList->getElement(j).pos->x)&& (playerPosList->getHeadElement().pos->y == playerPosList->getElement(j).pos->y)){
            mainGameMechsRef->setLoseFlag();
        }

    }
    
}

// More methods to be added
