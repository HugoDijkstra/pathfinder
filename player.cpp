#include "player.h"

Player::Player(int x, int y) {
  this->x = x;
  this->y = y;
  rect.x = x * 16;
  rect.y = y * 16;
  rect.w = 16;
  rect.h = 16;
}

Player::~Player() {}
