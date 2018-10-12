/*******************************************************************************
 ** bluemen.hpp
 ** This is the header file for the bluemen class and includes all the 
 ** declarations for bluemen.cpp
 ******************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "character.hpp"

class Bluemen: public Character
{
    public:
        Bluemen():Character(" ", "Bluemen",3,12){};
        int attack();
        int defense();
        void takeDmg(int);
        ~Bluemen();
};

#endif
