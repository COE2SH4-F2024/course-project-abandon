#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
listSize = 0;
arrayCapacity = 200;
aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
delete[] aList;
}

int objPosArrayList::getSize() const
{
return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
if(listSize == arrayCapacity)
    { 
        return;
    }
for(int i = listSize; i > 0; i--)   
        aList[i] = aList[i - 1];  // shuffling towards the tail

    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
 if(listSize == arrayCapacity)
    {
        return;
    }

    aList[listSize++] = thisPos;
    
}

void objPosArrayList::removeHead()
{
    if(listSize == 0)
    {
        
        return;
    }

    for(int i = 0; i < listSize - 1; i++)   
        aList[i] = aList[i + 1];  

    listSize--;
    
}

void objPosArrayList::removeTail()
{
     if(listSize == 0)
    {
        return;
    }

    listSize--; 
    
}

objPos objPosArrayList::getHeadElement() const
{
    if(listSize == 0)
    {
         return objPos();
    }

    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
 if(listSize == 0)
    {
        return objPos();
    }

    return aList[listSize-1];  
}

objPos objPosArrayList::getElement(int index) const
{
if (index < 0 || index >= listSize) {
         return objPos();
    }
    return aList[index];  
}
