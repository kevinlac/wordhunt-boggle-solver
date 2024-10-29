#pragma once
#include <string>
#include <vector>

struct TrieNode {
  bool isEnd;
  std::vector<TrieNode*> children;
  TrieNode() : isEnd(false), children(std::vector<TrieNode*>(26)) {}
};

class Trie {
 private:
  TrieNode* root;
  void destructorHelper(TrieNode* root);

 public:
  Trie();
  ~Trie();
  bool insert(std::string word);  // returns false if invalid input (strictly 16
                                  // chars lowercase alphabet)
  bool exists(std::string word);
  TrieNode* getRoot();
};
