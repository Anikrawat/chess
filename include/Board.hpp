#ifndef BOARD_HPP
#define BOARD_HPP

#include "Globals.hpp"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <vector>

class Board {
private:
  std::vector<Rectangle> cells;
  int cellSize = 120;
  int boardX = WINDOW_WIDTH / 2 - cellSize * 4;
  int boardY = WINDOW_HEIGHT / 2 - cellSize * 4;

public:
  Board();
  void draw(SDL_Renderer *renderer);
};

#endif // !BOARD_HPP
