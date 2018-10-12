/*******************************************************************************
 ** space.cpp
 ** This is the implementation file for the class space and contains all the 
 ** member variables and functions for space.cpp
 ******************************************************************************/
#include "space.hpp"
#include "die.hpp"

using namespace std;


string Space::getBossName()
{
    return bossName;
}

void Space::setBossName(string bossName)
{
    this->bossName = bossName;
}


void Space::setHealth(int health)
{ 
    bossHealthPoint = health;
}

int Space::getHealth()
{
    return bossHealthPoint;
}

void Space::setItem(Item* item)
{
    this->item = item;
}


Item* Space::getItem()
{
    return item;
}

void Space::setDies(int dies)
{
    this->dies = dies;
}

void Space::setSides(int sides)
{
    this->sides = sides;
}

int Space::getMultiplier()
{
    return dies;
}

int Space::getDieSides()
{
    return sides;
}

void Space::bossBattleCry()
{
    string * bossCry = new string[8];

 	bossCry [0] = "Get read, here I come! ";
	bossCry [1] = "Think, before you move boy! ";
	bossCry [2] = "Move out of the way! ";
	bossCry [3] = "Ready to die? ";
	bossCry [4] = "I will eat you alive!";
	bossCry [5] = "Any last words? ";
	bossCry [6] = "You have a death wish boy. ";
	bossCry [7] = "It's too late to turn back now. ";
    int random = rand() % 8;
    std::cout << bossCry[random] << std::endl;
}


int Space::attack()
{
    int val = 0;
    Die* die = new Die(getDieSides());
    for (int i = 0; i < getMultiplier() ; i++)
    {
        val += die->roll();
    }
    delete die;
    return val;
}


int Space::defense()
{
    int val = 0;
    Die* die = new Die(getDieSides());
    for (int i = 0; i < getMultiplier() ; i++)
    {
        val += die->roll();
    }
    delete die;
    return val/3;
}

Space::~Space()
{}