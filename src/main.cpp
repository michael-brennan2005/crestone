#include <iostream>
#include "crestone-lib/emulator.hpp"

int main() {
    Emulator* emulator = new Emulator();
    emulator->load_rom("chip8-test-rom.ch8");
    emulator->execute();
}
