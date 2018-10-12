/*******************************************************************************
 ** field.hpp
 ** This is the declaration file for the class field.
 ******************************************************************************/
#include "space.hpp"

#ifndef FIELD_HPP
#define FIELD_HPP

class Field: public Space
{
   
    public:
        Field();
        void conversation();
        string getType();
        ~Field();
       
};
#endif