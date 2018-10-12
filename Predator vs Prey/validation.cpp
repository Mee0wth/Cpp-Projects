/*********************************************************************
** Program name: validation.cpp
** Assignment: Group Project
** Date: May 1, 2018
** 
** What do these functions do: 
** Gets value from input stream and checks if it is valid
**
** Arguments: 
** A pointer to where the user's input should be stored
** (Sometimes an option) valid range (inclusive)
**
** Returns:
** An int: if it was valid, 1; if not valid, 0
**
** Citation:
** - String to number
** <http://www.cplusplus.com/reference/string/stoi/>
** <http://www.cplusplus.com/reference/stdexcept/out_of_range/>
*********************************************************************/

#include "validation.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

// What it does: Gets a valid integer from the user.
//
// Arguments: Pointer of where to save the converted user's input.
//  Range arguments are optional.  They will default to the minimum
//  and maximum values for integers.
//
// Returns: Integer, referring to whether the user's input passed
//  the tests and was successfully converted.
//  1-successful, is int; 0-unsuccessful, not an int.
//
int getValidInput(int *const usersInput, const int min, const int max)
{
    if (checkType(usersInput))
    {
        if (*usersInput >= min && *usersInput <= max)
        {
            return 1;
        }
        else
        {
            std::cout << "Error: out of range (min = " << min
                      << ", max = " << max << ") inclusive" << std::endl;
        }
    }

    return 0;
}

// What it does: Gets user input from terminal and saves it as string.
//  checks that each character meets specifications of the data type
//  (int, in this function)
//
// Arguments: Pointer of where to save the converted user's input.
//  Pointer to integer, here.
//
// Returns: Integer, referring to whether the user's input passed
//  the tests.  1-successful, is int; 0-unsuccessful, not an int.
//
int checkType(int *const usersInput)
{
    int flagTypeIsCorrect = 1;
    std::string userInputString;

    //Clear input stream before getting new input
    std::cin >> std::ws;
    getline(std::cin, userInputString);

    for (int i = 0; i < userInputString.size(); i++)
    {
        //Check if character isn't a digit
        if (!isdigit(userInputString[i]))
        {
            if (i == 0 && (userInputString[i] == '+' || userInputString[i] == '-'))
            {
                //First char is allowed to be + or -
            }
            else
            {
                flagTypeIsCorrect = 0;
            }
        }
    }

    if (flagTypeIsCorrect)
    {
        // Convert input from string to integer
        flagTypeIsCorrect = stringToNum(usersInput, userInputString);
    }
    else
    {
        std::cout << "Error: not an integer" << std::endl;
    }

    return flagTypeIsCorrect;
}

// What it does: Converts a string to an integer, and saves the int
//  at the provided address.
//
// Arguments: Pointer of where to save the converted user's input.
//  User's input as a string.
//
// Returns: Integer, referring to whether the user's input was
// able to be converted.  1-successful, is int; 0-unsuccessful, not an int.
//
int stringToNum(int *const usersInput, const std::string inputString)
{
    std::string::size_type sz; //alias of size_t

    try
    {
        *usersInput = std::stoi(inputString, &sz);
    }
    catch (const std::out_of_range &oor)
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        return 0;
    }
    catch (const std::invalid_argument &oor)
    {
        std::cerr << "Invalid argument error: " << oor.what() << '\n';
        return 0;
    }

    return 1;
}

int getValidInput(double *const usersInput, const double min, const double max)
{
    if (checkType(usersInput))
    {
        if (*usersInput >= min && *usersInput <= max)
        {
            return 1;
        }
        else
        {
            std::cout << "Error: out of range (min = " << min
                      << ", max = " << max << ") inclusive" << std::endl;
        }
    }

    return 0;
}

int checkType(double *const usersInput)
{
    int flagTypeIsCorrect = 1;
    std::string userInputString;
    int pointCounter = 0;

    //Clear input stream before getting new input
    std::cin >> std::ws;
    getline(std::cin, userInputString);

    for (int i = 0; i < userInputString.size(); i++)
    {
        //Check if character isn't a digit
        if (!isdigit(userInputString[i]))
        {
            if (userInputString[i] == '.')
            {
                pointCounter++;

                // There can only be 1 decimal point
                if (pointCounter > 1)
                {
                    flagTypeIsCorrect = 0;
                }
            }
            else if (i == 0 && (userInputString[i] == '+' || userInputString[i] == '-'))
            {
                //First char is allowed to be + or -
            }
            else
            {
                flagTypeIsCorrect = 0;
            }
        }
    }

    if (flagTypeIsCorrect)
    {
        // Convert input from string to integer
        flagTypeIsCorrect = stringToNum(usersInput, userInputString);
    }
    else
    {
        std::cout << "Error: not a double (scientific notation not allowed)" << std::endl;
    }

    return flagTypeIsCorrect;
}

int stringToNum(double *const usersInput, const std::string inputString)
{
    std::string::size_type sz; //alias of size_t

    try
    {
        *usersInput = std::stod(inputString, &sz);
    }
    catch (const std::out_of_range &oor)
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        return 0;
    }
    catch (const std::invalid_argument &oor)
    {
        std::cerr << "Invalid argument error: " << oor.what() << '\n';
        return 0;
    }

    return 1;
}

int getValidInput(std::string *const usersInput, const int min, int max)
{
    std::string userInputString;
    if (max == -1)
    {
        max = usersInput->max_size();
    }

    //Clear input stream before getting new input
    std::cin >> std::ws;
    getline(std::cin, userInputString);

    if (userInputString.size() >= min && userInputString.size() <= max)
    {
        *usersInput = userInputString;
        return 1;
    }
    else
    {
        std::cout << "Error: out of length range (min = " << min
                  << ", max = " << max << ") inclusive" << std::endl;
    }

    return 0;
}