/******************************************************************************
 ** Tiger Class
 ** This is the Tiger class implementation file that contains all the 
 ** definitions for Tigerclass. 
 * ****************************************************************************/
#include "tiger.hpp"


Tiger::Tiger()
{
    setAge(-1);
    setCost(10000);
    setNumOfBabies(0);
    setFoodCost(50);
    setRevenue(2000);

}

Tiger::Tiger(int age)
{
    setAge(age);
    setCost(10000);
    setNumOfBabies(0);
    setFoodCost(50);
    setRevenue(2000);
}