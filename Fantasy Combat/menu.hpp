/*******************************************************************************
 ** Menu.hpp
 ** This is the header file for the menu class and includes all the declarations
 ** for menu.cpp. 
 ******************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include "character.hpp"
#include "teamOne.hpp"
#include "teamTwo.hpp"
#include "deadTeam.hpp"

class Menu 
{
    private:
        TeamOne* oneLineup;
        TeamTwo* twoLineup;
        DeadTeam* losers;
        Character* fighterOne;
        Character* fighterTwo;

        int round = 1;


    public:
        Menu();
        void start();
        void displayMenu();
        void chooseChar(int);
        void makeChar(int, int);
        void combat();
        void rounds();
        void displayPreCombatStat();
        void displayResults(Character* winner, Character* loser);
        void clean();
        void reset();
        void printLineUp(); 
        int gameMenu();

        int validateIntegers(int, int);
        string validateString();

        ~Menu();

        

};

#endif 
