/*********************************************************************
** Program name: menu.hpp
** Assignment: Group Project
** Date: May 1, 2018
** 
** What this class does: 
**
** Dependencies:
** validation.hpp
**
*********************************************************************/

#include "menu.hpp"
#include "validation.hpp"
#include <iostream>

// Default constructor
Menu::Menu()
{
    setTitle("");
    menuSize = 0;
}

// What it does: Constructs a Menu object, initializes
//  all data fields.
//
// Arguments: String to be used as menu's title
//
// Returns: None
//
Menu::Menu(std::string title)
{
    setTitle(title);
    menuSize = 0;
}

// Set menu title
void Menu::setTitle(std::string title)
{
    menuTitle = title;
}

// What it does: Adds a menu option.
//
// Arguments: String, which will be the text that
//  displays when menu is printed.
//
// Returns: None
//
void Menu::add(std::string option)
{
    menuOptions.push_back(option);

    menuSize = menuOptions.size();
}

// What it does: Prints the menu to terminal (if applicable)
//  and then prompts the user for input.  User's input is run
//  through validation.
//
// Arguments: None
//
// Returns: Int - user's menu choice
//
int Menu::run()
{
    int userMenuChoice = 0;

    if (menuSize > 0)
    {
        do
        {
            std::cout << std::endl;
            print();

            std::cout << "Please select an option: ";
        } while (!getValidInput(&userMenuChoice, 1, menuSize));
    }
    else
    {
        std::cout << std::endl;
        std::cout << menuTitle << std::endl;
        std::cout << "-No menu options-\n"
                  << std::endl;
    }

    return userMenuChoice;
}

// What it does: Print the menu to the terminal with the
//  following format
//
//  Menu Title
//  1. Menu option 1
//  2. Menu option 2
//  ...
//
// Arguments: None
//
// Returns: None
//
void Menu::print()
{
    std::cout << std::endl;
    std::cout << menuTitle << std::endl;

    for (int i = 0; i < menuSize; i++)
    {
        std::cout << i + 1 << ": " << menuOptions[i] << std::endl;
    }

    std::cout << std::endl;
}