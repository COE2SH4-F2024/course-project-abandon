#include "objPos.h"
//Default constructor
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}
//Constructor

objPos::objPos(int xPos, int yPos, char sym)
{
    //Initializes position and assigns a symbol
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule
//copy, copy assignment, delete 
//Copy constructor
objPos::objPos(const objPos &t){
    pos = new Pos{t.pos->x, t.pos->y};
    symbol = t.symbol;
    
}
//Copy assignment operator
objPos& objPos::operator=(const objPos &t){
    //returns if same position is given
    if(this == &t){
        return *this;
    }
    delete pos;
    pos = new Pos{t.pos->x, t.pos->y};  
    symbol = t.symbol;
    return *this;

}
//Destructor
objPos::~objPos(){
    delete pos;
}
//

//Sets position and symbol with object o
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}
//Sets the position and symbol
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}
//Returns a copy
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}
//Return symbol
char objPos::getSymbol() const
{
    return symbol;
}
//Checks if current position is equal to another position
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}
//Returns symbol if positions match
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
