#include <iostream>
#include "crestone-lib/emulator.hpp"

int main() {
    Emulator* emulator = new Emulator();
    emulator->load_rom("test.c8");
    emulator->debug->dump_memory(16);
}
