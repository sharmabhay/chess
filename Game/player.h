#ifndef PLAYER_H
#define PLAYER_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>

#include "board.h"

class Player {
protected:
    bool isTurn;
    int color;
    Board *brd;
    char ch;

public:
    Player( bool isTurn, int col, Board *brd, char ch);
    Player();
    ~Player();

    bool getisTurn() const;
    int getColor() const;
    void setisTurn(bool turn);
    void setColor(int col); //col is the color!!
    char getChar();
    virtual void findMove() = 0;
};

#endif
