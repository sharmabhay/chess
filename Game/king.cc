#include "king.h"

King::King(bool canCastle, bool inCheckmate, bool inCheck, int color, std::pair<char, int> location, int points, char c):
    Piece(color, location, points, c), canCastle{canCastle}, inCheckmate{inCheckmate}, inCheck{inCheck} {}

bool King::getcanCastle() const {
    return canCastle;
}

bool King::getinCheckmate() const {
    return inCheckmate;
}

bool King::getinCheck() const {
    return inCheck;
}

void King::setcanCastle(Board &b) {
    canCastle = true; // TODO: change this!
}

void King::setinCheckmate(Board &b) {
    inCheckmate = false; // TODO: change this!
}

void King::setinCheck(Board &b) {
    inCheck = false; // TODO: change this!
}
