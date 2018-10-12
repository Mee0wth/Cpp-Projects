/******************************************************************************
 ** Animal Class
 ** This is the animal class header and contains all the member variables and 
 ** member function declarations for animal.cpp
 * ****************************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP


class Animal 
{
    protected:
        int   age,
              numOfBabies,
              cost,
              foodCost,
              revenue;
            
    public:
        // Defualt Constructor
        Animal();

        // accessors 
        int getAge() const;
        int getCost() const;
        int getNumOfBabies() const;
        int getFoodCost() const;
        int getRevenue() const;
        int getQuantity() const;

        // mutators 
        void setAge(int age);
        void setCost(int cost);
        void setNumOfBabies(int baby);
        void setFoodCost(int food);
        void setRevenue(int revenue);




};

#endif