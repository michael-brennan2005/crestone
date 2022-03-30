#ifndef CRESTONE_DEBUG_H
#define CRESTONE_DEBUG_H

#include "emulatorstate.hpp"

class Debug {
public:
    Debug(EmulatorState* emulator_state);
    ~Debug();
    EmulatorState* emulator_state;
    void dump_memory(int row_size);
};

#endif // CRESTONE_DEBUG_H