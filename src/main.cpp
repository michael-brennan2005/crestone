#include <iostream>
#include "crestone-lib/emulator.hpp"

int main() {
    Emulator* emulator = new Emulator();
    emulator->load_rom("test_opcode.ch8");
    emulator->execute();
}
