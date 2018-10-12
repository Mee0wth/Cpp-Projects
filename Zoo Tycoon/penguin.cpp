/******************************************************************************
 ** Penguin Class
 ** This is the penguin class implementation file that contains all the 
 ** definitions for penguin class. 
 * ****************************************************************************/
#include "penguin.hpp"

Penguin::Penguin()
{
    setAge(-1);
    setCost(1000);
    setFoodCost(10);
    setNumOfBabies(0);
    setRevenue(100);
}

Penguin::Penguin(int age)
{
    setAge(age);
    setCost(1000);
    setFoodCost(10);
    setNumOfBabies(0);
    setRevenue(100); 
}