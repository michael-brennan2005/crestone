#include <iostream>
#include "crestone-lib/emulator.hpp"

int main() {
    Emulator* emulator = new Emulator();
    emulator->load_rom("spaceinvaders.ch8");
    emulator->execute();
}
