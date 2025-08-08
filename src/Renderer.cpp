#include "Renderer.hpp"
#include "Board.hpp"
#include "Pieces.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>

Renderer::Renderer(Window window) {
  this->windowRenderer =
      SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED);

  if (!windowRenderer) {
    std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
    SDL_DestroyWindow(window.window);
    SDL_Quit();
  }
}

void Renderer::render(Board &board, Window &window, Pieces &pieceSprite) {

  window.drawWindow(this->windowRenderer);
  board.draw(this->windowRenderer);
  for (const auto &square : board.squares) {
    // std::cout << square.piecePosition << std::endl;
    pieceSprite.drawPieces(this->windowRenderer, square.piecePosition,
                           square.rectangle.rect);
  }
  SDL_RenderPresent(this->windowRenderer);
}
