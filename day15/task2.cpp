#include <iostream>
#include <unordered_map>

int main() {
  unsigned last_spoken;
  unsigned current_turn = 1;
  std::unordered_map<unsigned, unsigned> val_to_last_spoken;
  std::cin >> last_spoken;
  while (!std::cin.eof()) {
    val_to_last_spoken[last_spoken] = current_turn++;
    std::cin >> last_spoken;
    std::cin >> std::ws;
  }
  while (current_turn < 30000000) {
    if (val_to_last_spoken.count(last_spoken) == 0) {
      val_to_last_spoken[last_spoken] = current_turn++;
      last_spoken = 0;
    } else {
      unsigned dist = current_turn - val_to_last_spoken[last_spoken];
      val_to_last_spoken[last_spoken] = current_turn;
      last_spoken = dist;
      ++current_turn;
    }
  }
  std::cout << "Turn\t" << current_turn << " last spoken\t" << last_spoken
            << '\n';
}
