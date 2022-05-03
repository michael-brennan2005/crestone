#include <iostream>
#include "crestone-lib/emulator.hpp"

int main(int argc, char* argv[]) {
    Emulator* emulator = new Emulator();
    int result = emulator->load_rom(argv[1]);
    emulator->execute();
}
