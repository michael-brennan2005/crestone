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

    input = new bool[16]();
    clear_input();

    display = new bool[64*32];

    fill_display(false);
    kill_flag = false;
    wait_flag = false;
}

EmulatorState::~EmulatorState() {
    delete [] memory;
    delete [] registers;
    delete [] stack;
    delete [] display;
}

u8 EmulatorState::key_to_index(int key) {
    switch (key) {
        case 27:
            return 0x1; 
        case 28:
            return 0x2; 
        case 29:
            return 0x3; 
        case 30:
            return 0xC;
        case 16:
            return 0x4; 
        case 22:
            return 0x5; 
        case 4:
            return 0x6;   
        case 17:
            return 0xD;
        case 0:
            return 0x7;   
        case 18:
            return 0x8; 
        case 3:
            return 0x9;   
        case 5:
            return 0xE;
        case 25:
            return 0xA; 
        case 23:
            return 0x0; 
        case 2:
            return 0xB;   
        case 21:
            return 0xF;    
    }
}

void EmulatorState::clear_input() {
    for (int i = 0; i < 16; i++) {
        input[i] = false;
    }
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