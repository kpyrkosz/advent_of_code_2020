#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

struct instruction {
  enum class op : int { nop, acc, jmp };
  op operation;
  int operand;
};

int main() {
  std::vector<instruction> program_code;
  while (!std::cin.eof()) {
    instruction instr;
    int int_operation;
    std::cin >> int_operation >> instr.operand;
    assert(int_operation >= 0 && int_operation <= 2);
    instr.operation = static_cast<instruction::op>(int_operation);
    program_code.emplace_back(instr);
    std::cin >> std::ws;
  }
  std::unordered_set<int> executed_lines;
  int current_line = 0;
  int accumulator = 0;
  assert(line_as_vec_index < program_code.size());
  while (executed_lines.count(current_line) == 0) {
    executed_lines.insert(current_line);
    unsigned line_as_vec_index = static_cast<unsigned>(current_line);
    assert(line_as_vec_index < program_code.size());
    switch (program_code[line_as_vec_index].operation) {
    case instruction::op::nop:
      std::cerr << "NOP at line " << line_as_vec_index << '\n';
      ++current_line;
      break;
    case instruction::op::acc:
      accumulator += program_code[line_as_vec_index].operand;
      std::cerr << "ACC at line " << line_as_vec_index << " acc value "
                << accumulator << '\n';
      ++current_line;
      break;
    case instruction::op::jmp:
      std::cerr << "JMP at line " << line_as_vec_index;
      current_line += program_code[line_as_vec_index].operand;
      std::cerr << " jumped to line " << current_line << '\n';
      break;
    }
  }
  std::cout << accumulator << '\n';
  return 0;
}
