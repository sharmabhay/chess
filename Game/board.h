#ifndef BOARD_H
#define BOARD_H

#include <utility>
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cin, std::cout, std::endl
#include <algorithm>    // std::find

#include "piece.h"
#include "subject.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "emptyPiece.h"

class Board: public Subject {
    Piece *pieces[8][8];

public:
    Board();
    ~Board();

    //startLoc and endLoc are obtained from the findMove Function in Player
    void makeMove(std::pair<char, int> startLoc, std::pair<char, int> endLoc);
    bool isMoveValid(std::pair<char, int> startLoc, std::pair<char, int> endLoc);

    Piece* getPiece(std::pair<char, int> startLoc);

    Piece* getState(int x, int y) override;
    std::vector<std::pair <char, int>> emptyMoveableSquares();
    std::vector<std::pair <char, int>> pawnMoveableSquares(Pawn &p);
    std::vector<std::pair <char, int>> knightMoveableSquares(Knight &n);
    std::vector<std::pair <char, int>> bishopMoveableSquares(Bishop &b);
    std::vector<std::pair <char, int>> rookMoveableSquares(Rook &r);
    std::vector<std::pair <char, int>> queenMoveableSquares(Queen &q);
    std::vector<std::pair <char, int>> kingMoveableSquares(King &k);
    void render();
};

#endif
