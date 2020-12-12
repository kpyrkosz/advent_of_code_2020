#include <cmath>
#include <iostream>

static std::pair<int, int> rotate(int x, int y, int angle) {
  switch (angle) {
  case 90:
    return {-y, x};
  case 180:
    return {-x, -y};
  case 270:
    return {y, -x};
  default:
    throw std::invalid_argument("Wrong angle: " + std::to_string(angle));
  }
}

int main() {
  int waypoint_x = 10;
  int waypoint_y = 1;
  int x = 0;
  int y = 0;

  while (!std::cin.eof()) {
    char action;
    int operand;
    std::cin >> action >> operand >> std::ws;
    if (action == 'R') {
      action = 'L';
      operand = 360 - operand;
    }
    switch (action) {
    case 'N':
      waypoint_y += operand;
      break;
    case 'S':
      waypoint_y -= operand;
      break;
    case 'E':
      waypoint_x += operand;
      break;
    case 'W':
      waypoint_x -= operand;
      break;
    case 'L': {
      auto rotated = rotate(waypoint_x, waypoint_y, operand);
      waypoint_x = rotated.first;
      waypoint_y = rotated.second;
    } break;
    case 'F':
      x += waypoint_x * operand;
      y += waypoint_y * operand;
      break;
    default:
      std::cerr << "Unknown action, aborting: " << action << '\n';
      return 1;
    }
    std::cerr << "Executed " << action << operand << ' ' << x << ' ' << y << ' '
              << waypoint_x << ' ' << waypoint_y << '\n';
  }
  std::cout << x << ' ' << y << ' ' << abs(x) + abs(y) << '\n';
  return 0;
}
