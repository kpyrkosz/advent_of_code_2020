#include <iostream>
#include <numeric>
#include <unordered_map>

int main() {
  std::unordered_map<unsigned long long, unsigned long long> values;
  unsigned long long or_mask =
      0; // ones on the "to set" positions and zeros on the rest
  unsigned long long and_mask = 0; // vice versa
  while (!std::cin.eof()) {
    char operation;
    std::cin >> operation;
    if (operation == 'm') {
      std::string mask;
      std::cin >> mask;
      and_mask = std::numeric_limits<unsigned long long>::max();
      or_mask = 0;
      unsigned long long temp_mask = 1;
      for (auto it = mask.rbegin(); it != mask.rend(); ++it) {
        if (*it == '0') {
          and_mask &= (~temp_mask);
        } else if (*it == '1') {
          or_mask |= (temp_mask);
        }
        temp_mask <<= 1;
      }
      std::cout << mask << ' ' << and_mask << ' ' << or_mask << '\n';
    } else if (operation == 'w') {
      unsigned long long index, val;
      std::cin >> index >> val;
      val |= or_mask;
      val &= and_mask;
      values[index] = val;
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
