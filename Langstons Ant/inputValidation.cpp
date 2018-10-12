/*******************************************************************************
 ** Function: inputValidation.cpp
 ** This is the implementation for inputValidation.cpp. It checks to see if the 
 ** user enters the correct input of an int data type.
 ******************************************************************************/
#include <iostream>
#include <limits>
#include "./inputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;

int getRow()
{
    int row = 0;
    
    cout << "Enter row: " << endl;
    cin >> row;

    while (!(cin) || (row < 0 ))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
        cout << "Please enter valid user input. " << endl;
        cin >> row;
    }
    return row;
}

int getCol()
{
    int col = 0;
    
    cout << "Enter col: " << endl;
    cin >> col;

    while (!(cin) || (col < 0))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
        cout << "Please enter valid user input. " << endl;
        cin >> col;
    }
    return col;
}

int getX()
{
    int xPos = 0;
    
    cout << "Enter x position: " << endl;
    cin >> xPos;

    while (!(cin) || xPos < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
        cout << "Please enter valid user input. " << endl;
        cin >> xPos;
    }
    return xPos;
}

int getY()
{
    int yPos = 0;
    
    cout << "Enter y position: " << endl;
    cin >> yPos;

    while (!(cin) || yPos < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
        cout << "Please enter valid user input. " << endl;
        cin >> yPos;
    }
    return yPos;
}

int getSteps()
{
    int steps = 0;
    
    cout << "Enter steps to simulate: " << endl;
    cin >> steps;

    while (!(cin) || steps < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
        cout << "Please enter valid user input. " << endl;
        cin >> steps;
    }
    return steps;
}

int endGameMenu()
{
    int endGameChoice = 0;

     cout << "Game End. " << endl;
     cout << "Would you like to " << endl;
     cout << "1. Play Again? " << endl;
     cout << "2. Exit " << endl;
     cin >> endGameChoice;

     while ( !(cin) || endGameChoice < 1 || endGameChoice > 2 || cin.peek() != '\n')
    {
        cout << "Invalid Input. Please enter '1' or '2'. " << endl;
        cin.clear();
        cin.ignore();
        cin >> endGameChoice;
    }
    return endGameChoice;     
}
