/******************************************************************************
 ** Animal Class
 ** This is the implementation file for animal.cpp and includes all the 
 ** definitions for animal.cpp
 * ****************************************************************************/
#include "animal.hpp"

// Default Constructor
Animal::Animal()
{
}

// Accessors 
int Animal::getAge() const
{
    return age;
}

int Animal::getCost() const
{
    return cost;
}

int Animal::getNumOfBabies() const
{
    return numOfBabies;
}

int Animal::getFoodCost() const
{
    return foodCost;
}

int Animal::getRevenue() const
{
    return revenue;
}


// Mutators
void Animal::setAge(int age)
{
    this->age = age;
}

void Animal::setCost(int cost)
{
    this->cost = cost;
}

void Animal::setNumOfBabies(int baby)
{
    numOfBabies = baby;
}

void Animal::setFoodCost(int food)
{
    foodCost = food;
}

void Animal::setRevenue(int revenue)
{
    this->revenue = revenue;
}