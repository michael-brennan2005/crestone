//
// Created by michaelb on 3/28/22.
//

#ifndef CRESTONE_EMULATORSTATE_H
#define CRESTONE_EMULATORSTATE_H

#include "common.hpp"

struct EmulatorState {
public:
    EmulatorState();
    ~EmulatorState();
    u8* memory;
    u8* registers;
    u8 i_register;
    u8 delay_timer;
    u8 sound_timer;
    u16 program_counter;
    u8 stack_pointer;
    u16* stack;
};

#endif //CRESTONE_EMULATORSTATE_H
