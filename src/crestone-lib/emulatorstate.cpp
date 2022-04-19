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
    display = new bool[64*32];

    fill_display(false);
    kill_flag = false;
}

EmulatorState::~EmulatorState() {
    delete [] memory;
    delete [] registers;
    delete [] stack;
    delete [] display;
}

bool EmulatorState::get_pixel(int x, int y) {
    return display[x + (64 * y)];
}

void EmulatorState::set_pixel(int x, int y, bool value) {
    display[x + (64 * y)] = value;
};

void EmulatorState::fill_display(bool value) {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 32; j++) {
            set_pixel(i, j, value);
        }
    }
}