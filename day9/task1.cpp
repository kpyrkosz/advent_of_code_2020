#include <algorithm>
#include <iostream>
#include <vector>

static bool try_sum(std::vector<unsigned> head, unsigned expected_sum) {
  std::sort(begin(head), end(head));
  auto left = begin(head);
  auto right = prev(end(head));
  while (left != right) {
    auto sum = *left + *right;
    if (sum == expected_sum)
      return true;
    if (sum < expected_sum)
      ++left;
    else
      --right;
  }
  return false;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <preamble size>\n";
    return 1;
  }
  unsigned preamble_size = static_cast<unsigned>(std::atoi(argv[1]));
  std::vector<unsigned> head;
  for (unsigned i = 0; i < preamble_size; ++i) {
    unsigned val;
    std::cin >> val;
    head.push_back(val);
  }
  unsigned first_val_index = 0;
  while (!std::cin.eof()) {
    unsigned val;
    std::cin >> val;
    if (!try_sum(head, val)) {
      std::cout << "Cannot represent " << val << " using";
      for (const auto &i : head)
        std::cout << ' ' << i;
      std::cout << '\n';
      return 0;
    }
    head[first_val_index++] = val;
    first_val_index %= preamble_size;
    std::cin >> std::ws;
  }
  return 0;
}
