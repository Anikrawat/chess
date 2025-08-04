#ifndef PIECES_HPP
#define PIECES_HPP

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <map>
#include <string>
class Pieces {
public:
  class PieceSprite {
  public:
    SDL_Texture *texture;
    SDL_Rect dest;
  };

  const int None = 0;
  const int King = 1;
  const int Queen = 2;
  const int Knight = 3;
  const int Bishop = 4;
  const int Rook = 5;
  const int Pawn = 6;

  const int black = 8;
  const int white = 16;

  std::map<int, PieceSprite *> piecesSprites;
  // std::vector<PieceSprite *> piecesSprites;
  Pieces(SDL_Renderer *renderer);
  void loadTexture(int, std::string, SDL_Renderer *);
  void drawPieces(SDL_Renderer *renderer);
  void cleanup();
};

#endif // !PIECES_HPP
