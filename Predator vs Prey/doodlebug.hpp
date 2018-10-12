/*******************************************************************************
** Doodlebug Class
**     Header file for the Doodlebug Class contains some setter and getter functions
******************************************************************************/
#pragma once
#include "critter.hpp"

class Doodlebug : public Critter 
{
private:
	int lastAte;
	int starvePeriod;
	int colPos;
	int rowPos;

public:
	Doodlebug(Critter*** boardState, int boardSizeRow, int boardSizeCol, int currentDay);
	void move(int currentDay, int* newCoords, int currentRow, int currentCol);
	void breed(int currentDay, int* newCoords, int currentRow, int currentCol);
	void setLastAte(int lastAte);
	int getStarvePeriod();
	int getLastAte();
	int getSquareState(const Critter ** critterHolder, int inRow, int inCol);
};
