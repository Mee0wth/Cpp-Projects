/******************************************************************************
 ** Turtle Class
 ** This is the turtle class header file that contains all the member variables
 ** and function declarations for turtle.cpp
 * ****************************************************************************/
#include "animal.hpp"
#ifndef TURTLE_HPP
#define TURTLE_HPP

class Turtle: public Animal
{
    public:
        Turtle();
        Turtle(int age);

};
#endif 
