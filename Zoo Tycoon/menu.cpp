/******************************************************************************
 ** Menu Class
 ** This is the menu class implementation file that contains all the 
 ** definitions for menu class. 
 * ****************************************************************************/
#include "menu.hpp"
#include "zoo.hpp"
#include "tiger.hpp"
#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;

Menu::Menu(Zoo &passZoo)
{
    zooPtr = &passZoo;
}

void Menu::start()
{
    dayOne();
    
    while(!zooPtr->gameIsOver())
    {
        zooPtr->incrementDay();
    }
    cout << "GAME OVER" << endl;
}

void Menu::dayOne()
{
    int numOfTigers,
    numOfPenguins,
    numOfTurtles;

    cout << "==== WELCOME TO ZOO TYCOON ==== " << endl;
    cout << "=============================== " << endl;
    cout << "DAY: " << zooPtr->getDay() << endl;
    cout << "=============================== " << endl;
    cout << "BEGINNING CASH: $" << zooPtr->getCash() << endl;
    cout << "=============================== " << endl;
    cout << endl;
    cout << "To start your own Zoo, please choose three zoo animals to purchase."
         << endl;

    cout << "==  ZOO ANIMALS FOR PURCHASE ==" << endl;
    cout << "1. Tiger: " << endl;
    cout << "\tPrice: $" << Tiger().getCost() << endl;
    cout << "\tQuantity: 2" << endl;

    cout << "2. Penguin: " << endl;
    cout << "\tPrice: " << Penguin().getCost() << endl;
    cout << "\tQuantity: 2" << endl;

    cout << "3. Turtle: " << endl;
    cout << "\tPrice: " << Turtle().getCost()  << endl;
    cout << "\tQuantity: 2" << endl;

    // Pick how many Tigers
    cout << "How many Tigers would you like to purchase? " << endl;
    numOfTigers = inputValidate(0,2);
    while (numOfTigers > 0){
        zooPtr->addTiger(Tiger(1));
        numOfTigers--;
    }

    // Pick how many Penguins
    cout << "How many Penguins would you like to purchase? " << endl;
    numOfPenguins = inputValidate(0,2);
    while (numOfPenguins > 0){
        zooPtr->addPenguin(Penguin(1));
        numOfPenguins--;
    }
    // Pick how many Turtles
    cout << "How many Turtles would you like to purchase? " << endl;
    numOfTurtles = inputValidate(0,2);
    while (numOfTurtles > 0){
        zooPtr->addTurtle(Turtle(1));
        numOfTurtles--;
    }

    zooPtr->printStatus();

}

int Menu::inputValidate(int x, int y)
{
    int choice;
    cin >> choice;
    
    while(std::cin.fail() || (choice < x || choice > y))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Invalid input. Please pick 1 or 2. ";
        cin >> choice;
    }
    return choice;
}

Menu::~Menu()
{
    zooPtr = nullptr;
}