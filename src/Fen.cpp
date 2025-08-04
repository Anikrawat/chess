#include "Fen.hpp"
#include "Pieces.hpp"
#include <cctype>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> Fen::split(std::string str, char del) {

  int start = 0, end = 0;
  std::vector<std::string> splitedStr;

  while ((end = str.find(del, start)) != std::string::npos) {
    splitedStr.push_back(str.substr(start, end - start));
    start = end + 1;
  }

  splitedStr.push_back(str.substr(start));
  return splitedStr;
}

void Fen::piecePosition(Pieces pieceData) {

  std::map<char, int> pieceTypeFromSymbol = {
      {'k', pieceData.King},   {'q', pieceData.Queen},  {'r', pieceData.Rook},
      {'b', pieceData.Bishop}, {'n', pieceData.Knight}, {'p', pieceData.Pawn}};

  this->fenCode = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  std::string fenPiecePosition = split(this->fenCode, ' ').at(0);
  this->rank = 7;
  this->file = 0;

  for (const char piece : fenPiecePosition) {
    if (std::isdigit(piece)) {
      this->file += piece - '0';
    } else {
      if (piece == '/') {
        this->file = 0;
        this->rank--;
      } else {
        this->pieceColor =
            std::isupper(piece) ? pieceData.white : pieceData.black;
        this->pieceType = pieceTypeFromSymbol[std::tolower(piece)]
      }
    }
  }
}
