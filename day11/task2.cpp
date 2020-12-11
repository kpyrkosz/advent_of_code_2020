#include <iostream>
#include <string>
#include <vector>

static bool valid_coord(const std::vector<std::string> &state, unsigned h,
                        unsigned w) {
  return h > 0 && h < state.size() && w > 0 && w < state.front().size();
}

static unsigned occupied_around(const std::vector<std::string> &state,
                                unsigned h, unsigned w) {
  unsigned res = 0;
  for (unsigned i = 0; i <= 2; ++i)
    for (unsigned k = 0; k <= 2; ++k) {
      if (i == 1 && k == 1)
        continue;
      unsigned curr_h = h + i - 1;
      unsigned curr_w = w + k - 1;
      while (valid_coord(state, curr_h, curr_w) &&
             state[curr_h][curr_w] != 'L') {
        if (state[curr_h][curr_w] == '#') {
          ++res;
          break;
        }
        curr_h = curr_h + i - 1;
        curr_w = curr_w + k - 1;
      }
    }
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
            occupied_around(current_state, i, k) >= 5) {
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
