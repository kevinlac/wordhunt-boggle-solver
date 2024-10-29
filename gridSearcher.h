#pragma once
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

#include "trie.h"

class gridSearcher {
 private:
  Trie listOfWords;
  std::vector<std::vector<char>> words;
  void gridSearcherHelper(
      int currX, int currY,
      std::map<int, std::unordered_set<std::string>>& foundWords,
      TrieNode* currentNode, std::vector<std::pair<int, int>>& directions,
      std::string& currString);

 public:
  gridSearcher(std::string filepath);
  bool updateBoard(std::string board);
  std::map<int, std::unordered_set<std::string>> search();
};