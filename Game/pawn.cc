#include "pawn.h"

Pawn::Pawn(bool hasMoved, bool canPromote, int color, std::pair <char, int> location, int points, char c):
    Piece(color, location, points, c), hasMoved{hasMoved}, canPromote{canPromote} {}

bool Pawn::gethasMoved() const {
    return hasMoved;
}

bool Pawn::getcanPromote() const {
    return canPromote;
}

void Pawn::sethasMoved( bool b) {
    hasMoved = b;
}
