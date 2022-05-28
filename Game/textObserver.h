#ifndef _TEXTOBSERVER_H_
#define _TEXTOBSERVER_H_

#include "board.h"
#include "observer.h"
#include "studio.h"

class TextObserver: public Observer {
    Studio *subject;
    Board *b;
    std::ostream &out = std::cout;

public:
    TextObserver(Board *b);
    ~TextObserver();

    void notify() override;
};

#endif
