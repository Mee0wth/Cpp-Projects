/******************************************************************************
 ** Class: ant.cpp
 ** This is the definition for the ant.cpp class and includes all the private
 ** variables and member functions of this class.
 * ****************************************************************************/
#include "ant.hpp"

Ant::Ant(int x, int y, int row, int col, Color ** board)
{
    this->x = x;
    this->y = y;
    this->row = row;
    this->col = col;
    boardPtr = board;
}

/* 
This member function moves the ant right or left depending on what color the
cell the ant was on.
*/
void Ant::forward()
{
    if (getBoard()[y][x] == Color::BLACK)
    {
        turnLeft();
    }
    else if (getBoard()[y][x] == Color::WHITE)
    {
        turnRight();
    }
}

void Ant::turnRight()
{
    getBoard()[getYpos()][getXpos()] = Color::BLACK;
    if (antDirection == Direction::UP)
    {
        antDirection = Direction::RIGHT;
        setXpos(getXpos() + 1);
    } 
    else if (antDirection == Direction::RIGHT)
    {
        antDirection = Direction::DOWN;
        setYpos(getYpos() - 1);
    }
    else if (antDirection == Direction::DOWN)
    {
        antDirection = Direction::LEFT;
        setXpos(getXpos() - 1);
    }
    else if (antDirection == Direction::LEFT)
    {
        antDirection = Direction::UP;
        setYpos(getYpos() + 1);
    }
}

void Ant::turnLeft()
{
    getBoard()[getYpos()][getXpos()] = Color::WHITE;
    if (antDirection == Direction::UP)
    {
        antDirection = Direction::LEFT;
        setXpos(getXpos() - 1);
    }
    else if (antDirection == Direction::RIGHT)
    {
        antDirection = Direction::UP;
        setYpos(getYpos() + 1);
    }
    else if (antDirection == Direction::LEFT)
    {
        antDirection = Direction::DOWN;
        setYpos(getYpos() - 1);
    }
    else if (antDirection == Direction::DOWN)
    {
        antDirection = Direction::RIGHT;
        setXpos(getXpos() + 1);
    }
}

void Ant::setXpos(int x)
{
    this->x = x;
}

void Ant::setYpos(int y)
{
    this->y = y;
}

int Ant::getXpos()
{
    return x;
}

int Ant::getYpos()
{
    return y;
}

int Ant::getDirection()
{
    return antDirection;
}

// Returns true when ant hits wall
bool Ant::hitsWall()
{
    int x = getXpos();
    int y = getYpos();
    if (x < 0 || x > (col - 1) || y < 0 || y > (row - 1))
    {
        return true;
    }
    return false;
}

// Returns the board color at board location
Color ** Ant::getBoard()
{
    return boardPtr;
}

