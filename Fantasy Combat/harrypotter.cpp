/*******************************************************************************
 ** harrypotter.cpp
 ** This is the implementation file for the harry potter class and includes all
 **  the member variables and functions.
 ******************************************************************************/
#include "harrypotter.hpp"



int HarryPotter::attack()
{
    int att = rollDie(2,6);
    setAtt(att);
    return att;
}

int HarryPotter::defense()
{
    int def = rollDie(2,6);
    setDef(def);
    return def;
}

void HarryPotter::takeDmg(int dmg)
{
    //Damage = attacker’s roll – defender’s roll – defender’s armor
    setDef(defense());
    int actualDmg = dmg - getDef() - getArm();
    if (actualDmg <= 0)
    {
        actualDmg = 0;
    }    

    setActualDmg(actualDmg);

    if (getStr() - actualDmg <= 0 && deaths != 1)
    {
        //harry potter died, he gets revive once before he actually dies.
        setStr(20);
        this->deaths++; 
    }
    else
    {
        setStr(getStr() - actualDmg);
    }
}

HarryPotter::~HarryPotter()
{
    setName("");
}