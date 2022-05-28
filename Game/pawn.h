#ifndef PAWN_H
#define PAWN_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout

#include "piece.h"

class Pawn: public Piece {
    bool hasMoved = false;
    bool canPromote = false;

public:
    Pawn(bool hasMoved, bool canPromote, int color, std::pair <char, int> location, int points, char c);

    bool gethasMoved() const;
    bool getcanPromote() const;
    void sethasMoved(bool b);
};

#endif
