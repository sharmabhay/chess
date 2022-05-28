#include "piece.h"

Piece::Piece() {
    color = 0;
    location = std::make_pair('a', 1);
}

Piece::Piece( int color, std::pair <char, int> location, int points, char c):
    color{color}, location{location}, points{points}, c{c} {}

Piece::~Piece() {}

int Piece::getColor() const {
    return color;
}
int Piece::getPoints() const {
    return points;
}
std::pair<char, int> Piece::getLoc() const {
    return location;
}

char Piece::getChar() const {
    return c;
}

void Piece::setPair(std::pair <char, int> newLoc) {
    location = newLoc;
}
