/*******************************************************************************
 ** tower.cpp
 ** This is the implementation file for the class tower and contains all the 
 ** member variables and functions for tower.cpp
 ******************************************************************************/
#include "tower.hpp"
#include <iostream>

using namespace std;


Tower::Tower()
{
    setBossName("Queen Gohma"); 
    setHealth(10);
    setItem(new Item("Gohma's Eye", 6,9));
    setDies(6);
    setSides(3);
}


void Tower::conversation()
{
    cout << "================> TOWER <================" << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "The tower is long, stretches to the sky. You look around trying "
         << endl;
    cout << "to get an idea of your location. A shriek rattles the walls and "
         << endl;
    cout << "echos through the tower. Suddnely, the ground gives way and you "
         << endl;
    cout << "fall through. When the dust clears, you are confronted with a "
         << endl;
    cout << "spider with one giant eye. " << endl;
    cout << endl;
    
    cout << "Queen Gohma approaches, her eye stares intently at you " << endl;
    cout << "Queen Gohma: ";
    bossBattleCry();
    cout << endl;
}

string Tower::getType()
{
    return "Tower";
}

Tower::~Tower()
{
    delete getItem();
    setItem(nullptr);
}