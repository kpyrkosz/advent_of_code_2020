#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using vec = std::vector<unsigned long long>;

// my brain is not working today..
static vec gen_combos(vec in, vec floating) {
  if (floating.empty())
    return in;
  vec res;
  for (const auto &qq : in) {
    res.push_back(qq | floating.back());
    res.push_back(qq & (~floating.back()));
  }
  floating.pop_back();
  return gen_combos(res, floating);
}

int main() {
  std::unordered_map<unsigned long long, unsigned long long> values;
  vec floating;
  unsigned long long or_mask = 0;
  while (!std::cin.eof()) {
    char operation;
    std::cin >> operation;
    if (operation == 'm') {
      std::string mask;
      std::cin >> mask;
      floating.clear();
      or_mask = 0;
      unsigned long long temp_mask = 1;
      for (auto it = mask.rbegin(); it != mask.rend(); ++it) {
        if (*it == 'X') {
          floating.push_back(temp_mask);

        } else if (*it == '1') {
          or_mask |= (temp_mask);
        }
        temp_mask <<= 1;
      }
      std::cout << mask << ' ' << or_mask << '\n';
    } else if (operation == 'w') {
      unsigned long long index, val;
      std::cin >> index >> val;
      index |= or_mask;
      std::cerr << "Index " << index << ' ' << floating.size() << '\n';
      auto combos = gen_combos({index}, floating);
      for (auto &i : combos)
        values[i] = val;
    } else {
      std::cerr << "Unknown operation " << operation << '\n';
      return 1;
    }
    std::cin >> std::ws;
  }
  unsigned long long sum = 0;
  for (const auto &kv : values) {
    std::cerr << kv.first << ' ' << kv.second << '\n';
    sum += kv.second;
  }
  std::cout << sum << '\n';
  return 0;
}
