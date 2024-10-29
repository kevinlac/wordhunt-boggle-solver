#pragma once
#include <cassert>
#include <fstream>

#include "../trie.h"

class trieTest {
 private:
  void testInsert() {
    Trie trie;
    assert(trie.insert("he"));
    assert(trie.insert("hello"));
    assert(trie.insert("hell"));
    assert(trie.insert("phone"));
    assert(trie.insert(""));
    assert(trie.insert("1") == false);
    assert(trie.insert("@") == false);
    assert(trie.insert("hel1o") == false);
    assert(trie.insert("HELLO") == false);
  }
  void testExists() {
    Trie trie;
    std::ifstream words("tests/test_words.txt");
    std::string line;
    while (std::getline(words, line)) {
      trie.insert(line);
    }
    assert(trie.exists("apple"));
    assert(trie.exists("capsule"));
    assert(trie.exists("bus") == false);
  }

 public:
  void runTests() {
    // testInsert();
    testExists();
  }
};