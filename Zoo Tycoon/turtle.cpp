/******************************************************************************
 ** Turtle Class
 ** This is the turtle class implementation file that contains all the 
 ** definitions for turtle class. 
 * ****************************************************************************/
#include "turtle.hpp"

Turtle::Turtle()
{
    setAge(-1);
    setCost(100);
    setFoodCost(5);
    setNumOfBabies(0);
    setRevenue(5);
}

Turtle::Turtle(int age)
{
    setAge(age);
    setCost(100);
    setFoodCost(5);
    setNumOfBabies(0);
    setRevenue(5);
}