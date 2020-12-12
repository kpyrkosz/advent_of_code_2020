#include <cmath>
#include <iostream>

int main() {
  int x = 0;
  int y = 0;
  int direction = 0;

  while (!std::cin.eof()) {
    char action;
    int operand;
    std::cin >> action >> operand >> std::ws;
    switch (action) {
    case 'N':
      y += operand;
      break;
    case 'S':
      y -= operand;
      break;
    case 'E':
      x += operand;
      break;
    case 'W':
      x -= operand;
      break;
    case 'L':
      direction += operand;
      direction %= 360;
      break;
    case 'R':
      direction += 360;
      direction -= operand;
      direction %= 360;
      break;
    case 'F':
      switch (direction) {
      case 0:
        x += operand;
        break;
      case 90:
        y += operand;
        break;
      case 180:
        x -= operand;
        break;
      case 270:
        y -= operand;
        break;
      default:
        std::cerr << "Wrong angle: " << direction << '\n';
        return 1;
      }
      break;
    default:
      std::cerr << "Unknown action, aborting: " << action << '\n';
      return 1;
    }
  }
  std::cout << x << ' ' << y << ' ' << abs(x) + abs(y) << '\n';
  return 0;
}
