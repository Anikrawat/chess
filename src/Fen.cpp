#include "Fen.hpp"
#include "Board.hpp"
#include "Pieces.hpp"
#include <cctype>
#include <iostream>
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

void Fen::piecePosition(Pieces &pieceData, Board &board) {

  std::map<char, int> pieceTypeFromSymbol = {
      {'k', pieceData.King},   {'q', pieceData.Queen},  {'r', pieceData.Rook},
      {'b', pieceData.Bishop}, {'n', pieceData.Knight}, {'p', pieceData.Pawn}};

  this->fenCode = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  // this->fenCode = "2R5/8/8/4r3/8/2p5/4N3/8 w - - 0 1";
  std::string fenPiecePosition = split(this->fenCode, ' ').at(0);
  this->rank = 7;
  this->file = 0;

  for (const char piece : fenPiecePosition) {
    if (piece == '/') {
      this->file = 0;
      this->rank--;
    } else {
      if (std::isdigit(piece)) {
        this->file += piece - '0';
      } else {
        this->pieceColor =
            std::isupper(piece) ? pieceData.white : pieceData.black;
        this->pieceType = pieceTypeFromSymbol[std::tolower(piece)];
        board.squares[rank * 8 + file].piecePosition = pieceColor | pieceType;
        std::cout << board.squares[rank * 8 + file].piecePosition << std::endl;
        file++;
      }
    }
  }
}
