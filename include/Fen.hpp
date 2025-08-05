#ifndef FEN_HPP
#define FEN_HPP

#include "Board.hpp"
#include "Pieces.hpp"
#include <string>
#include <vector>
class Fen {
private:
  std::vector<std::string> split(std::string, char);

public:
  int rank;
  int file;
  int pieceColor;
  int pieceType;
  std::string fenCode;
  void piecePosition(Pieces &pieceData, Board &board);
};

#endif // !FEN_HPP
