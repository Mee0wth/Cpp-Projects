/*********************************************************************
** Program name: validation.hpp
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
*********************************************************************/

#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <limits>
#include <string>

int checkType(int *const usersInput);
int getValidInput(int *const usersInput, const int min = std::numeric_limits<int>::min(), const int max = std::numeric_limits<int>::max());
int stringToNum(int *const usersInput, const std::string inputString);

int checkType(double *const usersInput);
int getValidInput(double *const usersInput, const double min = std::numeric_limits<double>::min(), const double max = std::numeric_limits<double>::max());
int stringToNum(double *const usersInput, const std::string inputString);

int getValidInput(std::string *const usersInput, const int min = 1, const int max = -1);

#endif