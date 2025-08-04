#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

class Rectangle {
public:
  SDL_Rect rect;
  SDL_Color color;
};

#endif // !GLOBALS_HPP
