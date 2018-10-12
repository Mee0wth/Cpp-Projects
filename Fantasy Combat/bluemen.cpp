/*******************************************************************************
 ** bluemen.cpp
 ** This is the implementation file for the bluemen class and includes all
 **  the member variables and functions.
 ******************************************************************************/
#include "bluemen.hpp"

int Bluemen::attack()
{
    int att =  rollDie(2,10);
    setAtt(att);
    return att;
}

int Bluemen::defense()
{
    int dies = 3;
    int diff = 12 - getStr();
    int itr = diff / 4;
    for (int i = 0; i < itr; i++)
    {
        dies--;
    }
    int def =  rollDie(dies,6);
    setDef(def);
    return def;
}

void Bluemen::takeDmg(int dmg)
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

Bluemen::~Bluemen()
{
    setName("");
}