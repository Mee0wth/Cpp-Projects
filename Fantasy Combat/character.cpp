/*******************************************************************************
 ** character.cpp
 ** This is the implementation file for the character class and includes all
 **  the member variables and functions.
 ******************************************************************************/
#include "character.hpp"

Character::Character(string name, string type, int arm, int str)
{
    this->type = type;
    if (str >= 0)
    {
        this->maxStr = str;
    }
    else
    {
        throw string("can't set str less then 0");
    }
    setName(name);
    setArm(arm);
    setStr(str);
}

//getter
int Character::getArm()
{
    return arm;
}

string Character::getName()
{
    return this->name;
}

int Character::getStr()
{
    return str;
}

int Character::getAtt()
{
    return att;
}

int Character::getDef()
{
    return def;
}

string Character::getType()
{
    return type;
}

int Character::getActualDmg()
{
    return actualDmg;
}
bool Character::isAlive()
{
    return str > 0;
}

//setter
void Character::setArm(int arm)
{
    this->arm = arm;
}


void Character::setStr(int str)
{
    if (str >= 0 && str > maxStr)
    {
        this->str = maxStr;
    }
    else if (str >= 0)
    {
        this->str = str;
    }
}

void Character::setAtt(int att)
{
    if (att <= 0)
    {
    	throw std::string("You cannot set character's attack to zero or below.");
    }
    this->att = att;
}


void Character::setDef(int def)
{
    if (def <= 0)
    {
    	throw std::string("You cannot set character's defend to zero or below.");
    }
    this->def = def;
}


void Character::setName(string name)
{
    this->name = name;
}

void Character::setActualDmg(int d)
{
    actualDmg = d;
}

int Character::rollDie(int dice,int side)
{
  	int total = 0;
  
    std::random_device rd;
    std::mt19937 e{rd()}; // or std::default_random_engine e{rd()};
    std::uniform_int_distribution<int> roll{1, side};
  
  	while (dice > 0)
    {
      total += roll(e);
      dice--;
    }
  	return total;
}

Character::~Character()
{
    name = "";
}