/******************************************************************************
 ** Menu Class
 ** This is the menu class header file that contains all the member variables
 ** and function declarations for menu.cpp
 * ****************************************************************************/
#include "zoo.hpp"
#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
    private:
        Zoo* zooPtr = nullptr;

    public:
        Menu(Zoo &passZoo);
        int inputValidate(int min, int max);
        void start();
        void dayOne();
        ~Menu();


};




#endif