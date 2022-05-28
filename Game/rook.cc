#include "rook.h"

Rook::Rook(bool canCastle, int color, std::pair <char, int> location, int points, char c):
    Piece(color, location, points, c), canCastle{canCastle} {}

bool Rook::getcanCastle() const {
    return canCastle;
}
