/******************************************************************************
 ** Program: Langston's Ant
 ** Author: Linda Carey
 ** Date: 04/02/18
 ** Description: This program has an ant that travels around a grid of white
 ** cells and turns left if it hits a black cell and right if it hits a white 
 ** cell. If the cell is black when the ant hits the cell it will turn white and 
 ** vice versa. Langston's ant is a cellular automaton.
 * ****************************************************************************/
#include "displayMenu.hpp"
#include "inputValidation.hpp"
#include "ant.hpp"
#include "printBoard.hpp"

// Function Prototypes
Color ** createBoard(int, int);
void deleteBoard(Color ** board, int, int);


int main()
{
    int row = 0,
        col = 0,
        xPos = 0,
        yPos = 0,
        steps = 0,
        choice = 0,
        endGameChoice = 0;
    
    choice = displayMenu();

    switch(choice)
    {
        case 1:
            do
            {
                row = getRow();
                col = getCol();
                xPos = getX();
                // Board array initialized with index 0, in order to accurately set 
                // x, need to subtract 1 space
                xPos--;
                yPos = getY();
                // Board array initialized with index 0, in order to accurately set 
                // y, need to subtract 1 space
                yPos--;
                steps = getSteps();
                // Creates an ant object
                Color ** boardPtr = createBoard(row, col);
                Ant mainAnt(xPos, yPos, row, col, boardPtr);

                while (steps > 0 && !mainAnt.hitsWall())
                {
                    printBoard(mainAnt, row, col);
                    mainAnt.forward();
                    steps--;
                }
            
                endGameChoice = endGameMenu();
                deleteBoard(boardPtr, row, col);
            } while (endGameChoice == 1);
            break;

        case 2:
            break;
    }
    return 0;
}


// Board 

Color ** createBoard(int row, int col)
{
    Color **board = new Color *[row];
    for (int i = 0; i < row; ++i)
    {
        board[i] = new Color [col];
    }

    for (int c = 0; c < col; ++c)
    {
        for (int r = 0; r < row; ++r)
        {
            board[c][r] = Color::WHITE;
        }
    }
    return board;
}

void deleteBoard(Color ** board, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        delete [] board[i];
        board[i] = nullptr;
    }
    delete [] board;
    board = nullptr;
}

