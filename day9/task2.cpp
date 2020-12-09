#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <expected_sum>\n";
    return 1;
  }
  unsigned long long expected_sum = std::strtoul(argv[1], nullptr, 10);
  std::vector<unsigned long long> vals;
  while (!std::cin.eof()) {
    unsigned long long val;
    std::cin >> val;
    vals.push_back(val);
    std::cin >> std::ws;
  }
  for (auto left = begin(vals); left != prev(end(vals)); ++left) {
    unsigned long long current_sum = *left;
    for (auto right = next(left); right != end(vals); ++right) {
      current_sum += *right;
      if (current_sum == expected_sum) {
        auto [min, max] = std::minmax_element(left, next(right));
        std::cout << *min << '+' << *max << '=' << *min + *max << '\n';
        return 0;
      }
      if (current_sum > expected_sum)
        break;
    }
  }
  return 0;
}
