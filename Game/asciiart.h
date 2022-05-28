#ifndef ASCIIART_H
#define ASCIIART_H
#include <iostream>

class AsciiArt {
public:
    virtual ~AsciiArt();

    virtual char charAt(int row, int col, int tick) = 0;
};

#endif
