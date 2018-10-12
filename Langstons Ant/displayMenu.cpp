/*******************************************************************************
 ** Function: displayMenu.cpp
 ** This is the implementation for function displayMenu.cpp. This function
 ** prompts the user to choose from a menu and returns either a '1' or '2'.
 ******************************************************************************/
#include <iostream>
#include "displayMenu.hpp"

using std::cout;
using std::cin;
using std::endl;

int displayMenu()
{
    
    int choice = 0;

    cout << "Langston's Ant Simulation. Press: " << endl;
    cout << "1. Start Langston's Ant. " << endl;
    cout << "2. Exit " << endl;
    cin >> choice;

    while ( !(cin) || choice < 1 || choice > 2 || cin.peek() != '\n')
    {
        cout << "Invalid Input. Please enter '1' or '2'. " << endl;
        cin.clear();
        cin.ignore();
        cin >> choice;
    }
    return choice;
    
}