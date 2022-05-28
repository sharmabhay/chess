#ifndef KNIGHT_H
#define KNIGHT_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout

#include "piece.h"

class Knight: public Piece {
public:
    Knight(int color, std::pair <char, int> location, int points, char c);
};

#endif
