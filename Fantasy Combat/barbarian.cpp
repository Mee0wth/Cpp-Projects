/*******************************************************************************
 ** barbarian.cpp
 ** This is the implementation file for the barbarian class and includes all
 **  the member variables and functions.
 ******************************************************************************/
#include "barbarian.hpp"

int Barbarian::attack()
{
    int att = rollDie(2,6);
    setAtt(att);
    return att;
}


int Barbarian::defense()
{
    int def = rollDie(2,6);
    setDef(def);
    return def;
}


void Barbarian::takeDmg(int dmg)
{
    //Damage = attacker’s roll – defender’s roll – defender’s armor
    setDef(defense());
    int actualDmg = dmg - getDef() - getArm();
    if (actualDmg <= 0)
    {
        actualDmg = 0;
    }
    setActualDmg(actualDmg);
    setStr(getStr() - actualDmg);
    
}

Barbarian::~Barbarian()
{
    setName("");
}