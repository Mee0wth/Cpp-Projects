/*******************************************************************************
 ** cNode.cpp
 ** Implementation file for the cNode struct that includes definitions for 
 ** member variable and member functions.
 ******************************************************************************/
#include "cNode.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "medusa.hpp"
#include "bluemen.hpp"
#include "harrypotter.hpp"
#include "barbarian.hpp"
#include <string>

using std::string;

/*******************************************************************************
 ** cNode Constructor
 ** Everytime a new node is constructed we need to pass in the type of character
 ** to be created and the name. 
 ******************************************************************************/
cNode::cNode(int charType, string name)
{    
    prev = nullptr;
    next = nullptr;
    switch(charType)
    {
        case 1:
        {
            character = new Vampire();
            character->setName(name);
            break;
        }
        case 2:
        {
            character = new Medusa();
            character->setName(name);
            break;
        }
        case 3:
        {
            character = new Barbarian();
            character->setName(name);
            break;
        }
        case 4:
        {
            character = new Bluemen();
            character->setName(name);
            break;
        }
        case 5:
        {
            character = new HarryPotter();
            character->setName(name);
            break;
        }
    }
}

/*******************************************************************************
 ** cNode Deconstructor
 ** Deletes the character 
 ******************************************************************************/

cNode::~cNode()
{
    delete character;
    character = nullptr;
}