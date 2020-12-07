#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct child {
  unsigned count;
  std::string name;
};

// i know i shouldn't
std::unordered_map<std::string, std::vector<child>> items;

static unsigned count_all(const std::string &current_node) {
  unsigned sum = 1;
  for (const auto &c : items[current_node]) {
    sum += c.count * count_all(c.name);
  }
  return sum;
}

int main() {
  while (!std::cin.eof()) {
    int itemcount;
    std::cin >> itemcount;
    std::string parent;
    std::cin >> parent;
    std::cout << parent << '\n';
    for (int i = 0; i < itemcount; ++i) {
      child c;
      std::cin >> c.count >> c.name;
      items[parent].emplace_back(std::move(c));
    }
    std::cin >> std::ws;
  }
  std::cout << count_all("shiny_gold") - 1 << '\n';
  return 0;
}
