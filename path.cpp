#include "path.h"

Path::Path() {}
Tile *Path::getNextAdjacentTile(Tile *tile, Tile *goal,
                                std::vector<Tile *> *used) {
  int i = 0;
  if (tile == NULL) {
    std::cout << "FUCK ITS NULL" << std::endl;
    return NULL;
  }
  Tile *closest = tile->adjacent[i];
  while (closest == NULL && i < 4) {
    i++;
    closest = tile->adjacent[i];
  }
  while (i < 4) {
    i++;
    Tile *cur = tile->adjacent[i];
    if (cur == NULL)
      continue;
    else if (!cur->walkable)
      continue;
    if (std::find(used->begin(), used->end(), cur) != used->end())
      continue;
    cur->distanceTo(goal);
    used->push_back(cur);
    if (cur->distanceTo(goal) < closest->distanceTo(goal)) {
      closest = cur;
    }
  }
  return closest;
}
Path::~Path() {}
bool Path::genPath(Tile *start, Tile *finish) {
  path.clear();
  std::vector<Tile *> used;
  Tile *curTile = start;
  int tries = 0;
  do {
    curTile = getNextAdjacentTile(curTile, finish, &used);
    tries++;
    if (curTile == finish) {
      break;
    }
    this->path.push_back(curTile);
  } while (curTile != finish && tries < 10000);
  if (curTile != finish) {
    std::cout << "could not find path" << std::endl;
    return false;
  } else {
    return true;
  }
}
