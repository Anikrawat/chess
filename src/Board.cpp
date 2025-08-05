#include "Board.hpp"
#include "Globals.hpp"
#include <SDL2/SDL_render.h>

Board::Board() {

  for (int file = 0; file < 8; file++) {
    for (int rank = 0; rank < 8; rank++) {
      Cell square;
      square.rectangle.rect.x = boardX;
      boardX += cellSize;
      square.rectangle.rect.y = boardY;
      square.rectangle.rect.w = cellSize;
      square.rectangle.rect.h = cellSize;

      if ((file + rank) % 2 == 0) {
        square.rectangle.color = {217, 195, 170, 1};
      } else {
        square.rectangle.color = {149, 104, 85, 1};
      }
      square.piecePosition = 0;
      squares.push_back(square);
    }
    boardY += cellSize;
    boardX = WINDOW_WIDTH / 2 - cellSize * 4;
  }
}

void Board::draw(SDL_Renderer *renderer) {
  for (const auto &square : squares) {
    SDL_SetRenderDrawColor(renderer, square.rectangle.color.r,
                           square.rectangle.color.g, square.rectangle.color.b,
                           square.rectangle.color.a);
    SDL_RenderFillRect(renderer, &square.rectangle.rect);
  }
}
