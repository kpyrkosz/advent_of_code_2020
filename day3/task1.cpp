#include <iostream>
#include <string>

int main() {
  std::string line;
  unsigned pos = 0;
  unsigned total_trees = 0;
  while (std::getline(std::cin, line)) {
    if (line[pos] == '#')
      ++total_trees;
    pos += 3;
    pos %= line.size();
  }
  std::cout << total_trees << '\n';
  return 0;
}
