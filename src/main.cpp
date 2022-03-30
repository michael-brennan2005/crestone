#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include "emulator.hpp"

int main() {
    Emulator* emulator = new Emulator();
    emulator->load_rom("test.c8");
    emulator->debug->dump_memory(emulator->emulator_state, 16);
    
    std::cout << std::hex << +emulator->emulator_state->memory[0x200] << std::endl;
}