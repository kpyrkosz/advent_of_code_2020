#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>

// triplet hashing based on https://stackoverflow.com/a/10982151
struct triplet {
  int a, b, c, d;
  bool operator<(triplet const &o) const {
    return std::tie(a, b, c, d) < std::tie(o.a, o.b, o.c, o.d);
  }
  bool operator==(triplet const &o) const {
    return std::tie(a, b, c, d) == std::tie(o.a, o.b, o.c, o.d);
  }
};

namespace std {
template <> struct hash<triplet> {
  unsigned int operator()(triplet const &key) const {
    return ~key.a + 17u * (key.b+101) + (97u * key.c+103) +
           379u * (key.d+22); // totally made that up, could be better, I suppose
  }
};
} // namespace std

using triplet_map = std::unordered_map<triplet, bool>;

static unsigned active_neighbour_count(const triplet &loc,
                                       const triplet_map &prev) {
  unsigned res = 0;
  for (int x = -1; x <= 1; ++x)
    for (int y = -1; y <= 1; ++y)
      for (int z = -1; z <= 1; ++z)
        for (int w = -1; w <= 1; ++w) {
          if (x == 0 && y == 0 && z == 0 && w == 0)
            continue;
          triplet curr_loc = loc; // this could probably be optimized in the
                                  // loops above, not to repeat the addition
          curr_loc.a += x;
          curr_loc.b += y;
          curr_loc.c += z;
          curr_loc.d += w;
          if (prev.count(curr_loc) && prev.at(curr_loc))
            ++res;
        }
  return res;
}

static triplet_map step(const triplet_map &prev) {
  triplet_map res;
  for (auto kv_pair : prev) { // copy, to be moved into res
    unsigned neighbours = active_neighbour_count(kv_pair.first, prev);
    if ((neighbours != 2 && neighbours != 3) && kv_pair.second)
      kv_pair.second = false;
    else if (!kv_pair.second && neighbours == 3)
      kv_pair.second = true;
    res.insert(kv_pair);
  }
  return res;
}

static unsigned count_true(const triplet_map &prev) {
  unsigned res = 0;
  for (const auto &kv_pair : prev) {
    if (kv_pair.second)
      ++res;
  }
  return res;
}

int main() {
  std::unordered_map<triplet, bool> area_to_active;
  std::string line;
  for (int x = -8; x <= 16; ++x)
    for (int y = -8; y <= 16; ++y)
      for (int z = -8; z <= 16; ++z)
        for (int w = -8; w <= 16; ++w)
          area_to_active[{x, y, z, w}] = false;
  int y = 0;
  while (std::getline(std::cin, line)) {
    int x = 0;
    for (auto c : line)
      area_to_active[{x++, y, 0, 0}] = (c == '#');
    ++y;
  }
  for (int i = 0; i < 7; ++i) {
    std::cout << count_true(area_to_active) << '\n';
    area_to_active = step(area_to_active);
  }
}
