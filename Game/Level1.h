#ifndef LEVEL1_H
#define LEVEL1_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>
#include <cstdlib>

#include "board.h"
#include "player.h"

class Level1: public Player {
public:
    Level1(bool isTurn, int color, Board *brd, char ch);

    void findMove() override;
};

#endif
