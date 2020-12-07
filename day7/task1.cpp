#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int main() {
  std::unordered_map<std::string, std::vector<std::string>> item_to_parents;
  while (!std::cin.eof()) {
    int itemcount;
    std::cin >> itemcount;
    std::string parent;
    std::cin >> parent;
    for (int i = 1; i < itemcount; ++i) {
      std::string child;
      std::cin >> child;
      item_to_parents[child].emplace_back(parent);
    }
    std::cin >> std::ws;
  }
  int sum = -1;
  std::queue<std::string> to_process;
  to_process.push("shiny_gold");
  std::unordered_set<std::string> processed;
  while (!to_process.empty()) {
    auto curr = std::move(to_process.front());
    to_process.pop();
    if (processed.count(curr))
      continue;
    processed.insert(curr);
    ++sum;
    for (const auto &p : item_to_parents[curr])
      to_process.push(p);
  }
  std::cout << sum << '\n';
  return 0;
}
