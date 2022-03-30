//
// Created by michaelb on 3/28/22.
//

#include "emulator.hpp"
#include "cpu.hpp"
#include <iostream>
#include <fstream>

Emulator::Emulator() {
    emulator_state = new EmulatorState();
    debug = new Debug(emulator_state);
    cpu = new Cpu(emulator_state);
}

Emulator::~Emulator() {
    delete emulator_state;
    delete debug;
    delete cpu;
}

void Emulator::load_rom(char *file_name) {
    std::cout << "Loading file " << file_name << "..." << std::endl;
    std::ifstream file(file_name, std::ios::binary|std::ios::ate);
    std::ifstream::pos_type pos = file.tellg();
    int length = pos;
    std::cout << length << std::endl;
    file.seekg(0, std::ios::beg);
    file.read(reinterpret_cast<char*>(emulator_state->memory + 0x200), length);
    file.close();
    std::cout << "Done!" << std::endl;
}