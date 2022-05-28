#include <iostream>
#include "textObserver.h"

TextObserver::TextObserver(Board *b): b{b} {
    b->attach(this);
}

TextObserver::~TextObserver(){
    b->detach(this);
}

void TextObserver::notify() { // prints text observer
    int cols= 8;
    int rows= 8;

    out << " +";
    for (int j = 0; j < cols; ++j) out << '-';
    out << '+' << std::endl;

    for (int i = 7; i >= 0; --i) {
        out << (i+1);
        out << '|';
        for (int j = 0; j < 8; ++j) out << b->getState(i, j)->getChar();//->getChar();// character at that point, accounting for ticks
        out << '|' << std::endl;
    }

    out << " +";
    for (int j = 0; j < cols; ++j) out << '-';
    out << '+' << std::endl;

    out << "  abcdefgh" << std::endl;
}
