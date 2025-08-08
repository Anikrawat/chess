#include "Board.hpp"
#include "Events.hpp"
#include "Fen.hpp"
#include "ImageInit.hpp"
#include "Pieces.hpp"
#include "Renderer.hpp"
#include "Window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <sys/types.h>

int main() {

  int mouseX, mouseY;

  // Window Inititalization
  Window window;
  // Create a renderer
  Renderer renderer(window);
  // Board Inititalization
  Board board;

  Fen fen;
  // Image object Inititalization
  Imageinit *imageInitialization = new Imageinit();

  // Sprites
  Pieces pieceSprite(renderer.windowRenderer);

  fen.piecePosition(pieceSprite, board);

  const int TARGET_FPS = 60;
  const int FRAME_DELAY_MS = 1000 / TARGET_FPS;
  Uint32 framestart;
  int frametime;

  // === Game Loop ===
  bool running = true;
  Events events;

  while (running) {

    events.allEvents(running, board);

    framestart = SDL_GetTicks();

    // Update Game Logic
    // Renderer.
    renderer.render(board, window, pieceSprite);

    // Frame Rate.
    frametime = SDL_GetTicks() - framestart;
    if (FRAME_DELAY_MS > frametime) {
      SDL_Delay(FRAME_DELAY_MS - frametime);
    }
  }

  // Cleanup
  pieceSprite.cleanup();
  SDL_DestroyRenderer(renderer.windowRenderer);
  SDL_DestroyWindow(window.window);
  SDL_Quit();
  return 0;
}
