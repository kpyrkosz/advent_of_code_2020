#include <iostream>
#include <string>
#include <vector>

static unsigned occupied_around(const std::vector<std::string> &state,
                                unsigned h, unsigned w) {
  unsigned res = 0;
  for (unsigned i = 0; i <= 2; ++i)
    for (unsigned k = 0; k <= 2; ++k)
      if (state[h + i - 1][w + k - 1] == '#')
        ++res;
  if (state[h][w] == '#')
    --res;
  return res;
}

int main() {
  unsigned height, width;
  std::cin >> height >> width;
  std::cin >> std::ws;
  std::vector<std::string> current_state;
  for (unsigned i = 0; i < height + 2; ++i) {
    std::string line;
    std::cin >> line;
    std::cout << line << '\n';
    current_state.push_back(std::move(line));
  }
  bool was_changed = false;
  do {
    was_changed = false;
    std::vector<std::string> next_state(current_state);
    for (unsigned i = 1; i < height + 1; ++i)
      for (unsigned k = 1; k < width + 1; ++k) {
        if (current_state[i][k] == 'L' &&
            occupied_around(current_state, i, k) == 0) {
          was_changed = true;
          next_state[i][k] = '#';
        }
        if (current_state[i][k] == '#' &&
            occupied_around(current_state, i, k) >= 4) {
          was_changed = true;
          next_state[i][k] = 'L';
        }
      }
    std::swap(current_state, next_state);
  } while (was_changed);
  unsigned hashcount = 0;
  for (unsigned i = 1; i < height + 1; ++i)
    for (unsigned k = 1; k < width + 1; ++k)
      if (current_state[i][k] == '#')
        ++hashcount;
  std::cout << hashcount << '\n';
  return 0;
}
