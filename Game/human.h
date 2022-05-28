#ifndef HUMAN_H
#define HUMAN_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>

#include "board.h"
#include "player.h"

class Human: public Player {
public:
    Human(bool isTurn, int color, Board *brd, char ch);
    void findMove() override;
};

#endif
