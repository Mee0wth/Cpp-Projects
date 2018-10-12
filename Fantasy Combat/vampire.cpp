/*******************************************************************************
 ** Vampire.cpp
 ** This is the implementation file for the vampire class and includes all the
 ** member variables and functions.
 ******************************************************************************/

#include "vampire.hpp"
#include <iostream>
using std::cout;
using std::endl;

int Vampire::attack()
{
    int att = rollDie(1,12);
    setAtt(att);
    return att;
}


int Vampire::defense()
{
    int def = rollDie(1,6);
    setDef(def);
    return def;
}


void Vampire::takeDmg(int dmg)
{
    //Damage = attacker’s roll – defender’s roll – defender’s armor
    charm = rollDie(1,2);

    if (charm == 1)
    {
        cout << "Vampire charmed the opponent. The attack was not successful. "
             << endl;

             return;
    }
    else
    {
        setDef(defense());
        int actualDmg = dmg - getDef() - getArm();
        if (actualDmg <= 0)
        {
            actualDmg = 0;
        }
        setActualDmg(actualDmg);
        setStr(getStr() - actualDmg);
        
    }
    
}

Vampire::~Vampire()
{
    setName("");
}