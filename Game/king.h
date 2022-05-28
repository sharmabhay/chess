#ifndef KING_H
#define KING_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout

#include "piece.h"

class Board;

class King: public Piece {
    bool canCastle = true;
    bool inCheckmate = false;
    bool inCheck = false;

public:
    King(bool canCastle, bool inCheckmate, bool inCheck, int color, std::pair <char, int> location, int points, char c);

    bool getcanCastle() const;
    bool getinCheckmate() const;
    bool getinCheck() const;
    void setcanCastle(Board &b);
    void setinCheckmate(Board &b);
    void setinCheck(Board &b);
};

#endif
