/*******************************************************************************
 ** castle.hpp
 ** This is the declaration file for the class castle
 ******************************************************************************/
#include "space.hpp"

#ifndef CASTLE_HPP
#define CASTLE_HPP

class Castle: public Space
{
    private:
    public:
        Castle();
        void conversation();
        string getType();
        ~Castle();
};

#endif