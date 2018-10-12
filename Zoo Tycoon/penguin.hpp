/******************************************************************************
 ** Penguin
 ** This is the penguin class header file that contains all the member variables
 ** and function declarations for penguin.cpp
 * ****************************************************************************/
#include "animal.hpp"
#ifndef PENGUIN_HPP
#define PENGUIN_HPP

class Penguin: public Animal
{
    public:
        Penguin();
        Penguin(int age);

};
#endif 
