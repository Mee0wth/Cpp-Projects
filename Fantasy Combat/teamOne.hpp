/*******************************************************************************
 ** teamOne.hpp
 ** This is the header file for the teamOne class and includes all the 
 ** declarations for teamOne.cpp
 ******************************************************************************/
 #ifndef TEAMONE_HPP
 #define TEAMONE_HPP
 #include "character.hpp"
 #include "cNode.hpp"
 #include <string>
 using std::string;
 

class TeamOne 
{
    private:
        cNode* head;
        cNode* tail;


    public:
        TeamOne();
        bool isEmpty();
        void addCharacter(int charType, string Name);
        Character* getPlayer();
        cNode* removeCharacter();
        void addCharBack(cNode* winner);
        void printTeam();
        ~TeamOne();
};

 #endif