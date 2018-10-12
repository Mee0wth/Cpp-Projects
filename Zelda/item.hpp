/*******************************************************************************
 ** items.hpp
 ** This is the declaration file for the items class
 ******************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
using std::string;
class Item 
{
    private:
        int dies;
        int sides;
        string name;
    public:
        Item(string,int,int);
        ~Item();
        string getItemName();
        int getMultiplier();
        int getDieSides();

};

#endif