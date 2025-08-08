#include "Events.hpp"
#include "Board.hpp"
#include <iostream>

void Events::allEvents(bool &running, Board &board) {
  // Handle Events.
  while (SDL_PollEvent(&this->event)) {
    if (this->event.type == SDL_QUIT) {
      running = false;
    }

    if (this->event.type == SDL_MOUSEBUTTONDOWN) {
      if (this->event.button.button == SDL_BUTTON_LEFT) {

        SDL_GetMouseState(&mouseX, &mouseY);

        int relativeX = mouseX - board.boardX;
        int relativeY = mouseY - board.boardY;

        if ((relativeX >= 0 && relativeX < board.cellSize * 8) &&
            (relativeY >= 0 && relativeY < board.cellSize * 8)) {

          int file = relativeX / board.cellSize;
          int rank = 7 - (relativeY / board.cellSize);

          std::cout << "{ " << rank << "," << file << " }" << std::endl;

          board.squares[rank * 8 + file].rectangle.color = {255, 0, 0, 255};
        }
      }
    }
  }
}
