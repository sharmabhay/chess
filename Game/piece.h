#ifndef PIECE_H
#define PIECE_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>

class Piece {
protected:
    int color;
    std::pair <char, int> location;
    int points;
    char c;

public:
    Piece();
    Piece( int color, std::pair <char, int> location, int points, char c);
    virtual ~Piece();

    int getColor() const;
    int getPoints() const;
    char getChar() const;
    std::pair<char, int> getLoc() const;
    void setPair(std::pair <char, int> newLoc);
};

#endif
