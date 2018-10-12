/*******************************************************************************
 ** character.hpp
 ** This is the header file for the character class and includes all the 
 ** declarations for character.cpp. 
 ******************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <random>
#include <string>
using std::string;
    
class Character
{
    private:
        int att = 0,
            def = 0,
            arm = 0,
            str = 0,
            maxStr = 0,
            actualDmg = 0;
        
        string type = "";
        string name = "";
        

    public:
        //intput armor and str
        Character(string,string,int,int);

        //each subclass gotta implement their own thing here
        virtual int attack() = 0;
        virtual int defense() = 0;
        virtual void takeDmg(int) = 0;

        //getter
        int getArm();
        int getStr();
        int getAtt();
        int getDef();
        int getActualDmg();
        string getType();
        string getName();
        bool isAlive();

        //setter
        void setArm(int);
        void setStr(int);
        void setAtt(int);
        void setDef(int);
        void setActualDmg(int);
        void setName(string);


        //rolls the die
        int rollDie(int,int);

        virtual ~Character();

};

#endif