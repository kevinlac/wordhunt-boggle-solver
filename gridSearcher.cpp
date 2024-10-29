#include "gridSearcher.h"

#include <fstream>
#include <stdexcept>

gridSearcher::gridSearcher(std::string filepath)
    : words(std::vector<std::vector<char>>(4, std::vector<char>(4))) {
  std::ifstream words(filepath);
  if (!words.is_open()) {
    throw std::invalid_argument("file not found");
  } else {
    std::string line;
    while (std::getline(words, line)) {
      listOfWords.insert(line);
    }
  }
}

bool gridSearcher::updateBoard(std::string board) {
  if (board.length() != 16) return false;
  for (char i : board) {
    if (i < 'a' || i > 'z') return false;
  }
  for (int i = 0; i < 16; i++) {
    words[i / 4][i % 4] = board[i];
  }
  return true;
}

std::map<int, std::unordered_set<std::string>> gridSearcher::search() {
  // word length : found words
  std::map<int, std::unordered_set<std::string>> foundWords;
  std::vector<std::pair<int, int>> directions = {
      {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
  std::string currString;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (listOfWords.getRoot()->children[words[i][j] - 'a'] != nullptr) {
        gridSearcherHelper(j, i, foundWords, listOfWords.getRoot(), directions,
                           currString);
      }
    }
  }

  return foundWords;
}

void gridSearcher::gridSearcherHelper(
    int currX, int currY,
    std::map<int, std::unordered_set<std::string>>& foundWords,
    TrieNode* currentNode, std::vector<std::pair<int, int>>& directions,
    std::string& currString) {
  if (currX < 0 || currX >= 4 || currY < 0 || currY >= 4) return;
  if (words[currY][currX] == '#') return;
  if (currentNode->children[words[currY][currX] - 'a'] == nullptr) return;

  currentNode = currentNode->children[words[currY][currX] - 'a'];
  currString += words[currY][currX];

  if (currentNode->isEnd &&
      !foundWords[currString.length()].count(currString)) {
    foundWords[currString.length()].insert(currString);
  }
  char temp = words[currY][currX];
  words[currY][currX] = '#';
  for (auto direction : directions) {
    gridSearcherHelper(currX + direction.first, currY + direction.second,
                       foundWords, currentNode, directions, currString);
  }
  currString.pop_back();
  words[currY][currX] = temp;
}