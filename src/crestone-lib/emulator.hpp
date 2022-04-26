//
// Created by michaelb on 3/28/22.
//

#ifndef CRESTONE_EMULATOR_H
#define CRESTONE_EMULATOR_H

#include "common.hpp"
#include "emulatorstate.hpp"
#include "debug.hpp"
#include "cpu.hpp"
#include "shell.hpp"
#include "timer.hpp"

class Emulator {
public:
    EmulatorState* emulator_state;
    Shell* shell;
    Timer* timer;
    Cpu* cpu;
    Emulator();
    ~Emulator();
    void load_rom(char* file_name);
    void execute();
};


#endif //CRESTONE_EMULATOR_H
