#ifndef EMPTYPIECE_H
#define EMPTYPIECE_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout

#include "piece.h"

class EmptyPiece: public Piece {
    int color;
    std::pair <char, int> location;

public:
    EmptyPiece(int color, std::pair <char, int> location, int points, char c);
};

#endif
