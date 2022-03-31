#ifndef CRESTONE_CPP_H
#define CRESTONE_CPP_H

#include <functional>
#include "emulatorstate.hpp"



class Cpu {
public:
    Cpu(EmulatorState* emulator_state);
    ~Cpu();
    EmulatorState* emulator_state;

    u16 current_opcode;
    u16 nnn();
    u8 n();
    u8 x();
    u8 y();
    u8 kk();
    
    void execute();
    void OP_0();
    void OP_8();
    void OP_E();
    void OP_F();

    void OP_00E0();
    void OP_00EE();
    void OP_1NNN();
    void OP_2NNN();
    void OP_3XKK();
    void OP_4XKK();
    void OP_5XY0();
    void OP_6XKK();
    void OP_7XKK();
    void OP_8XY0();
    void OP_8XY1();
    void OP_8XY2();
    void OP_8XY3();
    void OP_8XY4();
    void OP_8XY5();
    void OP_8XY6();
    void OP_8XY7();
    void OP_8XYE();
    void OP_9XY0();
    void OP_ANNN();
    void OP_BNNN();
    void OP_CXKK();
    void OP_DXYN();
    void OP_EX9E();
    void OP_EXA1();
    void OP_FX07();
    void OP_FX0A();
    void OP_FX15();
    void OP_FX18();
    void OP_FX1E();
    void OP_FX29();
    void OP_FX33();
    void OP_FX55();
    void OP_FX65();
};

#endif // CRESTONE_CPP_H