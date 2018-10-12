/*******************************************************************************
 ** castle.cpp
 ** This is the implementation file for the class castle and contains all the 
 ** member variables and functions for castle.cpp
 ******************************************************************************/
#include "castle.hpp"
#include <iostream>

using namespace std;


Castle::Castle()
{
    setBossName("Ganon"); 
    setHealth(10);
    setItem(new Item("Ganon's Steed", 10,10));
    setDies(6);
    setSides(3);
}


void Castle::conversation()
{
    cout << "================> GANON'S CASTLE <================" << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

    cout << "A giant cloud of smoke explodes from the ground, walls, and all" 
         << endl;
    cout << " around you. A tornado appears and dissapears, standing in its "
         << endl;
    cout << "place is Ganon on his dark steed. " << endl;
    
    cout << endl;
    cout << "Ganon: Link, I am impressed you have been able to reach me. " << endl;
    cout << "Ganon: Although impressive, you will never win. I almost killed "
         << "you 100 years ago, but today I will finish what I started. " << endl;

    cout << "Ganon: Prepare yourself. ";
    bossBattleCry();
    cout << endl;

}

string Castle::getType()
{
    return "Castle";
}

Castle::~Castle()
{
    delete getItem();
    setItem(nullptr);
}