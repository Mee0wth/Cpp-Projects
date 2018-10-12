/******************************************************************************
 ** Program: Zoo Tycoon
 ** Author: Linda Carey
 ** Date: 04/23/18
 ** Description: This program allows players to run a zoo business where 
 ** different types of animals have different costs, maintienance costs, and 
 ** return on profits. The program uses classes and inheritence to simulate 
 ** running a zoo. 
 * ****************************************************************************/
#include "zoo.hpp"
#include "menu.hpp"

int main()
{
    // Create Zoo object and pass it to menu function
    Zoo zooTycoon;
    
    // Day one set thing sup
    Menu(zooTycoon).start();
    
}