#include "trie.h"

Trie::Trie() : root(new TrieNode()) {}

Trie::~Trie() { destructorHelper(root); }

void Trie::destructorHelper(TrieNode* root) {
  for (auto i : root->children) {
    if (i != nullptr) {
      destructorHelper(i);
    }
  }
  delete root;
  root = nullptr;
}

bool Trie::insert(std::string word) {
  for (int i = 0; i < word.length(); i++) {
    if (word[i] < 'a' || word[i] > 'z') return false;
  }
  TrieNode* currentNode = root;
  for (int i = 0; i < word.length(); i++) {
    if (currentNode->children[word[i] - 'a'] == nullptr) {
      currentNode->children[word[i] - 'a'] = new TrieNode();
    }
    currentNode = currentNode->children[word[i] - 'a'];
  }
  currentNode->isEnd = true;
  return true;
}

bool Trie::exists(std::string word) {
  TrieNode* currentNode = root;
  for (char i : word) {
    if (i < 'a' || i > 'z') return false;
    if (currentNode->children[i - 'a'] == nullptr) return false;
    currentNode = currentNode->children[i - 'a'];
  }
  if (currentNode->isEnd == false) return false;
  return true;
}

TrieNode* Trie::getRoot() { return root; }