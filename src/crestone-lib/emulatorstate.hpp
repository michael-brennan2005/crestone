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
    u16 i_register;
    u8 delay_timer;
    u8 sound_timer;
    u16 program_counter;
    u8 stack_pointer;
    u16* stack;

    bool* display;
    bool get_pixel(int x, int y);
    void set_pixel(int x, int y, bool value);
    void fill_display(bool value);

    bool kill_flag;
};

#endif //CRESTONE_EMULATORSTATE_H
