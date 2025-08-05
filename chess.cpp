#include "Board.hpp"
#include "Fen.hpp"
#include "ImageInit.hpp"
#include "Pieces.hpp"
#include "Renderer.hpp"
#include "Window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>

int main() {
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
  SDL_Event event;

  while (running) {
    // --- 1. Handle Events ---
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }

    framestart = SDL_GetTicks();

    // --- 2. Update Game Logic ---
    // (Add logic here, e.g., moving objects, collisions)

    renderer.render(board, window, pieceSprite);
    //  --- 3. Render ---
    //  --- 4. Cap Framerate (optional) ---
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
