#include "Window.hpp"
#include "Globals.hpp"
#include <SDL2/SDL_render.h>
#include <iostream>

Window::Window() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
  }
  // Create a window
  this->window = SDL_CreateWindow("SDL2 Game Loop", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                                  WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

  if (!window) {
    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
    SDL_Quit();
  }
}

void Window::drawWindow(SDL_Renderer *windowRenderer) {
  SDL_SetRenderDrawColor(windowRenderer, 0, 0, 0,
                         255); // Black background

  SDL_RenderClear(windowRenderer);
}
