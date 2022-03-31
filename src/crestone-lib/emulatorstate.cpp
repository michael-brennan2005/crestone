//
// Created by michaelb on 3/28/22.
//

#include "common.hpp"
#include "emulatorstate.hpp"

EmulatorState::EmulatorState() {
    memory = new u8[4096]();
    registers = new u8[16]();
    i_register = 0;
    delay_timer = 0;
    sound_timer = 0;
    program_counter = 0x200;
    stack_pointer = 0;
    stack = new u16[16]();
    clear_display = false;
}

EmulatorState::~EmulatorState() {
    delete [] memory;
    delete [] registers;
    delete [] stack;
}