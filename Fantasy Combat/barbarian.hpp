/*******************************************************************************
 ** barbarian.hpp
 ** This is the header file for the barbarian class and includes all the 
 ** declarations for barbarian.cpp
 ******************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"

class Barbarian: public Character
{
    public:
        Barbarian():Character(" ", "Barbarian",0,12){};
        int attack();
        int defense();
        void takeDmg(int);
        ~Barbarian();
};

#endif