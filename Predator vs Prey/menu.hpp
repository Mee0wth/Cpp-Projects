/*********************************************************************
** Program name: menu.hpp
** Assignment: Group Project
** Date: May 1, 2018
** 
** What this class does: 
**
** Dependencies:
** validation.hpp
**
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>

class Menu
{
  private:
    // Data members
    std::string menuTitle;
    std::vector<std::string> menuOptions;
    int menuSize;

    // Methods
    void print();

  public:
    // Methods
    Menu();
    Menu(std::string);
    void setTitle(std::string);
    void add(std::string);
    int run();
};

#endif