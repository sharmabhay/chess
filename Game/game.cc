#include "piece.h"
#include "subject.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "emptyPiece.h"
#include "subject.h"
#include "observer.h"
#include "textObserver.h"
#include "board.h"
#include "player.h"
#include "human.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

#include <utility>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    Board *brd = nullptr;
    Player *w = nullptr;
    Player *b = nullptr;
    TextObserver *t = nullptr;
    bool done = false;
    int white = 0;
    int black = 0;

    std::string s;

    std::cout << "Welcome to Chess!" << std::endl;
    std::cout << "To start a new game, enter the format 'game white-player black-player'." << std::endl;
    std::cout << "White pieces are lowercase, black pieces are uppercase" << std::endl;
    while (getline(std::cin, s)) {
        bool stalemate = false;
        std::string curCommand = "";
        std::istringstream ss1{s};

        ss1 >> curCommand;
        if (std::cin.eof()) break;

        if (curCommand == "game") {
            brd = new Board();
            t = new TextObserver(brd);
            brd->render();

            ss1 >> curCommand;
            if (curCommand == "human"){
                w = new Human(true, 1, brd, 'h');
            }
            else if (curCommand == "computer[1]"){
                w = new Level1(true, 1, brd, '1');
            }

            ss1 >> curCommand;
            if (curCommand == "human"){
                b = new Human(false, 0, brd, 'h');
            }
            else if (curCommand == "computer[1]"){
                b = new Level1(false, 0, brd, '1');
            }
        }
        else if (curCommand == "move") {
            std::string start;
            std::string end;

            //if computer level 1's turn
            if ((w->getisTurn() && w->getChar() =='1')){
                w->findMove();
                w->setisTurn(!w->getisTurn());
                b->setisTurn(!b->getisTurn());
            }
            else if ((b->getisTurn() && b->getChar() =='1')){
                b->findMove();
                w->setisTurn(!w->getisTurn());
                b->setisTurn(!b->getisTurn());
            }

            //if human's turn
            else if ((w->getisTurn() && w->getChar() =='h') || (b->getisTurn() && b->getChar() =='h')) {
                ss1 >> start;
                ss1 >> end;

                //should be replaced with findMove

                std::pair<char, int> startLoc = std::make_pair(start[0], start[1]-48);
                std::pair<char, int> endLoc = std::make_pair(end[0], end[1]-48);

                int curCol;
                if(w->getisTurn() == true){
                    curCol = 1;
                } else{
                    curCol = 0;
                }

                int movingPieceColor = brd->getPiece(startLoc)->getColor();

                if (brd->isMoveValid(startLoc, endLoc) && movingPieceColor == curCol ){
                    std::cout << "Move " << start[0] << start[1] << " " << end[0] << end[1] << " made" << std::endl;
                    brd->makeMove(startLoc, endLoc);
                    w->setisTurn(!w->getisTurn());
                    b->setisTurn(!b->getisTurn());
                }
                else {
                    std::cout << "Move is either invalid or leaves king in check! Please try again." << std::endl;
                }
            }
            else{
                continue;
            }
        }
        else if (curCommand == "resign") {
            if (w->getisTurn()) black++;
            else white++;

            done = true;
            break;
        }
        else {
            continue;
        }

        //TODO: check if player's king has been checkmated (using TextObserver?) and add that condition with "resign"
        //then finish stalemate

        done = true;
    }
    std::cout << "Final Score:" << std::endl;
    std::cout << "White: " << white << std::endl;
    std::cout << "Black: " << black << std::endl;

    delete w;
    delete b;
    delete t;
    delete brd;
}
