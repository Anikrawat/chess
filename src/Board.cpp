#include "Board.hpp"
#include "Globals.hpp"
#include <SDL2/SDL_render.h>

Board::Board() {

  for (int file = 0; file < 8; file++) {
    for (int rank = 0; rank < 8; rank++) {
      Rectangle cell;
      cell.rect.x = boardX;
      boardX += cellSize;
      cell.rect.y = boardY;
      cell.rect.w = cellSize;
      cell.rect.h = cellSize;

      if ((file + rank) % 2 == 0) {
        cell.color = {217, 195, 170, 1};
      } else {
        cell.color = {149, 104, 85, 1};
      }
      cells.push_back(cell);
    }
    boardY += cellSize;
    boardX = WINDOW_WIDTH / 2 - cellSize * 4;
  }
}

void Board::draw(SDL_Renderer *renderer) {
  for (const auto &cell : cells) {
    SDL_SetRenderDrawColor(renderer, cell.color.r, cell.color.g, cell.color.b,
                           cell.color.a);
    SDL_RenderFillRect(renderer, &cell.rect);
  }
}
