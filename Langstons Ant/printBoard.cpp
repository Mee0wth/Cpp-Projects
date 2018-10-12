/*******************************************************************************
 ** Function: printBoard.cpp
 ** This is the implementation for printBoard.cpp. It takes an Ant, int row and 
 ** col and prints the output in console.
 ******************************************************************************/
#ifndef PRINTBOARD_HPP
#define PRINTBOARD_HPP
#include "ant.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

char convertEnumToChar(Color c)
{
    if (c == Color::BLACK)
    {
        return '#';
    }
    else
    {
        return ' ';
    }
}

void printBoard(Ant a, int row, int col)
{
    Color **boardPtr = a.getBoard();

    for (int i = 0; i < col; ++i)
    {
        cout << " ";
    }
    cout << endl;

    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            if (a.getYpos() == c && a.getXpos() == r)
            {
                cout << " " << "*";
            }
            else
            {
                cout << " " << convertEnumToChar(boardPtr[r][c]);
            }
        }
        cout << " " << endl;
    }

    for (int i = 0; i < col; ++i)
    {
        cout << " ";
    }
    cout << endl;
}

#endif