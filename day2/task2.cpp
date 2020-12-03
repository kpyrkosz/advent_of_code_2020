#include <algorithm>
#include <iostream>
#include <string>

int main() {
  int result = 0;
  while (!std::cin.eof()) {
    unsigned low, up;
    char digit;
    std::string text;
    std::cin >> low >> up >> digit >> text;
    int count = 0;
    if (text[low - 1] == digit)
      ++count;
    if (text[up - 1] == digit)
      ++count;
    if (count == 1)
      ++result;
    std::cin >> std::ws;
  }
std::cout<<result;
}
