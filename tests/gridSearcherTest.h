#pragma once
#include <cassert>

#include "../gridSearcher.h"

class gridSearcherTest {
 private:
  void testUpdate() {
    gridSearcher grid("tests/test_words.txt");
    assert(grid.updateBoard("abcdefghijklmnop"));
    assert(grid.updateBoard("fnewociugeoewgax"));
    assert(grid.updateBoard("oieghwelngviudsa"));
    assert(grid.updateBoard("") == false);
    assert(grid.updateBoard("dfaafFdasf8asdff") == false);
    assert(grid.updateBoard("****************") == false);
  }
  void testSearch() {
    gridSearcher grid("tests/test_words.txt");
    grid.updateBoard("applbusedpacmrxr");
    int wordsFound = 0;
    auto results = grid.search();
    for (auto i : results) {
      wordsFound += i.second.size();
    }
    assert(wordsFound == 5);
  }

 public:
  void runTests() {
    testUpdate();
    testSearch();
  }
};