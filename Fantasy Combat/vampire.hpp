/*******************************************************************************
 ** vampire.hpp
 ** This is the header file for the vampire class and includes all the 
 ** declarations for vampire.cpp
 ******************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "character.hpp"

class Vampire: public Character
{
    private:
        int charm = 0;
    public:
        Vampire():Character(" ", "Vampire",0,18){};
        int attack();
        int defense();
        void takeDmg(int);
        ~Vampire();
};

#endif