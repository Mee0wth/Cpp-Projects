/*******************************************************************************
 ** die.hpp
 ** This file contains the declartion for the die class
 ******************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die 
{
    private:
        int sides;
    public:
        Die(int);
        int roll();
};

#endif