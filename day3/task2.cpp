#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <right step> <down step>\n";
    return 1;
  }
  unsigned right_step = std::stoul(argv[1], nullptr, 0);
  unsigned down_step = std::stoul(argv[2], nullptr, 0);
  if (right_step == 0 || down_step == 0) {
    std::cerr << "Both right and down step have to be positive integers\n";
    return 1;
  }
  std::string line;
  unsigned pos = 0;
  unsigned total_trees = 0;
  while (std::getline(std::cin, line)) {
    if (line[pos] == '#')
      ++total_trees;
    pos += right_step;
    pos %= line.size();
    for (unsigned i = 1; i < down_step; ++i) {
      std::getline(std::cin, line);
    }
  }
  std::cout << total_trees << '\n';
  return 0;
}
