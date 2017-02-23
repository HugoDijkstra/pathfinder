#include "finish.h"
#include "path.h"
#include "player.h"
#include "tile.h"
#include <SDL2/SDL.h>
#include <iostream>
int main(int argc, char const *argv[]) {
  Finish *finish = new Finish(9, 11);
  Player *player = new Player(2, 2);
  Tile *tiles[12][12];
  int gridSize = 12;
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      Tile *t = new Tile(true, 4, 16 * i, 16 * j, 16, 16);
      tiles[i][j] = t;
    }
  }
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      if (i > 0)
        tiles[i][j]->adjacent[0] = tiles[i - 1][j];
      if (j > 0)
        tiles[i][j]->adjacent[1] = tiles[i][j - 1];
      if (i < 12)
        tiles[i][j]->adjacent[2] = tiles[i + 1][j];
      if (j < 12)
        tiles[i][j]->adjacent[3] = tiles[i][j + 1];
    }
  }
  SDL_Window *window;
  SDL_Renderer *renderer;
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
  }
  window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  renderer = SDL_CreateRenderer(window, 0, 0);

  tiles[6][0]->walkable = false;
  tiles[6][1]->walkable = false;
  tiles[6][2]->walkable = false;
  tiles[6][3]->walkable = false;
  tiles[6][4]->walkable = false;
  tiles[6][5]->walkable = false;
  tiles[6][7]->walkable = false;
  tiles[6][8]->walkable = false;
  tiles[6][9]->walkable = false;
  tiles[6][10]->walkable = false;
  tiles[5][10]->walkable = false;
  tiles[4][10]->walkable = false;
  tiles[3][10]->walkable = false;
  tiles[2][10]->walkable = false;
  tiles[2][11]->walkable = false;

  Path *path = new Path();
  bool pathFound =
      path->genPath(tiles[(int)player->rect.x / 16][(int)player->rect.y / 16],
                    tiles[(int)finish->rect.x / 16][(int)finish->rect.y / 16]);
  if (pathFound)
    std::cout << "Path found" << std::endl;

  bool mustQuit = false;
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  while (!mustQuit) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    SDL_RenderClear(renderer);
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        mustQuit = true;
      }
    }
    std::vector<Tile *> p = path->getPath();
    for (int i = 0; i < gridSize; i++) {
      for (int j = 0; j < gridSize; j++) {
        if (std::find(p.begin(), p.end(), tiles[i][j]) != p.end()) {
          SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        } else if (tiles[i][j]->walkable)
          SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else
          SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderDrawRect(renderer, &tiles[i][j]->rect);
      }
    }
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &finish->rect);
    SDL_SetRenderDrawColor(renderer, 35, 35, 255, 255);
    SDL_RenderFillRect(renderer, &player->rect);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
