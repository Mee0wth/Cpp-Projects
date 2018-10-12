/*********************************************************************
** Program name: board.hpp
** Assignment: Group Project
** Date: May 1, 2018
** 
** What this class does: 
** Coordinates are all (row, col) -- easier printing
** 
** Dependencies:
** 
**
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "critter.hpp"

class Board
{
  private:
    // Data members

    // Limits for board size
    const int MAX_ROW = 80;
    const int MAX_COL = 80;

    const int MAX_DAYS = 15000;

    // Constant to define what char to print if blank square
    // const char CHAR_EMPTY = ' ';

    // TESTING
    const char CHAR_EMPTY = ' ';

    // ******NEEDS TO BE DEFINED BY TEAM*********
    // Needs to match what is returned by int Critter::getSpecies()
    const int ANT_ID = 0;
    const int DB_ID = 1;

    // Chosen size of board
    // e.g. sizeRow = 3 means there will be 3 rows
    //  and the board rows will be:
    //  0
    //  1
    //  2
    //
    int sizeRow;
    int sizeCol;

    // For keeping track of game time
    int dayLimit;
    int dayCounter;

    // 2D dynamic array of pointers to critter objects
    Critter ***boardState;

    // Methods
    // Initialization helper - (#ants, #dbs)
    void setInitLocs(int, int);
    void placeRandLocCritters(int, int);

    // Prints the state of the board
    // ========USES CRITTER::PRINT()==========
    void printBoard();

    // Setters - NO VALIDATION
    void setDayCounter(int inDay)
    {
        dayCounter = inDay;
    }

    // Getters
    int getSizeRow()
    {
        return sizeRow;
    }

    int getSizeCol()
    {
        return sizeCol;
    }

    int getDayCounter()
    {
        return dayCounter;
    }

    // Game control
    // Increments current day by 1
    void incDay()
    {
        setDayCounter(getDayCounter() + 1);
    }
    void moveCritters(int);  //moves ants or dbs based on int parameter
    void breedCritters(int); // breeds ants/dbs based on int parameter
    void starveDoodlebugs();

    // Helps moveCritters
    void moveTo(Critter *, int, int, int, int);

    // Helps breedCritters
    void addCritter(int, int, int);

    // Holds the game flow
    void runNormalGame();

    // Handles getting parameters from user before running game
    void newGame();
    void extendedGame();

    // Creates a new board from current data members
    void makeBoardState();

    // Erases the boardState array
    void deleteBoardState();

    // Get the Critter* at a square (row, col)
    // returns an int to indicate success
    //      0 - given coords invalid (outside board)
    //      1 - given coords valid (inside board)
    int getSquareState(Critter **, int, int);

  protected:
    // Data members

    // Methods

  public:
    // Data members

    // Methods
    // Constructor
    Board();

    ~Board();

    // Method for running the prey-predator game
    // All game logic and control contained inside runGame()
    void runGame();
};

#endif