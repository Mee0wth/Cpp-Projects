/*******************************************************************************
 ** Ant Class
 **     This is the implementation file for the ant class and contains all the 
 **     member variables and member functions for ant.
 ******************************************************************************/
#include "ant.hpp"
#include "critter.hpp"
#include <random>
#include <ctime>
#include <cstdlib>

Ant::Ant(Critter ***boardState, int boardSizeRow, int boardSizeCol, int currentDay) : Critter(currentDay, 0, 3, boardSizeRow, boardSizeCol, boardState)
{
    // seed rand generator
    std::srand(std::time(nullptr));
}

void Ant::move(int currentDay, int *newCoords, int currentRow, int currentCol)
{
    // Keep track of when the last attempted move was
    setDayLastMove(currentDay);

    int newRow = currentRow;
    int newCol = currentCol;

    // Generate a direction to move
    // 0 - up; 1 - right; 2 - down; 3 - left;
    int direction = rand() % 4;

    switch (direction)
    {
    case 0:
        newRow = currentRow - 1;
        break;
    case 1:
        newCol = currentCol + 1;
        break;
    case 2:
        newRow = currentRow + 1;
        break;
    case 3:
        newCol = currentCol - 1;
        break;
    }

    const Critter *tempCritter;

    int flagValidSquare = getSquareState(&tempCritter, newRow, newCol);

    // If square is out of bounds or occupied, then don't move
    if (!flagValidSquare || tempCritter != NULL)
    {
        newRow = currentRow;
        newCol = currentCol;
    }

    // Tell board where Ant wants to move (or not move)
    newCoords[0] = newRow;
    newCoords[1] = newCol;
}

void Ant::breed(int currentDay, int *breedCoords, int currentRow, int currentCol)
{
    int breedRow;
    int breedCol;

    bool flagAllDirectionsChecked = 0;
    bool flagUpChecked = 0;
    bool flagRightChecked = 0;
    bool flagDownChecked = 0;
    bool flagLeftChecked = 0;

    bool breedingSuccessful = 0;

    const Critter *tempCritter;
    int flagSquareIsInBounds;

    // Loop until either a valid square is found or all direcitons have been checked
    while (!breedingSuccessful && !flagAllDirectionsChecked)
    {
        // Reset desired coords
        breedRow = currentRow;
        breedCol = currentCol;

        // Generate a direction to move
        // 0 - up; 1 - right; 2 - down; 3 - left;
        int direction = rand() % 4;

        switch (direction)
        {
        case 0:
            flagUpChecked = 1;
            breedRow = currentRow - 1;
            break;
        case 1:
            flagRightChecked = 1;
            breedCol = currentCol + 1;
            break;
        case 2:
            flagDownChecked = 1;
            breedRow = currentRow + 1;
            break;
        case 3:
            flagLeftChecked = 1;
            breedCol = currentCol - 1;
            break;
        }

        flagSquareIsInBounds = getSquareState(&tempCritter, breedRow, breedCol);

        if (flagSquareIsInBounds && tempCritter == NULL)
        {
            breedingSuccessful = 1;
        }

        flagAllDirectionsChecked = flagUpChecked && flagRightChecked && flagDownChecked && flagLeftChecked;
    }

    if (breedingSuccessful)
    {
        setDayLastBred(currentDay);

        breedCoords[0] = breedRow;
        breedCoords[1] = breedCol;
    }
    else
    {
        breedCoords[0] = currentRow;
        breedCoords[1] = currentCol;
    }
}

// Get the address of the Critter at a square (row, col)
// returns an int to indicate success
//      0 - given coords invalid (outside board)
//      1 - given coords valid (inside board)
int Ant::getSquareState(const Critter **critterHolder, int inRow, int inCol)
{
    // If coords valid (inside board)
    bool rowValid = (inRow >= 0) && (inRow < getBoardSizeRows());
    bool colValid = (inCol >= 0) && (inCol < getBoardSizeCols());

    if (rowValid && colValid)
    {
        // Pass along the address to the Critter at (inRow, inCol)
        *critterHolder = pointerToBoardState[inRow][inCol];

        // Communicate that coords were valid
        return 1;
    }
    else
    {
        // Communicate that coords were invalid
        // (outside of board bounds)
        return 0;
    }
}