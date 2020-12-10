#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<unsigned> joltages;
  while (!std::cin.eof()) {
    unsigned jolt;
    std::cin >> jolt;
    joltages.push_back(jolt);
    std::cin >> std::ws;
  }
  std::sort(begin(joltages), end(joltages));
  std::vector<unsigned long long> dyn_array(joltages.back() + 1);
  dyn_array[0] = 1;
  for (auto it = begin(joltages); it != end(joltages); ++it) {
    for (unsigned i = 0; i < std::min(3u, *it); ++i) {
      dyn_array[*it] += dyn_array[*it - i - 1];
    }
  }
  std::cout << dyn_array.back() << '\n';
  return 0;
}
