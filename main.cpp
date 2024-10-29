#include <chrono>
#include <iostream>

#include "gridSearcher.h"

int main() {
  gridSearcher* grid;
  try {
    grid = new gridSearcher("words.txt");
  } catch (const std::invalid_argument& e) {
    std::cout << "invalid words file path" << std::endl;
    return 0;
  }
  std::string input;
  std::cout << "Enter board: ";
  while (std::getline(std::cin, input) && !input.empty()) {
    auto start = std::chrono::steady_clock::now();
    if (grid->updateBoard(input)) {
      for (auto i : grid->search()) {
        std::cout << "Words with length " << i.first << ":" << std::endl;
        for (auto word : i.second) {
          std::cout << word << " ";
        }
        std::cout << std::endl;
      }
      auto end = std::chrono::steady_clock::now();
      std::cout
          << "Results generated in "
          << std::chrono::duration<double, std::milli>(end - start).count()
          << " ms" << std::endl;
    }
    std::cout << "Enter board: ";
  }
  delete grid;
}
