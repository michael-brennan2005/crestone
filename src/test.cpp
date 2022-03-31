#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "crestone-lib/cpu.hpp"

TEST_CASE("Checking the CPU selectors") {
    Cpu cpu = Cpu(NULL);
    cpu.current_opcode = 0xABCD;
    CHECK(cpu.nnn() == 0xBCD);
    CHECK(cpu.n() == 0xD);
    CHECK(cpu.x() == 0xB);
    CHECK(cpu.y() == 0xC);
    CHECK(cpu.kk() == 0xCD);
}

TEST_CASE("Checking the CPU selectors pt. 2") {
    Cpu cpu = Cpu(NULL);
    cpu.current_opcode = 0x190F;
    CHECK(cpu.nnn() == 0x90F);
    CHECK(cpu.n() == 0xF);
    CHECK(cpu.x() == 0x9);
    CHECK(cpu.y() == 0x0);
    CHECK(cpu.kk() == 0x0F);
}