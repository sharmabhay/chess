#include "player.h"

Player::Player() {
    isTurn = false;
    color = 1;
    brd = nullptr;
    ch = 'p';
}

Player::Player( bool isTurn, int color, Board *brd, char ch):
    isTurn{isTurn}, color{color}, brd{brd}, ch{ch} {}

Player::~Player() {
    //delete this;
}

bool Player::getisTurn() const {
    return isTurn;
}

int Player::getColor() const {
    return color;
}

void Player::setisTurn(bool turn) {
    isTurn = turn;
}

void Player::setColor(int col) {
    color = col;
}

char Player::getChar() {
    return ch;
}
