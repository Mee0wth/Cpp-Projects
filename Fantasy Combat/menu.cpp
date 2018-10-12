/*******************************************************************************
 ** Menu.cpp
 ** This is the implementation file for the menu class and includes all the
 ** member variables and functions.
 ******************************************************************************/
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "harrypotter.hpp"
#include "medusa.hpp"
#include "menu.hpp"
#include "teamOne.hpp"
#include "teamTwo.hpp"
#include "deadTeam.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;



/******************************************************************************
 ** Menu Constructor
 *****************************************************************************/
Menu::Menu()
{
    oneLineup = new TeamOne;
    twoLineup = new TeamTwo;
    losers = new DeadTeam;
}

/******************************************************************************
 ** void start() 
 ** function starts tournament by asking user to play or exit. 
 *****************************************************************************/
void Menu::start()
{
     
    int menuChoice = 0;
    do{
        menuChoice = gameMenu();
       
        if (menuChoice == 1)
        {
            reset();
            displayMenu();
            combat();
        }
        else if (menuChoice == 3)
        {
            printLineUp();
        }
    }while (menuChoice != 2); 
        // exits game
    cout << "Exiting... " << endl;
}

void Menu::reset()
{
    round = 1;

    oneLineup = new TeamOne;
    twoLineup = new TeamTwo;
    losers = new DeadTeam;

    fighterOne = nullptr;
    fighterTwo = nullptr;
}
/******************************************************************************
 ** Display Menu to User
 *****************************************************************************/
void Menu::displayMenu()
{
    cout << "WELCOME TO FANTASY COMBAT TOURNAMENT " << endl;
    cout << "==================================== " << endl;

    cout << "Enter number of fighters for both teams (Max: 5): " << endl;

    int numFighters = validateIntegers(1,5);

    switch(numFighters)
    {   
        case 1:
        {
            // create one fighter for both teams
            chooseChar(1);
            cout << endl;
            chooseChar(2);
            break;
        }
        case 2:
        {
            // create two fighter for both teams
            int teamNum = 2;
            while (teamNum != 0)
            {
                chooseChar(1);
                chooseChar(2);
                teamNum--;
            }
            break;
           
        }
        case 3:
        {
            // create three fighter for both teams
            int teamNum = 3;
            while (teamNum != 0)
            {
                chooseChar(1);
                chooseChar(2);
                teamNum--;
            }
            break;
        }
        case 4:
        {
            // create four fighter for both teams
            int teamNum = 4;
            while (teamNum != 0)
            {
                chooseChar(1);
                chooseChar(2);
                teamNum--;
            }
            break;
        }
        case 5:
        {   
            // create five fighter for both teams
            int teamNum = 5;
            while (teamNum != 0)
            {
                chooseChar(1);
                chooseChar(2);
                teamNum--;
            }
            break;
        }
    }
}


/******************************************************************************
 ** Choose character type and set names for each character. Adds characters to 
 ** the lineup. 
 *****************************************************************************/
void Menu::chooseChar(int team)
{
    switch(team)
    {
        case 1:
        {
            // Create charactesr for team one
            cout << "Choose character for team 1: " << endl;
            cout << "1. Harry Potter " << endl;
            cout << "2. Medusa " << endl;
            cout << "3. Bluemen " << endl;
            cout << "4. Barbarian " << endl;
            cout << "5. Vampire " << endl;
      

            int fighter = validateIntegers(1,5);
            
            switch(fighter)
            {
                case 1:
                {
                    // add harry potter
                    cout << endl;
                    cout << "Please enter name for Harry Potter." << endl;
                    string name = validateString();
                    oneLineup->addCharacter(5, name);
                    break;
                    
                }
                case 2:
                {
                    // add Medusa 
                    cout << endl;
                    cout << "Please enter name for Medusa." << endl;
                    string name = validateString();
                    oneLineup->addCharacter(2, name);
                    break;
                }
                case 3:
                {
                    // add bluemen
                    cout << endl;
                    cout << "Please enter name for Bluemen." << endl;
                    string name = validateString();
                    oneLineup->addCharacter(4, name);
                    break;
                }
                case 4:
                {
                    // add Barbarian
                    cout << endl;
                    cout << "Please enter name for Barbarian." << endl;
                    string name = validateString();
                    oneLineup->addCharacter(3, name);
                    break;
                }
                case 5:
                {
                    // add Vampire
                    cout << endl;
                    cout << "Please enter name for Vampire." << endl;
                    string name = validateString();
                    oneLineup->addCharacter(1, name);
                    break;
                }

            }
            break;
        }
        case 2:        
        {
            // Create charactesr for team two
            cout << "Choose character for team 2: " << endl;
            cout << "1. Harry Potter " << endl;
            cout << "2. Medusa " << endl;
            cout << "3. Bluemen " << endl;
            cout << "4. Barbarian " << endl;
            cout << "5. Vampire " << endl;
      

            int fighter = validateIntegers(1,5);

            switch(fighter)
            {
                case 1:
                {
                    // add harry potter
                    cout << endl;
                    cout << "Please enter name for Harry Potter." << endl;
                    cout << endl;
                    string name = validateString();
                    twoLineup->addCharacter(5, name);
                    break;
                    
                }
                case 2:
                {
                    // add Medusa 
                    cout << endl;
                    cout << "Please enter name for Medusa." << endl;
                    cout << endl;
                    string name = validateString();
                    twoLineup->addCharacter(2, name);
                    break;
                }
                case 3:
                {
                    // add bluemen
                    cout << endl;
                    cout << "Please enter name for Bluemen." << endl;
                    cout << endl;
                    string name = validateString();
                    twoLineup->addCharacter(4, name);
                    break;
                }
                case 4:
                {
                    // add Barbarian
                    cout << endl;
                    cout << "Please enter name for Barbarian." << endl;
                    cout << endl;
                    string name = validateString();
                    twoLineup->addCharacter(3, name);
                    break;
                }
                case 5:
                {
                    // add Vampire
                    cout << endl;
                    cout << "Please enter name for Vampire." << endl;
                    cout << endl;
                    string name = validateString();
                    twoLineup->addCharacter(1, name);
                    break;
                }
            }
            break;
        }
    }
}

/******************************************************************************
 ** COMBAT: First in queue fights eachother
 *****************************************************************************/
void Menu::combat()
{
    // continue fight as long as there's fighters on the team's lineup
    while(!(oneLineup->isEmpty()) && !(twoLineup->isEmpty()))
    {
      	fighterOne = oneLineup->getPlayer();
        fighterTwo = twoLineup->getPlayer();
        while (fighterOne->isAlive() && fighterTwo->isAlive())
        {
               rounds();
        }
    }

    if (oneLineup->isEmpty())
    {
        cout << "TEAM 2 WINS!!" << endl;
    }
    else
    {
        cout << "TEAM 1 WINS!!" << endl;
    }
}
/******************************************************************************
 ** rounds() each round of attack
 *****************************************************************************/

void Menu::rounds()
{
    displayPreCombatStat();


    while (fighterOne->getStr() > 0 && fighterTwo->getStr() > 0)
    {
        // Player 1 attacks first
        fighterTwo->takeDmg(fighterOne->attack());
        // Player 2 counter attacks
        fighterOne->takeDmg(fighterTwo->attack());
    }

    if (fighterOne->getStr() <= 0)
    {
        cout << fighterTwo->getName() << " WINS! " << endl;
        displayResults(fighterTwo, fighterOne);
        
        // if fighter two wins, fighter two gets put back into team two lineup
        cNode* tempWin = twoLineup->removeCharacter();
        int roll = tempWin->character->rollDie(1,10); // each point is 10 percent
        cout << "Winner is recovering " << roll << "0 percent!" << endl;
        tempWin->character->setStr(tempWin->character->getStr()+roll);

        twoLineup->addCharBack(tempWin);

        // since fighter one lost, fighter one gets removed from team one line up
        // and put into loser pile
        cNode* tempLoser = oneLineup->removeCharacter();
        losers->addCharacter(tempLoser);
    }
    else if (fighterTwo->getStr() <=0)
    {
        cout << fighterOne->getName() << " WINS! " << endl;
        displayResults(fighterOne, fighterTwo);

        // if fighter one wins, fighter one gets put back into team one lineup
        cNode* tempWin = oneLineup->removeCharacter();
        int roll = tempWin->character->rollDie(1,10); // each point is 10 percent
        cout << "Winner is recovering " << roll << "0 percent!" << endl;
        tempWin->character->setStr(tempWin->character->getStr()+roll);

        oneLineup->addCharBack(tempWin);

         // since fighter two lost, fighter two gets removed from team two line up
        // and put into loser pile
        cNode* tempLoser = twoLineup->removeCharacter();
        losers->addCharacter(tempLoser);
    }
    round++;
    cout << "TEAM 1 LINEUP   ====>> ";
    oneLineup->printTeam();
    cout << "TEAM 2 LINEUP   ====>> ";
    twoLineup->printTeam();
    cout << endl;
}

/******************************************************************************
 ** displayPreCombatStats()
 ** displays player information before combat starts
 *****************************************************************************/
void Menu::displayPreCombatStat()
{
    // Displays precombat results
    cout << "==========>>> ROUND #" << round << " <<<==========" << endl;
    cout << fighterOne->getName() << "  (" << fighterOne->getType() << ")  "
         << "VS. " << fighterTwo->getName() << "  (" << fighterTwo->getType()
         << ")  "  << endl;
    cout << endl;
}

/******************************************************************************
 ** displayResults() : displays results of each round
 *****************************************************************************/

void Menu::displayResults(Character* winner, Character* loser)
{
    // Displays End Combat results 
    cout << "==========>>> END OF ROUND #" << round << "<<<==========" << endl;
    cout << winner->getName() << " WINS! (Gets put back into lineup.) " << endl;
    cout << loser->getName() << " LOST!  (Gets put into loser pile. ) " << endl;
    cout << endl;
    cout << endl;
}
/******************************************************************************
 ** clean() function cleans the game and resets it
 *****************************************************************************/
void Menu::clean()
{
    delete oneLineup;
    delete twoLineup;
    delete losers;
    round = 0;

  	oneLineup = nullptr;
  	twoLineup = nullptr;
    losers = nullptr;

    fighterOne = nullptr;
    fighterTwo = nullptr;
    
}

/******************************************************************************
 ** Validation Functions
 ** Integer Validation
 ** String Validation
 *****************************************************************************/
int Menu::validateIntegers(int first, int second)
{
    int input = 0;
    while (!(cin >> input) || input < first || input > second)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Invalid input. Please pick between " << first << " and " << second << endl;
    }
    return input;
}

string Menu::validateString()
{
    string name;

    while(!(cin >> name))
    {
        cout << "Please enter a valid name " << endl;
        cin >> name;
    }
    return name;
}

void Menu::printLineUp()
{
    // Displays each lineup
    cout << "TEAM 1 LINEUP   ====>> ";
    oneLineup->printTeam();
    cout << "TEAM 2 LINEUP   ====>> ";
    twoLineup->printTeam();
    cout << "DEFEATED LINEUP ====>> ";
    losers->printTeam();
}

/******************************************************************************
 ** endMenu() : end menu is displayed when first tournament is over to prompt
**              user if they'd like to exit or play again.
 *****************************************************************************/
int Menu::gameMenu()
{
    cout << "Fantasy Combat Menu " << endl;
    cout << "=================== " << endl;
    if (round != 1)
    {
        cout << "1. Play again" << endl;
        cout << "2. Exit the game" << endl;
        cout << "3. Print Lineup " << endl;
        return validateIntegers(1,3);
    }
    else 
    {
        cout << "Please select your choice: " << endl;
        cout << "1. Start Game " << endl;
        cout << "2. Exit " << endl;
        return validateIntegers(1,2);
    }
}


/******************************************************************************
 ** Menu Deconstructor 
 *****************************************************************************/
Menu::~Menu()
{
    clean();
}



