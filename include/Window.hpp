#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

class Window {
public:
  SDL_Window *window;

public:
  Window();
  void drawWindow(SDL_Renderer *);
};

#endif // !WINDOW_HPP
