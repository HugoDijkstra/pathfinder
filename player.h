#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

class Player {
public:
  Player(int x, int y);
  virtual ~Player();
  int x, y;
  SDL_Rect rect;

protected:
};

#endif
