#include "tile.h"

Tile::Tile() {
  walkable = false;
  cost = 0;
}
Tile::Tile(bool walkable, int cost, int x, int y, int w, int h) : Tile() {
  this->walkable = walkable;
  this->cost = cost;
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;
}
Tile::~Tile() {}
int Tile::distanceTo(Tile *tile) {
  int x = tile->rect.x - this->rect.x;
  int y = tile->rect.y - this->rect.y;
  return sqrt((x * x) + (y * y));
}
