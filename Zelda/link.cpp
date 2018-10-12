/*******************************************************************************
 ** link.cpp
 ** This is the implementation file for the link menu and contains all the 
 ** member variables and functions for link.cpp
 ******************************************************************************/
#include "link.hpp"
#include "space.hpp"
#include <iostream>

using namespace std;



/*******************************************************************************
 ** Link Constructor
 ******************************************************************************/
Link::Link()
{
    playerHealth = 80;
    dies = 1;
    sides = 10;
}

/*******************************************************************************
 ** Returns Link's Name
 ******************************************************************************/
void Link::setHealth(int health)
{
    playerHealth = health;
}

int Link::getHealth()
{
    return playerHealth;
}

vector<Item*> Link::getItems()
{
    return items;
}

void Link::addItem(Item* item)
{
    items.push_back(item);
}


void Link::sayLinkStuff()
{
    string * linkQuotes = new string[8];

 	linkQuotes[0] = "Link: I must hurry and rescue Princess Zelda.";
	linkQuotes[1] = "Link: This place is so quiet. ";
	linkQuotes[2] = "Link: Who goes there? ";
	linkQuotes[3] = "Link: Scary....";
	linkQuotes[4] = "Link: It's so dark, someone turn on a light";
	linkQuotes[5] = "Link: Zelda always needs rescuing, tsk tsk. ";
	linkQuotes[6] = "Link: Hello, anyone there? ";
	linkQuotes[7] = "Link: hmmmm.....";
    int random = rand() % 8;
    std::cout << linkQuotes[random] << std::endl;

}

int Link::attack()
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


int Link::defense()
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


void Link::setDies(int dies)
{
    this->dies = dies;
}

void Link::setSides(int sides)
{
    this->sides = sides;
}

int Link::getMultiplier()
{
    return dies;
}

int Link::getDieSides()
{
    return sides;
}


void Link::setCurrentPlace(PLACE place)
{
    this->currentPlace = place;
}

PLACE Link::getCurrentPlace()
{
    return currentPlace;
}

Link::~Link()
{
    
}