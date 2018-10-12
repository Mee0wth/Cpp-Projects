/*******************************************************************************
 ** space.hpp
 ** This is the header file for the class space and contains all the 
 ** declarations for the space class.
 ******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <vector>
#include <iostream>
#include "item.hpp"
#include "die.hpp"

using namespace std;

enum PLACE {gate,yard,battle,door};

class Space
{
    private:

        Item * item;
        string bossName;
        int bossHealthPoint;
        int dies;
        int sides;

    public:
        Space* next = nullptr;

        // Mutator Functions
        virtual void conversation(){}; 
        virtual string getType(){return "";};
        virtual ~Space();

        void setBossName(string);
        void setHealth(int health);
        void setItem(Item*);
        void setDies(int);
        void setSides(int);
        void bossBattleCry();
        
        // Accessor Functions
        string getBossName();
        int getHealth();
        int getMultiplier();
        int getDieSides();

        int attack();
        int defense();
        Item* getItem();
};

#endif