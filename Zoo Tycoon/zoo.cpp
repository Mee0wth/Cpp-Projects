/******************************************************************************
 ** Zoo Class
 ** This is the zooclass implementation file that contains all the 
 ** definitions for zoo class. 
 * ****************************************************************************/
#include "zoo.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

using std::cout;
using std::endl;
using std::cin;


Zoo::Zoo()
{
    srand(time(NULL));
    playerCash = 100000;
    bonus = 0;
    day = 0;

    numOfTigers = 10;
    numOfPenguins = 10;
    numOfTurtles = 10;
    
    tigPtr = new Tiger[numOfTigers];
    penPtr = new Penguin[numOfPenguins];
    turPtr = new Turtle[numOfTurtles];
}

// Mutators
int Zoo::endDayProfit()
{
    int tigProfit = 0,
        penProfit = 0,
        turProfit = 0,
        totalProfit = 0;

    for(int i = 0; i < numOfTigers; i++)
    {
        if (tigPtr[i].getAge()!= -1)
        {
            tigProfit += (tigPtr[i].getRevenue());
        }
    }

    for (int i = 0; i < numOfPenguins; i++)
    {
        if (penPtr[i].getAge() != -1)
        {
            penProfit += penPtr[i].getRevenue();

        }
    }

    for (int i = 0; i < numOfTurtles; i++)
    {
        if (turPtr[i].getAge() != -1)
        {
            turProfit += turPtr[i].getRevenue();
        }
    }

    totalProfit = (tigProfit + penProfit + turProfit);
    playerCash += totalProfit;
    
    return totalProfit;
 
}

void Zoo::incrementDay()
{
    int profit = 0;
    // Tigers turn 1 day older / subtract Tiger feed
    for(int i = 0; i < numOfTigers; i++)
    {
        if (tigPtr[i].getAge()!= -1)
        {
            tigPtr[i].setAge(tigPtr[i].getAge()+ 1 );
            playerCash -= tigPtr[i].getFoodCost();
        }
    }

    // Penguins turn one day older / sub penguin feed
    for (int i = 0; i < numOfPenguins; i++)
    {
        if (penPtr[i].getAge() != -1)
        {
            penPtr[i].setAge(penPtr[i].getAge() + 1);
            playerCash -= penPtr[i].getFoodCost();
        }
    }

    // Turtle turns one day older / sub turtle feed
    for (int i = 0; i < numOfTurtles; i++)
    {
        if (turPtr[i].getAge() != -1)
        {
            turPtr[i].setAge(turPtr[i].getAge() + 1);
            playerCash -= turPtr[i].getFoodCost();
        }
    }

    randEvent();

    // Calcuate Profits for the day 
    profit = endDayProfit() + bonus;
    cout << "===============================" << endl;
    cout << "END DAY REVENUE: $" << profit << endl;
    cout << "===============================" << endl;
    bonus = 0;
    
    cout << "CURRENT CASH: $" << getCash() << endl;
    cout << "===============================" << endl;
    purchaseAnimal();

    int choice = 0;
    cout << "Would you like to continue this game?" << endl;
    cout << "\t1. Continue" << endl;
    cout << "\t2. End Game" << endl;
    while( !(cin >> choice) || choice > 2 || choice < 1)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Invalid input. Please pick 1 or 2. ";
        cin >> choice;
    }
    if (choice == 2)
    {
        gameOver = true;
        return;
    }
    printStatus();

}

void Zoo::purchaseAnimal()
{
    int choice = 0;
    int aniChoice = 0;

    cout << "Would you like to purchase an adult animal? " << endl;
    cout << "1. Yes " << endl;
    cout << "2. No " << endl;
    while(!(cin >> choice) || (choice < 1 || choice > 2))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Invalid input. Please pick 1 or 2. ";
        cin >> choice;
    }

    if (choice == 1)
    {
        cout << "Which of the three would you like to purchase: " << endl;
        cout << "1. Tiger: \t$" << Tiger().getCost() << endl;
        cout << "2. Penguin: \t$" << Penguin().getCost() << endl;
        cout << "3. Turtle: \t$" << Turtle().getCost() << endl;
        cout << "4. I changed my mind." << endl;
      
        while(!(cin >> aniChoice) || (aniChoice < 1 || aniChoice > 4))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Invalid input. Please choose an intger between 1-4" << endl;
            cin >> aniChoice;
        }

        switch (aniChoice)
        {
            case 1:
            {
                addTiger(Tiger(3));
                cout << "A tiger has been purchased. " << endl;
                break;
            }
            case 2:
            {
                addPenguin(Penguin(3));
                cout << "A penguin has been purchased. " << endl;
                break;
            }
            case 3:
            {
                addTurtle(Turtle(3));
                cout << "A turtle has been purhased. " << endl;
                break;
            }
            case 4:
            {
                break;
            }
        }
       
    }
    else
    {
        cout << "Not purchasing any animal today, moving on..." << endl;
        return;
    }

}

void Zoo::addTiger(Tiger tiger)  
{
    //count animals in the arrays
    if ((getTigers()+1) > numOfTigers){
        //we get too many animal and need to move things over. 
        Tiger * temp = new Tiger[numOfTigers];
        for (int i = 0; i < numOfTigers; i++)
        {
            temp[i] = tigPtr[i];
        }

        delete[] tigPtr;

        //make tigPtr double sized.
        int oldNum = numOfTigers;
        numOfTigers *= 2;
        tigPtr = new Tiger[numOfTigers];

        for (int i = 0; i < oldNum; i++)
        {
            tigPtr[i].setAge(temp[i].getAge());
        }
        cout << "Tiger pool has expanded, now we can hold up to " << numOfTigers << " Tigers." << endl;

    }

    for (int i = 0; i < numOfTigers; i++)
    {
        if (tigPtr[i].getAge() == -1)
        {
            tigPtr[i] = tiger;
            break;
        }
    }
    playerCash -= Tiger().getCost();
}


void Zoo::addPenguin(Penguin penguin)
{
    if ((getPenguins()+1) > numOfPenguins){
        //we get too many animal and need to move things over. 
        Penguin * temp = new Penguin[numOfPenguins];
        for (int i = 0; i < numOfPenguins; i++)
        {
            temp[i] = penPtr[i];
        }

        delete[] penPtr;

        //make penPtr double sized.
        int oldNum = numOfPenguins;
        numOfPenguins *= 2;
        penPtr = new Penguin[numOfPenguins];

        for (int i = 0; i < oldNum; i++)
        {
            penPtr[i].setAge(temp[i].getAge());
        }
        cout << "Penguin pool has expanded, now we can hold up to " << numOfPenguins << " Penguins." << endl;
    }

    for (int i = 0; i < numOfPenguins; i++)
    {
        if (penPtr[i].getAge() == -1)
        {
            penPtr[i] = penguin;
            break;
        }
    }
    playerCash -= Penguin().getCost();
}


void Zoo::addTurtle(Turtle turtle)
{
    if ((getTurtles()+1) > numOfTurtles){
        //we get too many animal and need to move things over. 
        Turtle * temp = new Turtle[numOfTurtles];
        for (int i = 0; i < numOfTurtles; i++)
        {
            temp[i] = turPtr[i];
        }

        delete[] turPtr;

        //make turPtr double sized.
        int oldNum = numOfTurtles;
        numOfTurtles *= 2;
        turPtr = new Turtle[numOfTurtles];

        for (int i = 0; i < oldNum; i++)
        {
            turPtr[i].setAge(temp[i].getAge());
        }
        cout << "Turtle pool has expanded, now we can hold up to " << numOfTurtles << " Turtles." << endl;
    }
    for (int i = 0; i < numOfTurtles; i++)
    {
        if (turPtr[i].getAge() == -1)
        {
            turPtr[i] = turtle;
            break;
        }
    }  
    playerCash -= Turtle().getCost();
}

// function kills rand animal from array and reconstructs array
bool Zoo::killTiger()
{
    for (int i = 0; i < numOfTigers; i++)
    {
        if (tigPtr[i].getAge() != -1)
        {
            tigPtr[i] = Tiger();
            cout << "A Tiger has died" << endl;
            cout << "There are now " << getTigers() << " Tigers." << endl;
            return true;
            break;
        }
        
    }
    return false;
}

bool Zoo::killPenguin()
{
    for (int i = 0; i < numOfPenguins; i++)
    {
        if (penPtr[i].getAge() != -1)
        {
            penPtr[i] = Penguin();
            cout << "A Penguin has died" << endl;
            cout << "There are now " << getPenguins() << " Penguins." << endl;
            return true;
            break;
        }
    }
    return false;
}

bool Zoo::killTurtle()
{
    for (int i = 0; i < numOfTurtles; i++)
    {
        if (turPtr[i].getAge() != -1)
        {
            turPtr[i] = Turtle();
            cout << "A Turtle has died" << endl;
            cout << "There are now " << getTurtles() << " Turtles." << endl;
            return true;
            break;
        }
    }
    return false;
}


void Zoo::sickAnimal()
{
    int randAnimal = 0;
    randAnimal = rand() % 3;

    cout << "RAND EVENT: " << "An Animal is Sick. " << endl;
    cout << "===============================" << endl;
    switch(randAnimal)
    {
        case 0:
        {
            // kill Tiger
            if (killTiger())
            {
                break;
            }
            else
            {
                cout << "A sickness targeting Tigers swept through your zoo " 
                     << endl;
                cout << "Thankfully you have no Tigers, so you were not affected"
                     << endl;
                break;
            }
        }
        case 1:
        {
            // Kill Penguin
            if (killPenguin())
            {
                break;
            }
            else
            {
                cout << "A sickness targeting Penguins swept through your zoo " 
                     << endl;
                cout << "Thankfully you have no Penguins, so you were not affected"
                     << endl;
                break;
            }
        }
        case 2:
        {
            // Kill Turtle 
            
            if (killTurtle())
            {
                break;
            }
            else
            {
                cout << "A sickness targeting Turtles swept through your zoo " 
                     << endl;
                cout << "Thankfully you have no Turtles, so you were not affected"
                     << endl;
                break;
            }
        }
    }
}

void Zoo::makeBaby()
{
    int randBaby = 0;
    randBaby = rand() % 3;

    cout << "RAND EVENT: " << "A birth is taking place! " << endl;
    cout << "===============================" << endl;
    switch(randBaby)
    {
        case 0:
        {
            // look for a >3 year old tiger
            bool oldEnough = false;
            for (int i = 0; i < numOfTigers; i++)
            {
                if (tigPtr[i].getAge() >= 3)
                {
                    oldEnough = true;
                }
            }
            // Tiger one baby
            if (oldEnough)
            {
                addTiger(Tiger(0));
                cout << "A Tiger baby has been born. " << endl;
                break;
            }

        }
        case 1:
        {
            // look for a >3 year old Penguin
            bool oldEnough = false;
            for (int i = 0; i < numOfPenguins; i++)
            {
                if (penPtr[i].getAge() >= 3)
                {
                    oldEnough = true;
                }
            }
            // Penguins have 5 babys

            if (oldEnough)
            {
                int i = 5;
                while (i > 0)
                {
                    addPenguin(Penguin(0));
                    cout << "A Penguin baby has been born. " << endl;
                    i--;
                }
                break;
            }

        }
        case 2:
        {
            // look for a >3 year old Penguin
            bool oldEnough = false;
            for (int i = 0; i < numOfTurtles; i++)
            {
                if (turPtr[i].getAge() >= 3)
                {
                    oldEnough = true;
                }
            }
            if (oldEnough)
            {
                int i = 10;
                while (i > 0)
                {
                    addTurtle(Turtle(0));
                    cout << "A Turtle baby has been born. " << endl;
                    i--;
                }
                // Turtles have 10 babys
                break;
            }

        }
        case 4:
            cout << "There are no animal of that type that is "
                 << "older than 3 days old." << endl;
    }
   

}

void Zoo::boomZooAttd()
{
    int min = 250,
        max = 500;
    int randBonus = 0;
    int count = 0;

    randBonus = rand() % (max-min + 1) + min;
    
    cout << "RAND EVENT: " << "Boom in Zoo Attendance! " << endl;
    cout << "===============================" << endl;
    cout << "Each Tiger gets a random bonus of $" << randBonus << "." << endl;

    // Need to count numOfTigers that does not equal -1 and multiply by bonus
    for(int i = 0; i < numOfTigers; i++)
    {
        if (tigPtr[i].getAge()!= -1)
        {
           count++;    
        }
    }

    bonus = (randBonus * count);
    cout << "===============================" << endl;
    cout << "TOTAL BONUS TODAY: $" << bonus << endl;
    playerCash += bonus;
}
       
void Zoo::randEvent()
{
    int randNum = 0;
    randNum = rand() % 3;

    switch(randNum)
    {
        case 0: 
        {
            sickAnimal();
            break;
        }
        case 1:
        {
            boomZooAttd();
            break;
        }
        case 2:
        {
            makeBaby();
            break;
        }
        case 3:
        {
            cout << "Nothing seems to have happened... " << endl;
            break;
        }
    }
}


int Zoo::getCash() const
{
    return playerCash;
}


int Zoo::getDay() const
{
    return day;
}


int Zoo::getTigers() const
{
    int count = 0;
    for (int i = 0; i < numOfTigers; i++)
    {
        if (tigPtr[i].getAge() != -1)
        {
            count ++;
        }
    }
    return count;
}


int Zoo::getPenguins() const
{
    int count = 0;
    for (int i = 0; i < numOfPenguins; i++)
    {
        if (penPtr[i].getAge() != -1)
        {
            count ++;
        }
    }
    return count;
}


int Zoo::getTurtles() const
{
    int count = 0;
    for (int i = 0; i < numOfTurtles; i++)
    {
        if (turPtr[i].getAge() != -1)
        {
            count ++;
        }
    }
    return count;
}

void Zoo::printStatus()
{
    ++day;
    cout << "===============================" << endl;
    cout << "===============================" << endl;
    cout << "DAY: " << day << endl;
    cout << "===============================" << endl;
    //prints money
    cout << "BEGINNING CASH: $" << getCash() << endl;
    cout << "===============================" << endl;
    cout << endl;

    //prints each animal
    cout << "ANIMALS CURRENTLY IN ZOO:" << endl;
    cout << "===============================" << endl;
    cout << endl;

    int count = 1;

    cout << getTigers() << " TIGERS: " << endl;
    for (int i = 0; i < numOfTigers; i++)
    {
        if (tigPtr[i].getAge() != -1)
        {
            cout << count << ": Age: " << tigPtr[i].getAge() <<endl;
            count ++;
        }
    }
    cout << endl;
    count = 1;
    cout  << getPenguins() << " PENGUINS: " << endl;
    for (int i = 0; i < numOfPenguins; i++)
    {
        if (penPtr[i].getAge() != -1)
        {
            cout << count << ": Age: " << penPtr[i].getAge() <<endl;
            count ++;
        }
    }
    cout << endl;
    count = 1;
    cout << getTurtles() << " TURTLES: " << endl;
    for (int i = 0; i < numOfTurtles; i++)
    {
        if (turPtr[i].getAge() != -1)
        {
            cout << count << ": Age: " << turPtr[i].getAge() <<endl;
            count++;
        }
    }
    cout << endl;
    //print if game is over

    if (gameIsOver())
    {
        cout << "You have $" << getCash() << " in the bank." << endl;
    }
}

// Mutators

bool Zoo::gameIsOver()
{
    if (getCash() <= 0 || gameOver == true){
        return true;
    }
    return false;
}

Zoo::~Zoo()
{
    delete [] tigPtr;
    delete [] penPtr;
    delete [] turPtr;

    tigPtr = nullptr;
    penPtr = nullptr;
    turPtr = nullptr;
}