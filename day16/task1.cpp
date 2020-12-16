#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream vals_in("vals");
  std::ifstream ranges_in("ranges");
  std::vector<std::pair<unsigned, unsigned>> ranges;
  while (!ranges_in.eof()) {
    unsigned begin;
    char separator;
    unsigned end;
    ranges_in >> begin >> separator >> end >> std::ws;
    std::cerr << begin << " - " << end << '\n';
    ranges.push_back({begin, end});
  }
  unsigned sum = 0;
  while (!vals_in.eof()) {
    unsigned val;
    vals_in >> val >> std::ws;
    std::cout << val << '\n';
    if (std::all_of(begin(ranges), end(ranges), [val](const auto pair) {
          return val < pair.first || val > pair.second;
        }))
      sum += val;
  }
  std::cout << sum << '\n';
  return 0;
}
