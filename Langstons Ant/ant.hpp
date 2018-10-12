/******************************************************************************
 ** Class Ant Header
 ** This is the header file for the class ant.cpp and includes all the 
 ** declarations.
 * ****************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

enum Direction {UP, RIGHT, DOWN, LEFT};
enum Color {WHITE, BLACK};

class Ant 
{
    private:
        int x = 0,
            y = 0;
        
        int row = 0,
            col = 0;
        
        Direction antDirection = Direction::UP;
        Color **boardPtr;

    public:
        Ant(int x, int y, int row, int col, Color ** board);
        void turnRight();
        void turnLeft();
        void setXpos(int x);
        void setYpos(int y);
        void forward();
        int getXpos();
        int getYpos();
        int getDirection();
        bool hitsWall();

        // Board
        void createBoard(int row, int col);
        Color **getBoard();
};

#endif