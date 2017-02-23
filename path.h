#ifndef PATH_H
#define PATH_H

#include "tile.h"
#include <algorithm>
#include <iostream>
#include <vector>
class Path {
public:
  Path();
  virtual ~Path();
  Tile *getNextAdjacentTile(Tile *tile, Tile *goal, std::vector<Tile *> *used);
  bool genPath(Tile *start, Tile *goal);
  std::vector<Tile *> getPath() { return path; };

protected:
  std::vector<Tile *> path;
};

#endif
