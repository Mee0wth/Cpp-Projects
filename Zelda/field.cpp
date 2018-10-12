/*******************************************************************************
 ** field.cpp
 ** This is the implementation file for the class field and contains all the 
 ** member variables and functions for field.cpp
 ******************************************************************************/
#include "field.hpp"
#include <iostream>

using namespace std;


Field::Field()
{
    setBossName("King Dodongo"); 
    setHealth(10);
    setItem(new Item("Dodongo's Scale", 3,15));
    setDies(6);
    setSides(3);
}


void Field::conversation()
{
    cout << "================> FIELD <================" << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "The grash is lush, and the land is vast. Suddenly, the "
         << endl;
    cout << "the ground starkts shaking uncontrollably... and crakes open. "
         << endl;
    cout << "From beneath the ground crawls out a Lizard looking monster. " 
         << endl;
    
    cout << "King Dodongo sliters toward you. " << endl;
    cout << "King Dodongo: ";
    bossBattleCry();
    cout << endl;
}

string Field::getType()
{
    return "Field";
}

Field::~Field()
{
    delete getItem();
    setItem(nullptr);
}