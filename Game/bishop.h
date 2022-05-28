#ifndef BISHOP_H
#define BISHOP_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout

#include "piece.h"
//#include "board.h"

class Bishop: public Piece {
public:
    Bishop(int color, std::pair <char, int> location, int points, char c);

    //virtual std::vector<std::pair <char, int>> moveableSquares(Board &b) override;
};

#endif
