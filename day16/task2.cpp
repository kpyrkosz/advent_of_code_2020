#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct val_range {
  std::string name;
  unsigned begin_a;
  unsigned end_a;
  unsigned begin_b;
  unsigned end_b;
};

int main() {
  std::ifstream tickets_in("tickets");
  std::ifstream ranges_in("ranges");
  std::vector<val_range> ranges;
  while (!ranges_in.eof()) {
    val_range v;
    ranges_in >> v.name >> v.begin_a >> v.end_a >> v.begin_b >> v.end_b >>
        std::ws;
    std::cerr << v.name << v.begin_a << v.end_a << v.begin_b << v.end_b << '\n';
    ranges.emplace_back(std::move(v));
  }
  // failed[i][k] == true means that column i cannot fit into val_range k
  std::vector<std::vector<unsigned>> failed(
      ranges.size(), std::vector<unsigned>(ranges.size(), 0));
  while (!tickets_in.eof()) {
    std::vector<unsigned> current_line;
    bool is_valid = true;

    for (unsigned i = 0; i < ranges.size(); ++i) {
      unsigned val;
      tickets_in >> val;
      std::cerr << val << ' ';
      current_line.push_back(val);
      if (std::all_of(begin(ranges), end(ranges), [val](const val_range &r) {
            if (val >= r.begin_a && val <= r.end_a)
              return false;
            if (val >= r.begin_b && val <= r.end_b)
              return false;
            return true;
          }))
        is_valid = false;
    }
    if (!is_valid) {
      std::cerr << "CHUJ\n";
      continue;
    }
    for (unsigned i = 0; i < ranges.size(); ++i) {
      auto val = current_line[i];
      for (unsigned k = 0; k < ranges.size(); ++k) {
        if (val >= ranges[k].begin_a && val <= ranges[k].end_a)
          continue;
        if (val >= ranges[k].begin_b && val <= ranges[k].end_b)
          continue;
        failed[i][k] = true;
      }
    }
    std::cerr << '\n';
    tickets_in >> std::ws;
  }

  for (unsigned i = 0; i < ranges.size(); ++i) {
    for (unsigned k = 0; k < ranges.size(); ++k) {
      std::cerr << failed[i][k];
    }
    std::cerr << '\n';
  }

  bool fixed = true;
  unsigned row_num = 0;
  while (fixed && row_num < ranges.size()) {
    fixed = false;
    unsigned zero_index = 0;
    unsigned FUCK_THIS_SHIT = 'f' + 'u' + 'c' + 'k';
    for (unsigned i = 0; i < ranges.size(); ++i) {
      unsigned zero_count = 0;
      zero_index = 0;
      for (unsigned k = 0; k < ranges.size(); ++k) {
        if (!failed[i][k]) {
          ++zero_count;
          zero_index = k;
        }
      }
      if (zero_count == 1) {
        FUCK_THIS_SHIT = i;
        fixed = true;
        break;
      }
    }
    std::cout << "Column " << FUCK_THIS_SHIT << ' ' << ranges[zero_index].name
              << ' ' << '\n';
    ++row_num;
    for (unsigned k = 0; k < ranges.size(); ++k)
      failed[k][zero_index] = true;
  }
  return 0;
}
