/*******************************************************************************
 ** link.hpp
 ** This is the header file for the class link and contains all the 
 ** declarations for the link class.
 ******************************************************************************/
#ifndef LINK_HPP
#define LINK_HPP
#include <string>
#include <vector>
#include "space.hpp"

using namespace std;

class Link 
{
    private:
        int playerHealth;
        PLACE currentPlace = PLACE::gate;
        vector<Item*> items;
        int dies;
        int sides;
    public:
        Link();
        ~Link();
        
        void setHealth(int health);
        void sayLinkStuff();
        void setCurrentPlace(PLACE);

        int getHealth();
        vector<Item*> getItems();
        void addItem(Item*);
        PLACE getCurrentPlace();


        void setDies(int);
        void setSides(int);
        int getMultiplier();
        int getDieSides();
        
        // Link's attack
        int attack();
        int defense();
};

#endif