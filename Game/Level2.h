#ifndef LEVEL2_H
#define LEVEL2_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>

#include "board.h"
#include "player.h"

class Level2: public Player {
public:
    Level2(bool isTurn, int col, Board *brd, char ch);

    virtual void findMove(Board *b) = 0;
};

#endif
