/*******************************************************************************
 ** Medusa.hpp
 ** This is the header file for the medusa class and includes all the declarations
 ** for medusa.cpp 
 ******************************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "character.hpp"

class Medusa: public Character
{
    public:
        Medusa():Character(" ", "Medusa",3,8){};
        int attack();
        int defense();
        void takeDmg(int);
        ~Medusa();
};

#endif