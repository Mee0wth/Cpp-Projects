/********************************************************************* 
** Author: CS162 Team 37
** Date: 5/13/2018
** Group Project: Predator-Prey Game
** Description: Implementation file for the Critter class
*********************************************************************/ 
// critter.cpp


#include <iostream>
#include <string>

#include "critter.hpp"

// Declare specific using statements to avoid namespace pollution

using std::cout;
using std::cin;
using std::endl;


// constructor
Critter::Critter(int day, int initSpecies,int initbreedingPeriod, int initSizeRow, int initSizeCol, Critter*** pointerToBoardState)
{
    setDayBirth(day);
    setSpecies(initSpecies);
    setCritterChar(initSpecies);
    setBreedingPeriod(initSpecies);
    setDayLastBred(day);
    setDayLastMove(day);
    setSizeRow(initSizeRow);
    setSizeCol(initSizeCol);
    setBoardStatePtr(pointerToBoardState);
}

// getters
int Critter::getDayBirth()
{
    return dayBirth;
}

int Critter::getSpecies() const
{
    return species;
}

int Critter::getDayLastBred()
{
    return dayLastBred;
}

int Critter::getDayLastMove()
{
    return dayLastMove;
}

int Critter::getBreedingPeriod()
{
    return breedingPeriod;
}

char Critter::getCritterChar()
{
    return critterChar;
}

int Critter::getBoardSizeRows()
{
    return sizeRow;
}

int Critter::getBoardSizeCols()
{
    return sizeCol;
}


// setters
void Critter::setDayLastBred(int newDayLastBred)
{
    dayLastBred = newDayLastBred;
}

void Critter::setDayLastMove(int newDayLastMove)
{
    dayLastMove = newDayLastMove;
}
	
void Critter::setSpecies(int initSpecies)
{
    species = initSpecies;
}

void Critter::setDayBirth(int initDayBirth)
{
    dayBirth = initDayBirth;
}

void Critter::setBreedingPeriod(int species)
{
    // const int ANT_ID = 0;
    // const int DB_ID = 1;
    if (species == 0)
    {
        breedingPeriod = 3;
    }
    else
    {
        breedingPeriod = 8;
    }
}

void Critter::setCritterChar(int species)
{
    // const int ANT_ID = 0;
    // const int DB_ID = 1;
    if (species == 0)
    {
        critterChar = char(79);
    }
    else
    {
        critterChar = char(88);
    }
}

void Critter::setSizeRow(int initSizeRow)
{
    sizeRow = initSizeRow;
}

void Critter::setSizeCol(int initSizeCol)
{
    sizeCol = initSizeCol;
}

void Critter::setBoardStatePtr(Critter*** initPointerToBoardState)
{
    pointerToBoardState = initPointerToBoardState;
}


void Critter::print()
{
    cout << getCritterChar();
}