#include "ImageInit.hpp"
#include <iostream>

Imageinit::Imageinit() {
  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    std::cerr << "SDL_image could not initialize! SDL_image Error: "
              << IMG_GetError() << std::endl;
  }
}
