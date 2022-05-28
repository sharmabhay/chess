#ifndef LEVEL3_H
#define LEVEL3_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>

#include "board.h"
#include "player.h"

class Level3: public Player {
public:
    Level3(bool isTurn, int col, Board *brd, char ch);

    virtual void findMove(Board *b) = 0;
};

#endif
