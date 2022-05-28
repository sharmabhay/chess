#include "board.h"

Board::Board(): Subject{} {
    pieces[0][0] = new Rook(true, 1, std::make_pair('a', 1), 5, 'r');
    pieces[0][1] = new Knight(1, std::make_pair('b', 1), 3, 'n');
    pieces[0][2] = new Bishop( 1, std::make_pair('c', 1), 3, 'b');
    pieces[0][3] = new Queen(1, std::make_pair('d', 1), 9, 'q');
    pieces[0][4] = new King(true, false, false, 1, std::make_pair('e', 1), -1, 'k');
    pieces[0][5] = new Bishop( 1, std::make_pair('f', 1), 3, 'b');
    pieces[0][6] = new Knight( 1, std::make_pair('g', 1), 3, 'n');
    pieces[0][7] = new Rook(true, 1, std::make_pair('h', 1), 5, 'r');

    for (int i = 0; i < 8; i++) {//white pawns
        pieces[1][i] = new Pawn(false, false, 1, std::make_pair('a' + i, 2), 1, 'p');
    }

    for (int i = 2; i < 6; i++) {//empty spaces
        for (int j = 0; j < 8; j++) {
            char lightOrDark = ' ';
            if (((i-j) % 2) == 0){//if the difference between row and col are even, then dark square
                lightOrDark = '_';
            }
            pieces[i][j] = new EmptyPiece(-1, std::make_pair('a' + j, j + 1), 0, lightOrDark);
        }
    }

    for (int i = 0; i < 8; i++) {//black pawns
        pieces[6][i] = new Pawn(false, false, 0, std::make_pair('a' + i, 7), 1, 'P');
    }

    pieces[7][0] = new Rook(true, 0, std::make_pair('a', 8), 5, 'R');
    pieces[7][1] = new Knight(0, std::make_pair('b', 8), 3, 'N');
    pieces[7][2] = new Bishop( 0, std::make_pair('c', 8), 3, 'B');
    pieces[7][3] = new Queen(0, std::make_pair('d', 8), 9, 'Q');
    pieces[7][4] = new King(true, false, false, 0, std::make_pair('e', 8), -1, 'K');
    pieces[7][5] = new Bishop( 0, std::make_pair('f', 8), 3, 'B');
    pieces[7][6] = new Knight( 0, std::make_pair('g', 8), 3, 'N');
    pieces[7][7] = new Rook(true, 0, std::make_pair('h', 8), 5, 'R');
}

Board::~Board() {
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++ j){
            delete pieces[i][j];
        }
    }
}

Piece* Board::getPiece(std::pair<char, int> startLoc) {
    return pieces[startLoc.second-1][startLoc.first - 'a'];
}

Piece* Board::getState(int x, int y) {//for observers
    return pieces[x][y];
}

std::vector<std::pair <char, int>> Board::emptyMoveableSquares() {
    std::vector<std::pair<char, int>> moves;
    return moves;
}

std::vector<std::pair <char, int>> Board::pawnMoveableSquares(Pawn &p) {
    //file and rank represent char and int in position
    char file = p.getLoc().first; //eg in c5, this is c
    int rank = p.getLoc().second; //eg in c5, this is 5

    int X[8] = { 1, 1, 1, -1, -1, -1, 0, 0 };
    int Y[8] = { -1, 0, 1, 1, 0, -1, 1, -1 };
    std::vector<std::pair<char, int>> moves;

    if (p.getChar() == 'p'){

        Piece *twoSpaces = getPiece(std::make_pair(file,rank+2));
        Piece *oneSpace = getPiece(std::make_pair(file,rank+1));
        Piece *rightDiag = getPiece(std::make_pair(file+1,rank+1));
        Piece *leftDiag = getPiece(std::make_pair(file-1,rank+1));

        if ((twoSpaces->getChar()==' ' || twoSpaces->getChar()=='_') && p.gethasMoved() == false){
            moves.push_back(std::make_pair(file,rank+2));
        }

        if (oneSpace->getPoints()==0){
            moves.push_back(std::make_pair(file,rank+1));
        }

        //capture
        if (rightDiag->getColor()==(1-p.getColor())){
            moves.push_back(std::make_pair(file+1,rank+1));
        }

        if (leftDiag->getColor()==(1-p.getColor())){
            moves.push_back(std::make_pair(file-1,rank+1));
        }

        //for (int col = 0; col < 8; ++col) {
            //if (p.getLoc() == p.getPiece(std::make_pair(col+1, 8))) {
                //Queen *q = new Piece(p.getColor(), std::make_pair(col+1, 8), 9, 'q');
                //delete p;
            //}
        //}
    }
    else if (p.getChar() == 'P'){

        Piece *twoSpaces = getPiece(std::make_pair(file,rank-2));
        Piece *oneSpace = getPiece(std::make_pair(file,rank-1));
        Piece *rightDiag = getPiece(std::make_pair(file+1,rank-1));
        Piece *leftDiag = getPiece(std::make_pair(file-1,rank-1));

        if ((twoSpaces->getChar()==' ' || twoSpaces->getChar()=='_') && p.gethasMoved() == false){
            moves.push_back(std::make_pair(file,rank-2));
        }

        if (oneSpace->getPoints()==0){
            moves.push_back(std::make_pair(file,rank-1));
        }

        //capture
        if (rightDiag->getColor()==(1-p.getColor())){
            moves.push_back(std::make_pair(file+1,rank-1));
        }

        if (leftDiag->getColor()==(1-p.getColor())){
            moves.push_back(std::make_pair(file-1,rank-1));
        }

        //for (int col = 0; col < 8; ++col) {
            //if (p.getLoc() == p.getPiece(std::make_pair(col+1, 1))) {
                //Queen *q = new Piece(p.getColor(), std::make_pair(col+1, 1), 9, 'Q');
                //delete p;
            //}
        //}
    }

    //TODO: Implement en passant
    return moves;
}

std::vector<std::pair <char, int>> Board::knightMoveableSquares(Knight &n) {
    //file and rank represent char and int in position
    char file = n.getLoc().first; //eg in c5, this is c
    int rank = n.getLoc().second; //eg in c5, this is 5

    int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    std::vector<std::pair<char, int>> moves;
    for (int i = 0; i < 8; i++) {
        char x = file + X[i];
        int y = rank + Y[i];

        //checks if square is valid location on the board and there is no piece of the same colour
        //also checks there is no king of opposite colour on the square
        if (x >= 'a' && y > 0 && x <= 'h' && y <= 8 && getPiece({x,y})->getColor()!=n.getColor()
            && !(getPiece({x,y})->getChar() == 'k' && getPiece({x,y})->getColor()!=n.getColor())) {
            moves.push_back(std::make_pair(x,y)); //TODO: check if move causes king to be in check
        }
    }
    return moves;
}

std::vector<std::pair <char, int>> Board::bishopMoveableSquares(Bishop &b) {
    //file and rank represent char and int in position
    char file = b.getLoc().first; //eg in c5, this is c
    int rank = b.getLoc().second; //eg in c5, this is 5

    std::vector<std::pair<char, int>> moves;
    // four loops: u,d,l,r
    //while not end of the board, and you havent found a piece blocking your way,
        //add to the vector

    //up-left loop
    int up = rank+1;
    int left = file-1;
    while (left >='a' && up <= 8 && getPiece(std::make_pair(left,up))->getPoints()==0){
        moves.push_back(std::make_pair(left,up));
        up++;
        left--;
    }
    if (left >='a' && up <= 8 && getPiece(std::make_pair(left,up))->getColor()==(1-b.getColor())) {
        moves.push_back(std::make_pair(left,up)); //capturing move
    }

    //up-right loop
    up = rank+1;
    int right = file+1;
    while (right <='h' && up <= 8 && getPiece(std::make_pair(right,up))->getPoints()==0){
        moves.push_back(std::make_pair(right,up));
        up++;
        right--;
    }
    if (right <='h' && up <= 8 && getPiece(std::make_pair(right,up))->getColor()==(1-b.getColor())) {
        moves.push_back(std::make_pair(right,up)); //capturing move
    }

    //down-left loop
    int down = rank-1;
    left = file-1;
    while (left >='a' && down >= 1 && getPiece(std::make_pair(left,down))->getPoints()==0){
        moves.push_back(std::make_pair(left,down));
        down--;
        left--;
    }
    if (left >='a' && down >= 1 && getPiece(std::make_pair(left,down))->getColor()==(1-b.getColor())) {//capturing move
        moves.push_back(std::make_pair(left,down)); //capturing move
    }

    //down-right loop
    down = rank-1;
    right = file+1;
    while (right <='h' && down >= 1 && getPiece(std::make_pair(right,down))->getPoints()==0){
        moves.push_back(std::make_pair(right,down));
        down--;
        right++;
    }
    if (right <='h' && down >= 1 && getPiece(std::make_pair(right,down))->getColor()==(1-b.getColor())) {//capturing move
        moves.push_back(std::make_pair(right,down)); //capturing move
    }

    return moves;
}

std::vector<std::pair <char, int>> Board::rookMoveableSquares(Rook &r) {
    //file and rank represent char and int in position
    char file = r.getLoc().first; //eg in c5, this is c
    int rank = r.getLoc().second; //eg in c5, this is 5

    // four loops: u,d,l,r
    //while not end of the board, and you havent found a piece blocking your way,
        //add to the vector

    //up loop
    int up = rank + 1;
    std::vector<std::pair<char, int>> moves;
    while (up <= 8 && getPiece(std::make_pair(file,up))->getPoints()==0){
        moves.push_back(std::make_pair(file,up));
        up++;
    }
    if (up <= 8 && getPiece(std::make_pair(file,up))->getColor()==(1-r.getColor())) {
        moves.push_back(std::make_pair(file,up)); //capturing move
    }

    //down loop
    int down = rank - 1;
    while (down >= 1 && getPiece(std::make_pair(file,down))->getPoints()==0){
        moves.push_back(std::make_pair(file,down));
        down--;
    }
    if (down >= 1 && getPiece(std::make_pair(file,down))->getColor()==(1-r.getColor())) {
        moves.push_back(std::make_pair(file,down)); //capturing move
    }

    //right loop
    int right = file + 1;
    while (right <= 'h' && getPiece(std::make_pair(right,rank))->getPoints()==0){
        moves.push_back(std::make_pair(right,rank));
        right++;
    }
    if (right <= 'h' && getPiece(std::make_pair(right,rank))->getColor()==(1-r.getColor())) {//capturing move
        moves.push_back(std::make_pair(right,rank)); //capturing move
    }

    //left loop
    int left = file - 1;
    while (left >= 'a' && getPiece(std::make_pair(left,rank))->getPoints()==0){
        moves.push_back(std::make_pair(left,rank));
        left--;
    }
    if (left >= 'a' && getPiece(std::make_pair(left,rank))->getColor()==(1-r.getColor())) {//capturing move
        moves.push_back(std::make_pair(left,rank)); //capturing move
    }

    return moves;
}

std::vector<std::pair <char, int>> Board::queenMoveableSquares(Queen &q) { // TODO!!
    std::pair <char, int> curLoc = q.getLoc();
    int color = q.getColor();

    std::vector<std::pair<char, int>> moves;

    Rook *r = new Rook(false, q.getColor(), q.getLoc(), 5, 'r');
    moves = rookMoveableSquares(*r);
    delete r;

    Bishop *bp = new Bishop( q.getColor(), q.getLoc(), 3, 'b');
    std::vector<std::pair<char, int>> movesbp = bishopMoveableSquares(*bp);
    moves.insert(std::end(moves), std::begin(movesbp), std::end(movesbp));
    delete bp;

    return moves;
}

std::vector<std::pair <char, int>> Board::kingMoveableSquares(King &k) {
    char col = k.getLoc().first;
    int row = k.getLoc().second;

    int X[8] = { 1, 1, 1, -1, -1, -1, 0, 0 };
    int Y[8] = { -1, 0, 1, 1, 0, -1, 1, -1 };
    std::vector<std::pair<char, int>> kmoves;
    for (int i = 0; i < 8; i++) {
        char x = col + X[i];
        int y = row + Y[i];

        if (x >= 'a' && y >= 1 && x <= 'h' && y <= 8 && getPiece({x,y})->getColor() != k.getColor()) {
            kmoves.push_back(std::make_pair(x,y));
        }
    }

    std::vector<std::pair <char, int>> oppMoves;//how the opposite color can capture
    std::vector<std::pair <char, int>> finalMoves;

    //get big vector of moves other color can use to capture
    for (int i = 0; i < 8; ++i){//row
        for (int j = 0; j < 8; ++j){//column

            char file = pieces[i][j]->getLoc().first;
            int rank = pieces[i][j]->getLoc().second;

            if (pieces[i][j]->getColor() != k.getColor()){
                if (pieces[i][j]->getChar() == 'P'){

                    if (  file - 1  >= 'a' && rank - 1 >= 1){
                        oppMoves.push_back(std::make_pair(file - 1 , rank - 1 ));//adding square down-left
                    }
                    if ( file + 1 <= 'h' && rank - 1 >= 1){ //adding square down right
                        oppMoves.push_back(std::make_pair(file + 1, rank - 1));
                    }
                }
                else if (pieces[i][j]->getChar() == 'p'){

                   if (  file - 1  >= 'a' && rank + 1 <= 8){
                        oppMoves.push_back(std::make_pair(file - 1 , rank + 1 ));//adding square up-left
                    }
                    if ( file + 1 <= 'h' && rank + 1 <= 8){ //adding square up right
                        oppMoves.push_back(std::make_pair(file + 1, rank + 1));
                    }
                }
                else if(pieces[i][j]->getChar() != 'k' && pieces[i][j]->getChar() != 'K'){
                    std::vector<std::pair <char, int>> curPiece;

                    if(pieces[i][j]->getChar() == 'b' || pieces[i][j]->getChar() == 'B'){
                        Bishop *bp = static_cast<Bishop *>(pieces[i][j]);
                        curPiece = bishopMoveableSquares(*bp);
                    }
                    if(pieces[i][j]->getChar() == 'n' || pieces[i][j]->getChar() == 'N'){
                        Knight *kn = static_cast<Knight *>(pieces[i][j]);
                        curPiece = knightMoveableSquares(*kn);
                    }
                    if(pieces[i][j]->getChar() == 'r' || pieces[i][j]->getChar() == 'R'){
                        Rook *r = static_cast<Rook *>(pieces[i][j]);
                        curPiece = rookMoveableSquares(*r);
                    }
                    if(pieces[i][j]->getChar() == 'q' || pieces[i][j]->getChar() == 'Q'){
                        Queen *q = static_cast<Queen *>(pieces[i][j]);
                        curPiece = queenMoveableSquares(*q);
                    }

                    oppMoves.insert(std::end(oppMoves), std::begin(curPiece), std::end(curPiece));
                }
                else if(pieces[i][j]->getChar() == 'k' || pieces[i][j]->getChar() == 'K'){
                    std::vector<std::pair<char, int>> otherKMoves;
                    for (int i = 0; i < 8; i++) {
                        char x = file + X[i];
                        int y = rank + Y[i];

                        if (x >= 'a' && y >= 1 && x <= 'h' && y <= 8 && getPiece({x,y})->getColor() != k.getColor()) {
                            otherKMoves.push_back(std::make_pair(x,y));
                        }
                    }

                    oppMoves.insert(std::end(oppMoves), std::begin(otherKMoves), std::end(otherKMoves));
                }
                else{
                    continue;
                }
            }
        }
    }

    for (auto n : kmoves){
        bool captureFound = false;
        for(int i = 0; i < oppMoves.size(); ++i){
            if( n.first == oppMoves.at(i).first && n.second == oppMoves.at(i).second ){
                captureFound = true;
                break;
            }
        }
        if (!captureFound){
            finalMoves.push_back(n);
        }
    }

    return finalMoves;
}

//startLoc and endLoc are obtained from the findMove Function in Player
void Board::makeMove(std::pair<char, int> startLoc, std::pair<char, int> endLoc) {
    if (isMoveValid(startLoc, endLoc)) {
        //get the piece at startLoc
        int startY = startLoc.first - 97;
        int startX = startLoc.second - 1;

        int endY = endLoc.first - 97;
        int endX = endLoc.second - 1;
        Piece *p = getPiece(startLoc);

        delete pieces[endX][endY];
        pieces[endX][endY] = p;

        //make the location of the piece endLoc
        p->setPair(endLoc);

        //make start location empty again
        char lightOrDark = ' ';
        if ((startX-startY) % 2 == 0) lightOrDark = '_';

        pieces[startX][startY] = new EmptyPiece(-1, std::make_pair('a' + startX, startY + 1), 0, lightOrDark);

        if (p->getChar()=='p' || p->getChar()=='P'){
            Pawn *pwn = static_cast<Pawn *>(p);
            pwn->sethasMoved(true);
        }
        render();
    }
}

bool Board::isMoveValid(std::pair<char, int> startLoc, std::pair<char, int> endLoc) {
    Piece *piece = getPiece(startLoc);
    std::vector<std::pair<char, int>> moves;
    if(piece->getChar() == ' ' || piece->getChar() == '_'){
        std::cout  << "Trying to move empty piece!" << std::endl;
        return false;
    }
    else if(piece->getChar() == 'p' || piece->getChar() == 'P'){
        Pawn *p = static_cast<Pawn *>(piece);
        moves = pawnMoveableSquares(*p);
    }
    else if(piece->getChar() == 'n' || piece->getChar() == 'N'){
        Knight *n = static_cast<Knight *>(piece);
        moves = knightMoveableSquares(*n);
    }
    else if(piece->getChar() == 'r' || piece->getChar() == 'R'){
        Rook *r = static_cast<Rook *>(piece);
        moves = rookMoveableSquares(*r);
    }
    else if(piece->getChar() == 'b' || piece->getChar() == 'B'){
        Bishop *b = static_cast<Bishop *>(piece);
        moves = bishopMoveableSquares(*b);
    }
    else if(piece->getChar() == 'q' || piece->getChar() == 'Q'){
        Queen *q = static_cast<Queen *>(piece);
        moves = queenMoveableSquares(*q);
    }
    else if(piece->getChar() == 'k' || piece->getChar() == 'K'){
        King *k = static_cast<King *>(piece);
        moves = kingMoveableSquares(*k);
    }

    for(int i = 0; i < moves.size(); ++i){
        if( endLoc.first == moves.at(i).first && endLoc.second == moves.at(i).second ){
            //create a inCheck method in board.h
            //create a Board here with the move done
            //if your king is in check as a result of the move, the move is invalid

            return true;
        }
    }

    return false;
}

void Board::render() {
    notifyObservers();
}
