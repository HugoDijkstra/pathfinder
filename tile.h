#ifndef TILE_H
#define TILE_H
#include <SDL2/SDL.h>
#include <math.h>
class Tile {
public:
  Tile();
  Tile(bool walkable, int cost, int x, int y, int w, int h);
  virtual ~Tile();
  bool walkable;
  int cost;
  SDL_Rect rect;
  Tile *adjacent[4];
  int distanceTo(Tile *tile);

private:
};

#endif
