#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<unsigned> joltages;
  joltages.push_back(0);
  while (!std::cin.eof()) {
    unsigned jolt;
    std::cin >> jolt;
    joltages.push_back(jolt);
    std::cin >> std::ws;
  }
  std::sort(begin(joltages), end(joltages));
  unsigned one_diff = 0;
  unsigned three_diff = 1;
  auto left = begin(joltages);
  for (auto right = next(left); right != end(joltages); ++right, ++left) {
    auto diff = *right - *left;
    if (diff == 1)
      ++one_diff;
    if (diff == 3)
      ++three_diff;
  }
  std::cout << one_diff << ' ' << three_diff << ' ' << one_diff * three_diff
            << '\n';
  return 0;
}
