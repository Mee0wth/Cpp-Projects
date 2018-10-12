/*******************************************************************************
 ** helper.cpp
 ** This file contains all the helper functions such as input validation and
 ** anything the program needs to run.
 ******************************************************************************/
#include "helper.hpp"
#include <iostream>
#include <limits>
using namespace std;

void introText()
{
    cout << "Navi: Hey! " << endl;
    cout << "Navi: Link, wake up... " << endl;
    cout << "Press ENTER to continue..." << endl;
    cin.get();
    cin.get();

    cout << "Link sturs from his slumber... " << endl;
    cout << "Navi: Link, you've been alseep for almost 100 years " << endl;
    cout << "Navi: Do you remember what happend Link? " << endl;
    
    cout << "1. Yes " << endl;
    cout << "2. No " << endl;
    int choice1 = validateInteger(1,2);
    
    switch(choice1)
    {
        case 1:
        {
            cout << "Press ENTER to continue..." << endl;
            cin.get();
            cin.get();
   
            cout << "Navi: Great! We need to rescue Princess Zelda from Ganon. "
                 << endl;
            cout << "Navi: Link you must make your way through a series of locations. "
                 << endl;
            cout << "Navi: You must defeat the mini bosses and reach Ganon. " << endl;
            cout << "Navi: Ganon will be waiting for you at the last location. " 
                 << endl;
            
            cout << "Navi: Here are some things to keep in mind Link: " << endl;
            cout << "   1. Your health is at 50 percent because you've been " << endl;
            cout << "      asleep so long. You only have 1 life and cannot heal "
                 << endl;
            cout << "   2. Each boss drops an item with diffent stat enhacements. " 
                 << endl;
            cout << "   3. You must select carefully which item you " << endl;
            cout << "      would like to pick up. Although you can hold " << endl;
            cout << "      many items in your inventory, only the stats " << endl;
            cout << "      from the last item you pick up will be applied. " << endl;
              

            cout << "Navi: Go forth Link, and save the Princess. Good luck! " << endl;
            cout << "Press ENTER to continue..." << endl;
            cin.get();

            break;
        }
        case 2:
        {
            cout << "Press ENTER to continue..." << endl;
            cin.get();
            cin.get();

            cout << "Navi: You can't remember? " << endl;
            cout << "Navi: 100 years ago you were sealed away by Princess Zelda. "
                 << endl;
            cout << "Hyrule was on the brink of destruction. And now that you "
                 << endl;
            cout << "have awakened, you must defeat Ganon and rescue Zelda "
                 << endl;
            
            cout << "Navi: Link you must make your way through a series of locations "
                 << "you must defeat the mini bosses and reach Ganon." << endl;

            cout << "Navi: Ganon will be waiting for you at the last loation. " 
                 << endl;
            
            cout << "Navi: Here are some things to keep in mind Link: " << endl;
            cout << "   1. Your health is at 50 percent because you've been " << endl;
            cout << "      asleep so long. You only have 1 life and cannot heal "
            << endl;
            cout << "   2. Each boss drops an item with diffent stat enhacements. " 
            << endl;
            cout << "   3. You must select carefully which item you " << endl;
            cout << "      would like to pick up. Although you can hold " << endl;
            cout << "      many items in your inventory, only the stats " << endl;
            cout << "      from the last item you pick up will be applied. " << endl;
                

            cout << "Navi: Go forth Link, and save the Princess. Good luck! " << endl;
            cout << "Press ENTER to continue..." << endl;
            cin.get();
 
            break;
        }
    }

}

int endMenu()
{
    cout << "======> GAME OVER <====== " << endl;
    cout << "1. Play Again " << endl;
    cout << "2. Exit " << endl;
    
    int endChoice = validateInteger(1,2);

    switch(endChoice)
    {
        case 1:
        {
            return 1;
        }
        case 2:
        {
            return 0;
        }
    }
    return 0;
}

int validateInteger(int first, int second)
{
    int input = 0;
    while (!(cin >> input) || input < first || input > second)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Invalid input. Please pick between " << first << " and " << second;
        cout << endl;
    }
return input;
}

