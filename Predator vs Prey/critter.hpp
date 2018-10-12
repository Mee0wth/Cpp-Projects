/********************************************************************* 
** Author: CS162 Team 37
** Date: 5/13/2018
** Group Project: Predator-Prey Game
** Description: Header file to define the interface of the Critter class
*********************************************************************/ 
// critter.hpp

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <iostream>
#include <string>


// Declare specific using statements to avoid namespace pollution

using std::cout;
using std::cin;
using std::endl;

enum Direction {UP, RIGHT, DOWN, LEFT};

// const int ANT_ID = 0;
// const int DB_ID = 1;

class Critter
{
private: 

    int dayBirth;
    int dayLastBred;
    int dayLastMove;
    int species;
    int breedingPeriod;
    char critterChar;
    int sizeRow;
    int sizeCol;


protected:
    // setters
    void setSpecies(int initSpecies);
    void setDayBirth(int initDayBirth);
    void setBreedingPeriod(int species);
    void setCritterChar(int species);
    void setSizeRow(int sizeRow);
    void setSizeCol(int sizeCol);
    void setBoardStatePtr(Critter*** pointerToBoardState);

    const Critter* const* const* pointerToBoardState;

public:

    // default constructor
    Critter() {};

    // constructor
    Critter(int day, int initSpecies, int initbreedingPeriod, int initSizeRow, int initSizeCol, Critter*** pointerToBoardState);

    // destructor
    virtual ~Critter() {};

    // getters
    int getDayBirth();
    int getSpecies() const;
    int getDayLastBred();
    int getDayLastMove();
    int getBreedingPeriod();
    char getCritterChar();
    int getBoardSizeRows();
    int getBoardSizeCols();


    // setters
    void setDayLastBred(int newDayLastBred);
    void setDayLastMove(int newDayLastMove);

    /**********************************************************
    / class methods
    **********************************************************/

    void print();

    // pure virtual functions defined in the derived classes of Ant and Doodlebug
    virtual void move(int currentDay, int* newCoords, int currentRow, int currentCol) = 0;
    virtual void breed(int currentDay, int * passCoords, int currentRow, int currentCol) = 0;

    // virtual functions defined in the derived classes of Doodlebug
    virtual int getLastAte(){};
    virtual int getStarvePeriod(){};
	
};
#endif