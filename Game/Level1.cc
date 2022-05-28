#include "Level1.h"

Level1::Level1(bool isTurn, int color, Board *brd, char ch):
    Player(isTurn, color, brd, ch) {}

void Level1::findMove(){
    std::vector<std::pair<char, int>> allStartMoves;
    std::vector<std::pair<char, int>> allEndMoves;
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            if (brd->getState(i,j)->getColor() == color){
                char file = brd->getState(i,j)->getLoc().first;
                int rank = brd->getState(i,j)->getLoc().second;

                if(brd->getState(i,j)->getChar() == 'p' || brd->getState(i,j)->getChar() == 'P'){
                    Pawn *p = dynamic_cast<Pawn *>(brd->getState(i,j));
                    std::vector<std::pair<char, int>> pieceMoves = brd->pawnMoveableSquares(*p);
                    for (auto n : pieceMoves){
                        allStartMoves.push_back(std::make_pair(file, rank));
                        allEndMoves.push_back(n);
                    }
                }
                else if(brd->getState(i,j)->getChar() == 'b' || brd->getState(i,j)->getChar() == 'B'){
                    Bishop *bp = dynamic_cast<Bishop *>(brd->getState(i,j));
                    std::vector<std::pair<char, int>> pieceMoves = brd->bishopMoveableSquares(*bp);
                    for (auto n : pieceMoves){
                        allStartMoves.push_back(std::make_pair(file, rank));
                        allEndMoves.push_back(n);
                    }
                }
                else if(brd->getState(i,j)->getChar() == 'n' || brd->getState(i,j)->getChar() == 'N'){
                    Knight *kn = dynamic_cast<Knight *>(brd->getState(i,j));
                    std::vector<std::pair<char, int>> pieceMoves = brd->knightMoveableSquares(*kn);
                    for (auto n : pieceMoves){
                        allStartMoves.push_back(std::make_pair(file, rank));
                        allEndMoves.push_back(n);
                    }
                }
                else if(brd->getState(i,j)->getChar() == 'r' || brd->getState(i,j)->getChar() == 'R'){
                    Rook *r = dynamic_cast<Rook *>(brd->getState(i,j));
                    std::vector<std::pair<char, int>> pieceMoves = brd->rookMoveableSquares(*r);
                    for (auto n : pieceMoves){
                        allStartMoves.push_back(std::make_pair(file, rank));
                        allEndMoves.push_back(n);
                    }
                }
                else if(brd->getState(i,j)->getChar() == 'q' || brd->getState(i,j)->getChar() == 'Q'){
                    Queen *q = dynamic_cast<Queen *>(brd->getState(i,j));
                    std::vector<std::pair<char, int>> pieceMoves = brd->queenMoveableSquares(*q);
                    for (auto n : pieceMoves){
                        allStartMoves.push_back(std::make_pair(file, rank));
                        allEndMoves.push_back(n);
                    }
                }
                else if(brd->getState(i,j)->getChar() == 'k' || brd->getState(i,j)->getChar() == 'K'){
                    King *k = dynamic_cast<King *>(brd->getState(i,j));
                    std::vector<std::pair<char, int>> pieceMoves = brd->kingMoveableSquares(*k);
                    for (auto n : pieceMoves){
                        allStartMoves.push_back(std::make_pair(file, rank));
                        allEndMoves.push_back(n);
                    }
                }
                else{
                    continue;
                }
            }
        }
    }

    int index = rand() % allStartMoves.size();
    std::cout << index;
    brd->makeMove(allStartMoves[index], allEndMoves[index]);
}
