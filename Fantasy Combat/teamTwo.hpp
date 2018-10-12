/*******************************************************************************
 ** teamTwo.hpp
 ** This is the header file for the teamTwo class and includes all the 
 ** declarations for teamTwo.cpp
 ******************************************************************************/
 #ifndef TEAMTWO_HPP
 #define TEAMTWO_HPP
 #include "character.hpp"
 #include "cNode.hpp"
 #include <string>
 using std::string;
 

class TeamTwo 
{
    private:
        cNode* head;
        cNode* tail;


    public:
        TeamTwo();
        bool isEmpty();
        void addCharacter(int charType, string Name);
        Character* getPlayer();
        cNode* removeCharacter();
        void addCharBack(cNode* winner);
        void printTeam();
        ~TeamTwo();
};

 #endif