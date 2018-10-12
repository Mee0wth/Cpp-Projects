/*******************************************************************************
 ** Medusa.cpp
 ** This is the implementation file for the medusa class and includes all the
 ** member variables and functions.
 ******************************************************************************/
#include "medusa.hpp"
#include <iostream>

using std::endl;
using std::cout;

int Medusa::attack()
{
    int att = rollDie(2,6);

    // when Medusa attacks, she has a chance of rolling 12 and auto killing opponent
    if (att == 12)
    {
        cout << "Medusa used Glare to kill the opponent! " << endl;
        return 999;
    }
    setAtt(att);

    return att;
}

int Medusa::defense()
{
    int def = rollDie(1,6);
    setDef(def);
    return def;
}

void Medusa::takeDmg(int dmg)
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

Medusa::~Medusa()
{
    setName("");
}