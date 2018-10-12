/*******************************************************************************
 ** deadTeam.hpp
 ** This is the header file for the deadTeam class and includes all the 
 ** declarations for deadTeam.cpp
 ******************************************************************************/
 #ifndef DEADTEAM_HPP
 #define DEADTEAM_HPP
 #include "character.hpp"
 #include "cNode.hpp"
 #include <string>
 using std::string;
 

class DeadTeam
{
    private:
        cNode* head;
        cNode* tail;


    public:
        DeadTeam();
        bool isEmpty();
        void addCharacter(cNode* deadChar);
        void printTeam();
       ~DeadTeam();
};

 #endif