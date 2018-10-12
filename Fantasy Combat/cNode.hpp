/*******************************************************************************
 ** cNode.hpp 
 ** This header file creates a struct with a pointer to a character and pointers
 ** to each character node. The declarations will be provided below:
 ******************************************************************************/
#ifndef CNODE_HPP
#define CNODE_HPP
#include "character.hpp"
#include <string>

using std::string;

struct cNode 
{
    public:
        Character* character;
        cNode* prev;
        cNode* next;
        // cNode constructor constructs a chracter node
        cNode(int charType, string name);
        // cNode deconstructor deconstructs character node
        ~cNode();
};
#endif