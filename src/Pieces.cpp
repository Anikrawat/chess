#include "Pieces.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <iostream>

Pieces::Pieces(SDL_Renderer *renderer) {
  loadTexture(this->black | this->Pawn, "assets/Pieces/black-pawn.png",
              renderer);
  loadTexture(this->black | this->King, "assets/Pieces/black-king.png",
              renderer);
  loadTexture(this->black | this->Queen, "assets/Pieces/black-queen.png",
              renderer);
  loadTexture(this->black | this->Knight, "assets/Pieces/black-knight.png",
              renderer);
  loadTexture(this->black | this->Rook, "assets/Pieces/black-rook.png",
              renderer);
  loadTexture(this->black | this->Bishop, "assets/Pieces/black-bishop.png",
              renderer);
  loadTexture(this->white | this->Pawn, "assets/Pieces/white-pawn.png",
              renderer);
  loadTexture(this->white | this->King, "assets/Pieces/white-king.png",
              renderer);
  loadTexture(this->white | this->Queen, "assets/Pieces/white-queen.png",
              renderer);
  loadTexture(this->white | this->Knight, "assets/Pieces/white-knight.png",
              renderer);
  loadTexture(this->white | this->Bishop, "assets/Pieces/white-bishop.png",
              renderer);
  loadTexture(this->white | this->Rook, "assets/Pieces/white-rook.png",
              renderer);
}

void Pieces::loadTexture(int pieceName, std::string path,
                         SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load(path.c_str());
  if (!surface) {
    std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
    return;
  }
  PieceSprite *piece = new PieceSprite();

  piece->texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_FreeSurface(surface);

  if (!piece->texture) {
    std::cerr << "Failed to create texture from " << path << ": "
              << SDL_GetError() << std::endl;
    return;
  }

  this->piecesSprites[pieceName] = piece;
}

void Pieces::drawPieces(SDL_Renderer *renderer) {
  for (const auto &pair : this->piecesSprites) {
    pair.second->dest.x = 100;
    pair.second->dest.y = 100;
    pair.second->dest.w = 100;
    pair.second->dest.h = 100;
    SDL_RenderCopy(renderer, pair.second->texture, NULL, &pair.second->dest);
  }
}

void Pieces::cleanup() {
  for (const auto &pair : this->piecesSprites) {
    SDL_DestroyTexture(pair.second->texture);
    IMG_Quit();
  }
}
