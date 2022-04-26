#ifndef CRESTONE_timer_H
#define CRESTONE_timer_H

#include "common.hpp"
#include "emulatorstate.hpp"
#include <chrono>

class Timer {
public:
    Timer(EmulatorState* emulator_state) : emulator_state(emulator_state), dt(0) {};
    ~Timer();
    EmulatorState* emulator_state;
    long long dt;
    void execute();
};

#endif 