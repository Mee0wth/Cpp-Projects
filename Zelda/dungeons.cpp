/*******************************************************************************
 ** dungeons.cpp
 ** This is the implementation file for the class dungeons and contains all the 
 ** member variables and functions for dungeons.cpp
 ******************************************************************************/
#include "dungeons.hpp"
#include "cave.hpp"
#include "field.hpp"
#include "tower.hpp"
#include "castle.hpp"
#include "link.hpp"
#include <iostream>
#include <limits>
#include "helper.hpp"

using std::cout;
using std::endl;

Dungeons::Dungeons(Link* link)
{
    level = 1;
    this->link = link;
    
    // There are 6 Dungeons
    head = new Cave();
    head->next = new Cave();
    head->next->next = new Tower();
    head->next->next->next = new Field();
    head->next->next->next->next = new Cave();
    head->next->next->next->next->next = new Castle();
}

//game is over when link or finishes the game
bool Dungeons::isGameOver()
{
    return link->getHealth() <= 0 || getCurrentDungeon() == nullptr;
}

// Prints status of link
void Dungeons::printStatus()
{
    cout << "----------------LINK CURRENT STATS--------------------- " << endl;
    cout << "======================================================= " << endl;
    cout << "Link is currently at " << level << "th dungeon." << endl;
    cout << "The current dungeon is a " << getCurrentDungeonType() << endl;
    cout << endl;
    cout << "[Link's Current Status]: " << endl;
    cout << "   Health: " << link->getHealth() << endl;
    if (link->getItems().empty())
    {
        cout << "   Item: empty. " << endl;
    }
    else
    {
        cout << "   Item: "<< endl;
        for (unsigned i = 0; i < link->getItems().size(); i++)
        {
            cout << link->getItems().at(i)->getItemName() << endl;
        }
    }
    cout << "--------------------------------------------------------" << endl;
    cout << endl;
    cout << "Press ENTER to continue..." << endl;
    cin.get();
    
}


void Dungeons::intro()
{
    // link says random things 
    link->sayLinkStuff();
    cout << endl;
    link -> setCurrentPlace(PLACE::gate);
}

// moves link from gate to yard
void Dungeons::lookAtYard()
{
    getCurrentDungeon()->conversation();
    link -> setCurrentPlace(PLACE::yard);
}

//returns true if link won, false if link lost,
bool Dungeons::battles()
{
    link -> setCurrentPlace(PLACE::battle);

    //exchange damage until one of them dies
    cout << "BATTLE STATUS:" << endl;
    cout << "--------------" << endl;
    while (link->getHealth() > 0 && getCurrentDungeon()->getHealth() > 0)
    {
        int linkHealth = link->getHealth();
      
        if (!link->getItems().empty())
        {
            link->setDies(link->getItems().at(link->getItems().size()-1)->getMultiplier());
            link->setSides(link->getItems().at(link->getItems().size()-1)->getDieSides());
        }
    
        int linkAttack = link->attack();
        int linkDefence = link->defense();

        int dungeonHealth = getCurrentDungeon()->getHealth();
       

        int dungeonAttack = getCurrentDungeon()->attack();
        int dungeonDefence = getCurrentDungeon()->defense();

   
        cout << "   Link health: " << linkHealth << endl;
        cout << "   Link attack: " << linkAttack << endl;;
        cout << "   Link defense: " << linkDefence << endl;
        cout << getCurrentDungeon()->getBossName() << " health: " << dungeonHealth << endl;
        cout << getCurrentDungeon()->getBossName() << " attack: " << dungeonAttack << endl;
        cout << getCurrentDungeon()->getBossName() << " defense: " << dungeonDefence << endl;
        
        dungeonAttack -= linkDefence;
        if (dungeonAttack < 0)
        {
            dungeonAttack = 0;
        }
        linkAttack -= dungeonDefence;
        if (linkAttack < 0)
        {
            linkAttack = 0;
        }
        link->setHealth(linkHealth - dungeonAttack);
        getCurrentDungeon()->setHealth(dungeonHealth - linkAttack);
    }

    if (link->getHealth() > 0)
    {
        cout << "--------------" << endl;
        cout << endl;
        cout << "END BATTLE STATUS:" << endl;
        cout << "------------------" << endl;
        cout << endl;
        cout << getCurrentDungeon()->getBossName() << " died." << endl;
        // list out current item effect
        if (!link->getItems().empty())
        {
            cout << "Link's base multiplier is 1, with equipped item his multiplier is: " << link->getItems().at(link->getItems().size()-1)->getMultiplier() << endl;
            cout << "Link's base magic die has 4 sides, with equipped item his magic die has: " << link->getItems().at(link->getItems().size()-1)->getDieSides() << endl;
        }
        else
        {
            cout << "Link's base multiplier is 1" << endl;
            cout << "Link's base magic die has 4 sides, and he has no equipped item " << endl;
        }

        // link picks up item from the boss, user gets to ask if they want the item
        cout << getCurrentDungeon()->getBossName() << " dropped " << getCurrentDungeon()->getItem()->getItemName() << endl;
        cout << "It has the effect of adding multiplier: " << getCurrentDungeon()->getItem()->getMultiplier() << endl;
        cout << "And change the range of each magic die to: " << getCurrentDungeon()->getItem()->getDieSides() << endl;
        cout << "------------------" << endl;
        cout << endl;
        cout << "Would you like to pick up this item? " << endl;
        cout << "1. Pick up " << getCurrentDungeon()->getItem()->getItemName() << endl;
        cout << "2. Move on without equipping item " << endl;
        
        int pickUpItem = validateInteger(1,2);

        switch (pickUpItem)
        {
            case 1:
            {
                cout << "Link picked up " << getCurrentDungeon()->getItem()->getItemName() << endl;
                link->addItem(getCurrentDungeon()->getItem());
                break;
            }
            case 2:
            {
                cout << "The item was not picked up. " << endl;
                break;
            }
        }
        
        
    }
    else
    {
        cout << "Link died." << endl;
    }


    return link->getHealth() > 0;

}


bool Dungeons::promote()
{
    link -> setCurrentPlace(PLACE::door);
    level++;
    return true;
}

Space* Dungeons::getCurrentDungeon()
{
    int curr = 1;
    Space * dungeon = head;
    while (curr != level)
    {
        dungeon = dungeon->next;
        curr++;
    }

    return dungeon;
}

string Dungeons::getCurrentDungeonType()
{
    int curr = 1;
    Space * dungeon = head;
    while (curr != level)
    {
        dungeon = dungeon->next;
        curr++;
    }

    return dungeon->getType();
}

Dungeons::~Dungeons()
{
    delete link;

    vector<Space*> spaces;
    Space * curr = head;
    while (curr != nullptr)
    {
        spaces.push_back(curr);
        curr = curr->next;
    }
    for (unsigned i = 0; i < spaces.size(); i++)
    {
        delete spaces.at(i);
    }
    curr = nullptr;
}