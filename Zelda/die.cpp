/*******************************************************************************
 ** die.cpp
 ** This file contains the implementation file for the die class
 ******************************************************************************/

#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>     
#include "die.hpp"

// Die Constructor
Die::Die(int sides)
{
      this->sides = sides;
}

int Die::roll()
{
    int rolled;
    // each die has 10 sides
    rolled = (rand() % sides) + 1;
    return rolled;
}