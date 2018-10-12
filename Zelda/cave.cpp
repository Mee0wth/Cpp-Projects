/*******************************************************************************
 ** cave.cpp
 ** This is the implementation file for the class cave and contains all the 
 ** member variables and functions for cave.cpp
 ******************************************************************************/
#include "cave.hpp"
#include <iostream>

using namespace std;
Cave::Cave()
{
    setBossName("Dark Link"); 
    setHealth(10);
    setItem(new Item("Dark Link's Shadow", 6,6));
    setDies(6);
    setSides(3);

}

void Cave::conversation()
{
    cout << "================> CAVE <================" << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "The Cave is dark... there are bats on the ceilings,"
         << endl;
    cout << " and water puddles on the ground. A mysterious dark "
         << endl;
    cout << "figure emerges from the shadows. " << endl;
    cout << endl;
 
    cout << "Dark Link: It's been a long time Link. " << endl;
    cout << "Dark Link Shouts: ";
    bossBattleCry();
    cout << endl;
}


string Cave::getType()
{
    return "Cave";
}

Cave::~Cave()
{
    delete getItem();
    setItem(nullptr);
}