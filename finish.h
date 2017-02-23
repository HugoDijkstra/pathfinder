#ifndef FINISH_H
#define FINISH_H

#include <SDL2/SDL.h>

class Finish {
public:
  Finish(int x, int y);
  virtual ~Finish();
  int x, y;
  SDL_Rect rect;

protected:
};

#endif
