/******************************************************************************
 ** Zoo Class
 ** This is the zoo class header file that contains all the member variables
 ** and function declarations for zoo.cpp
 * ****************************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

class Zoo 
{
    private:
        int day,
            playerCash,
            bonus;

        int numOfTigers,
            numOfPenguins,
            numOfTurtles;

        bool gameOver = false;

        Tiger* tigPtr = nullptr;
        Penguin* penPtr = nullptr;
        Turtle* turPtr = nullptr;

        
    
    public:
        // Default Constructor
        Zoo();

        // Accessor 
        int getCash() const;
        int getDay() const;
        int getTigers() const;
        int getPenguins() const;
        int getTurtles() const;

        int getArraySize(int); //this returns the proper array size given animal size it would be handling
        bool arrayResizeNeeded(int);
        void printStatus();

        // Mutators
        bool gameIsOver();
        void incrementDay();
        void sickAnimal();
        void makeBaby();
        void boomZooAttd();
        void purchaseAnimal();
        //void addAnimal(int animal);
        void addTiger(Tiger);
        bool killTiger();

        void addPenguin(Penguin);
        bool killPenguin();

        void addTurtle(Turtle);
        bool killTurtle();

        int endDayProfit();
        void randEvent();

        // Deconstructor 
        ~Zoo();
    
};



#endif