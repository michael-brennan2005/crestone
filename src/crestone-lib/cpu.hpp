#ifndef CRESTONE_CPP_H
#define CRESTONE_CPP_H

#include "emulatorstate.hpp"

class Cpu {
public:
    Cpu(EmulatorState* emulator_state);
    ~Cpu();
    EmulatorState* emulator_state;
    u16 current_opcode;
    void nnn();
    void n();
    void x();
    void y();
    void kk();
    void execute();
};

#endif // CRESTONE_CPP_H