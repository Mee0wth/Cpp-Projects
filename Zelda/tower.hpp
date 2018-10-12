/*******************************************************************************
 ** tower.hpp
 ** This is the declaration file for the class tower.
 ******************************************************************************/
#include "space.hpp"

#ifndef TOWER_HPP
#define TOWER_HPP

class Tower: public Space
{
   
    public:
        Tower();
        void conversation();
        string getType();
        ~Tower();
       
};
#endif