/*******************************************************************************
 ** dungeons.hpp
 ** This is the declaration file for the dungeons class
 ******************************************************************************/
#ifndef DUNGEONS_HPP
#define DUNGEONS_HPP

#include "link.hpp"
#include "space.hpp"
class Dungeons
{
    private:
        Link* link;
        Space* head;
        int level;

        Space* getCurrentDungeon();
    public:
        Dungeons(Link*);
        ~Dungeons();
        bool isGameOver();
        void printStatus();
        void intro();
        void lookAtYard();
        bool battles();
        bool promote();
        string getCurrentDungeonType();
};



#endif