/*******************************************************************************
 ** cave.hpp
 ** This is the declaration file for the cave.cpp
 ******************************************************************************/
#include "space.hpp"

#ifndef CAVE_HPP
#define CAVE_HPP

class Cave: public Space
{
    public:
        Cave();
        void conversation();
        string getType();
        ~Cave();
};

#endif