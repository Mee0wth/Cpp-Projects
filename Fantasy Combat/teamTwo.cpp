/*******************************************************************************
 ** teamTwo.cpp
 ** This is the implementation file for the teamTwo class and includes all the
 ** member variables and functions.
 ******************************************************************************/
#include "teamTwo.hpp"
#include "character.hpp"
#include "cNode.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/******************************************************************************
 ** TeamTwo Constructor: 
 **         Sets head and tail = null
 *****************************************************************************/
TeamTwo::TeamTwo()
{
    head = nullptr;
    tail = nullptr;
}
/******************************************************************************
** bool isEmpty()
**         Checks to see if team is empty. Empty if head == nullptr;
**         Returns a true or false.
 *****************************************************************************/
bool TeamTwo::isEmpty()
{
    if (head == nullptr)
        return true;
    else
        return false;
}

/******************************************************************************
** addCharacter function adds character to the tail in a queue like structure
** where characters will also be taken from the front of the queue to fight.
*****************************************************************************/
void TeamTwo::addCharacter(int charType, string name)
{
    if (isEmpty())
    {
        // if the team is empty ( head == null ), then add the first character
        // and set head and tail equal to character node
        head = new cNode(charType, name);
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
        cNode* tempChar = new cNode(charType, name);
        tempChar->prev = tail;
        tempChar->next = head;
        head->prev = tempChar;
        tail->next = tempChar;
        tail = tempChar;
    }
}

/******************************************************************************
** getPlayer() function gets the player from the front of the queue to fight.
*****************************************************************************/
Character* TeamTwo::getPlayer()
{
    if (isEmpty())
    {
        return nullptr;
    }
    else
    {
        return head->character;
    }
}

/******************************************************************************
** removeCharacter function removes a character from the front of the queue 
** when it has fought opponent and died. 
*****************************************************************************/
cNode* TeamTwo::removeCharacter()
{
    if (isEmpty())
    {
        cout << "There are no characters to remove from this lineup. " << endl;
        return nullptr;
    }
    else if (head != tail)
    {
        cNode* removeChar = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        return removeChar;
    }
    else
    {
        cNode* removeChar = head;
        head->next = nullptr;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = nullptr;
        head = nullptr;

        return removeChar;
    }
}

/******************************************************************************
** addCharBack function takes the winning character and puts it at the back
** of the queue.
*****************************************************************************/
void TeamTwo::addCharBack(cNode* winner)
{
    if (isEmpty())
    {
        head = winner;
        tail = head;

        tail->prev = head;
        tail->next = head;
        head->next = tail;
        head->prev = tail;
    }
    else
    {
        // adds character back into the list
        // make sure to account percentage of life back
        tail->next = winner;
        winner->prev = tail;
        head->prev = winner;
        winner->next = head;
        tail = winner;
    }
}

/******************************************************************************
** printTeam function traverses the character nodes and prints each character
** within the lineup.
*****************************************************************************/
void TeamTwo::printTeam()
{
   if (isEmpty())
   {
       cout << "This are no members on this team. " << endl;
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
** ~TeamOne deconstructor deletes character nodes and sets pointers to nullptr
*****************************************************************************/

TeamTwo::~TeamTwo()
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

