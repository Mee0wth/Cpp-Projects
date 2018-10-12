/*******************************************************************************
 ** item.cpp
 ** This is the implementation file for the class items and contains all the 
 ** member variables and functions for items.cpp
 ******************************************************************************/
#include "item.hpp"

Item::Item(string name,int dies,int sides)
{
    this->name = name;
    this->dies = dies;
    this->sides = sides;
}

string Item::getItemName()
{
    return name;
}

int Item::getMultiplier()
{
    return dies;
}

int Item::getDieSides()
{
    return sides;
}

Item::~Item()
{
    
}