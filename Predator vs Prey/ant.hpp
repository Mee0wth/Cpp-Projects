/*******************************************************************************
 ** Ant Class
 **     This is the header file for the ant class and contains all the
 **     declarations for ant.cpp
 ******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "critter.hpp"


class Ant : public Critter 
{
    private:


    public:
        Ant(Critter*** boardState, int boardSizeRow, int boardSizeCol, int currentDay);

        int getSquareState(const Critter** critterHolder, int inRow, int inCol);

        void move(int, int*, int, int);
        
        void breed(int, int*, int, int);
};
#endif