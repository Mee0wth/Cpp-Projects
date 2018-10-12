/*******************************************************************************
 ** deadTeam.cpp
 ** This is the implementation file for the deadTeam class and includes all the
 ** member variables and functions.
 ******************************************************************************/
#include "deadTeam.hpp"
#include "character.hpp"
#include "teamOne.hpp"
#include "teamTwo.hpp"
#include "cNode.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/******************************************************************************
 ** DeadTeam Constructor
 **         Sets head and tail = null
 *****************************************************************************/
DeadTeam::DeadTeam()
{
    head = nullptr;
    tail = nullptr;
}
/******************************************************************************
** bool isEmpty()
**         Checks to see if team is empty. Empty if head == nullptr;
**         Returns a true or false.
 *****************************************************************************/
bool DeadTeam::isEmpty()
{
    if (head == nullptr)
        return true;
    else
        return false;
}

/******************************************************************************
** addCharacter function adds the character who lost to the DeadTeam queue 
*****************************************************************************/
void DeadTeam::addCharacter(cNode* deadChar)
{
    if (isEmpty())
    {
        // if the team is empty ( head == null ), then add the first character
        // and set head and tail equal to character node
        head = deadChar;
        tail = head;

        // double linked queue, set head and tail (next,prev) to point to 
        // eachother
        head->prev = tail;
        head->next = tail;
        tail->prev = head;
        tail->next = head;
    } 
    else
    {
        cNode* tempChar = deadChar;
        tempChar->prev = tail;
        tempChar->next = head;
        head->prev = tempChar;
        tail->next = tempChar;
        tail = tempChar;
    }
}

/******************************************************************************
** printTeam function traverses the character nodes and prints loser team
*****************************************************************************/
void DeadTeam::printTeam()
{
   if (isEmpty())
   {
       cout << "Empty... " << endl;
   }
   else
   {
        // print until we hit head again
        cNode * curr = head;
        cout << curr->character->getName() << "  ";
        curr = curr->next;

        while (curr != head)
        {
            cout << curr->character->getName() << "  ";
            curr = curr->next;       
        }
        cout << endl;
   }

}

/******************************************************************************
** ~DeadTeam deconstructor deletes character nodes and sets pointers to nullptr
*****************************************************************************/

DeadTeam::~DeadTeam()
{
    // while the team is not empty delete character nodes
    while (!isEmpty())
    {
        // if only character node, delete node
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            cNode* tempDelete = head;

            head = head->next;
            tail = head->prev;
            head = tail->next;
            delete tempDelete;

            head = nullptr;
            tail = nullptr;
        }
    }
}

