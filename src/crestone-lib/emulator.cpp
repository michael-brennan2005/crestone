//
// Created by michaelb on 3/28/22.
//

#include "emulator.hpp"
#include "shell.hpp"
#include "cpu.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

#include "timer.hpp"

Emulator::Emulator() {
    emulator_state = new EmulatorState();

    const u8 font[] = {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F   
    };
    
    for (int i = 0; i < 80; i++) {
        emulator_state->memory[i] = font[i];
    }
    
    shell = new Shell(emulator_state);
    timer = new Timer(emulator_state);
    cpu = new Cpu(emulator_state);
}

Emulator::~Emulator() {
    delete emulator_state;
    delete shell;
    delete cpu;
}

int Emulator::load_rom(char *file_name) {
    std::cout << "Loading file " << file_name << "..." << std::endl;
    std::ifstream file(file_name, std::ios::binary|std::ios::ate);
    std::ifstream::pos_type pos = file.tellg();
    int length = pos;
    std::cout << length << std::endl;
    file.seekg(0, std::ios::beg);
    file.read(reinterpret_cast<char*>(emulator_state->memory + 0x200), length);
    file.close();
    return 0;
}

void Emulator::execute() {
    while (true) {
        // Clear input.
        emulator_state->clear_input();
        shell->execute();
        timer->execute();
        cpu->execute();

        if (emulator_state->kill_flag == true) {
            break;
        }
    }
}