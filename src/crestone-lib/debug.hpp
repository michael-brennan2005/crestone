#ifndef CRESTONE_DEBUG_H
#define CRESTONE_DEBUG_H

#include "emulatorstate.hpp"

class Debug {
public:
    Debug();
    ~Debug();
    void dump_memory(EmulatorState* emulator_state, int row_size);
};

#endif // CRESTONE_DEBUG_H