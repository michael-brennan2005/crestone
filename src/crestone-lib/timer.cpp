#include "timer.hpp"
#include <iostream>

void Timer::execute() {
    // from emulator::execute()
    dt += std::chrono::milliseconds(2).count();
    if (dt > 16) {
        dt = 0;
        if (emulator_state->sound_timer > 0) {
            emulator_state->sound_timer--;
        } 

        if (emulator_state->delay_timer > 0) {
            emulator_state->delay_timer--;
        }
    }
}