#ifndef QUEEN_H
#define QUEEN_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout

#include "piece.h"

class Queen: public Piece {
public:
    Queen(int color, std::pair <char, int> location, int points, char c);
};

#endif
