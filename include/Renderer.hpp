#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Board.hpp"
#include "Pieces.hpp"
#include "Window.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
class Renderer {
public:
  SDL_Renderer *windowRenderer;

  Renderer(Window *);
  void render(Board *, Window *, Pieces *);
};

#endif // !RENDERER_HPP
