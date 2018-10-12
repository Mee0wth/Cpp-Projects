/*******************************************************************************
 ** Author: Linda Carey
 ** Date:   06/01/18
 ** Program: This is a game where the player plays as Link from the franchise 
 **          Zelda. Link wakes up in a Dungeon where he's been asleep for 100
 **          years, and must now go through all the dungeons to resecue Zelda
 **          and beat the final boss Ganon. 
 ******************************************************************************/
#include <iostream>
#include <ctime>
#include "helper.hpp"
#include "link.hpp"
#include "dungeons.hpp"

using namespace std;


int main()
{
    srand(time(NULL));
    Link * player = nullptr;
    Dungeons * dungeons = nullptr;

    /*
                                       /@
                       __        __   /\/
                      /==\      /  \_/\/   
                    /======\    \/\__ \__
                  /==/\  /\==\    /\_|__ \
               /==/    ||    \=\ / / / /_/
             /=/    /\ || /\   \=\/ /     
          /===/   /   \||/   \   \===\
        /===/   /_________________ \===\
     /====/   / |                /  \====\
   /====/   /   |  _________    /  \   \===\    THE LEGEND OF 
   /==/   /     | /   /  \ / / /  __________\_____      ______       ___
  |===| /       |/   /____/ / /   \   _____ |\   /      \   _ \      \  \
   \==\             /\   / / /     | |  /= \| | |        | | \ \     / _ \
   \===\__    \    /  \ / / /   /  | | /===/  | |        | |  \ \   / / \ \
     \==\ \    \\ /____/   /_\ //  | |_____/| | |        | |   | | / /___\ \
     \===\ \   \\\\\\\/   /////// /|  _____ | | |        | |   | | |  ___  |
       \==\/     \\\\/ / //////   \| |/==/ \| | |        | |   | | | /   \ |
       \==\     _ \\/ / /////    _ | |==/     | |        | |  / /  | |   | |
         \==\  / \ / / ///      /|\| |_____/| | |_____/| | |_/ /   | |   | |
         \==\ /   / / /________/ |/_________|/_________|/_____/   /___\ /___\
           \==\  /               | /==/
           \=\  /________________|/=/    
             \==\     _____     /==/ 
            / \===\   \   /   /===/
           / / /\===\  \_/  /===/
          / / /   \====\ /====/
         / / /      \===|===/
         |/_/         \===/
                        =  

*/
    
    cout << "===============================" << endl;
    cout << "=           ZELDA             =" << endl;
    cout << "===============================" << endl;

    cout << "1. Play Game " << endl;
    cout << "2. Exit "  << endl;
    int gameChoice = validateInteger(1,2);
    
    while (gameChoice == 1)
    {
        switch(gameChoice)
        {
            case 1:
            {
                player = new Link();
                dungeons = new Dungeons(player);
                introText();  
                while (!dungeons->isGameOver())
                {
                    // Prints information at the start of stage
                    dungeons->printStatus(); 
                    // dungeon intro text
                    dungeons->intro(); 
                    // moves link from gate to yard
                    dungeons->lookAtYard();
                    //this moves link form yard to battle field, this is when link did something to trigger boss
                    
                    cout << "Link enters battle field." << endl;
                    cout << "1. Link's Status" << endl;
                    cout << "2. Link's Inventory" << endl;
                    cout << "3. Into the battle" << endl;
                    int userBattleInfo = validateInteger(1,3);
                    while (userBattleInfo != 3)
                    {
                        if (userBattleInfo == 1)
                        {
                            cout << "[Link's Current Status]: " << endl;
                            cout << "   Health: " << player->getHealth() << endl;
                            cout << "   Location: " << dungeons->getCurrentDungeonType() << endl;
                        }
                        else if (userBattleInfo == 2)
                        {
                            if (player->getItems().empty())
                            {
                                cout << "   Item: empty. " << endl;
                            }
                            else
                            {
                                cout << "   Item: "<< endl;
                                for (unsigned i = 0; i < player->getItems().size(); i++)
                                {
                                    cout << player->getItems().at(i)->getItemName() << endl;
                                }
                            }
                        }
                        cout << "Link enters battle field." << endl;
                        cout << "1. Link's Status" << endl;
                        cout << "2. Link's Inventory" << endl;
                        cout << "3. Into the battle" << endl;     
                        userBattleInfo = validateInteger(1,3);
                    }

                    if (dungeons->battles()) 
                    {
                    // returns true if link won, false if link lost, 
                    // prints out details of battle and takes link to next dungeon
                    dungeons->promote(); 
                    }
                }
                if (player->getHealth() > 0)
                {
                    cout << "Link has defeated Ganon and rescued Zelda" << endl;
                }
                gameChoice = endMenu();
                break;
            }
            case 2:
            {
                cout << "Exiting Game... " << endl;
                break;
            }  
        } 
    }
    delete player;
    delete dungeons;
    player = nullptr;
    dungeons = nullptr;

    return 0;
}
 
/*******************************************************************************
 ** CITATION:
 ** Zelda Ascii Shield
 ** https://www.zeldaxtreme.com/ascii-art/
 ******************************************************************************/
