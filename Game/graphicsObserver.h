#ifndef _GRAPHICSOBSERVER_H_
#define _GRAPHICSOBSERVER_H_

#include "board.h"
#include "observer.h"
#include "studio.h"
#include "window.h"

class GraphicsObserver: public Observer {
 public:
    GraphicsObserver(int x, int y);
    ~GraphicsObserver();

  void notify() override;
};

#endif
