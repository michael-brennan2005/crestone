#include <iomanip>
#include <iostream>
#include "debug.hpp"
#include "common.hpp"

Debug::Debug() {}
Debug::~Debug() {}

void Debug::dump_memory(EmulatorState* emulator_state, int row_size) {
    // '+' go on the memory fields because that promotes them from char to integer, printing their effective hex values.
    for (int i = 0; i < 4096 / row_size; i += 1) {
        std::cout << "0x" << std::setw(3) << std::setfill('0') << std::uppercase << std::hex << i * 16 << " | ";
        for (int j = 0; j < row_size; j += 1) {
            std::cout << std::setw(2) << std::setfill('0') << std::uppercase << std::hex << +emulator_state->memory[i * 16 + j] << " ";
        }
        std::cout << std::endl;
    }
}