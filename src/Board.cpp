#include "Board.hpp"
#include "Globals.hpp"
#include <SDL2/SDL_render.h>
#include <iostream>
Board::Board() {

  for (int rank = 7; rank >= 0; rank--) {
    for (int file = 0; file < 8; file++) {
      Cell square;
      square.rectangle.rect.x = boardX + file * cellSize;
      square.rectangle.rect.y = boardY + rank * cellSize;
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
  }
}

void Board::draw(SDL_Renderer *renderer) {
  // std::cout << "Loop started" << std::endl;
  for (const auto &square : squares) {
    // std::cout << "{ " << square.rectangle.rect.x + 10 << ","
    //         << square.rectangle.rect.y + 10 << " }" << std::endl;
    SDL_SetRenderDrawColor(renderer, square.rectangle.color.r,
                           square.rectangle.color.g, square.rectangle.color.b,
                           square.rectangle.color.a);
    SDL_RenderFillRect(renderer, &square.rectangle.rect);
  }
}
