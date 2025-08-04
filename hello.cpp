#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string str, char del) {

  int start = 0, end = 0;
  std::vector<std::string> splitedStr;

  while ((end = str.find(del, start)) != std::string::npos) {
    splitedStr.push_back(str.substr(start, end - start));
    start = end + 1;
  }

  // push the last segment (after last delimiter)
  splitedStr.push_back(str.substr(start));
  return splitedStr;
}

int main() {
  std::string fenCode =
      "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  std::vector<std::string> fenSplitted = split(fenCode, ' ');

  for (const auto fen : fenSplitted) {
    std::cout << fen << std::endl;
  }
  return 0;
}
