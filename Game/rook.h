#ifndef ROOK_H
#define ROOK_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout

#include "piece.h"

class Rook: public Piece {
    bool canCastle = true;

public:
    Rook(bool canCastle, int color, std::pair <char, int> location, int points, char c);

    bool getcanCastle() const;
};

#endif
