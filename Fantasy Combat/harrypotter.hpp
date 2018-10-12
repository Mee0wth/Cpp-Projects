/*******************************************************************************
 ** harrypotter.hpp
 ** This is the header file for the harry potter class and includes all the 
 ** declarations for harrypotter.cpp. 
 ******************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "character.hpp"

class HarryPotter: public Character
{
    private:
        int deaths = 0;
    public:
        HarryPotter():Character(" ", "Harry Potter",0,10){};
        int attack();
        int defense();
        void takeDmg(int);
        ~HarryPotter();
};

#endif