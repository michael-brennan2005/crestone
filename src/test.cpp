#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "crestone-lib/cpu.hpp"
#include "crestone-lib/common.hpp"

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

class CpuTestFixture {
public:
    Cpu* cpu;
    EmulatorState* emulator_state;
    CpuTestFixture() {
        emulator_state = new EmulatorState();
        cpu = new Cpu(emulator_state);
    }
    ~CpuTestFixture() {
        delete cpu;
        delete emulator_state;
    }
};

TEST_CASE_FIXTURE(CpuTestFixture, "Op 8xy0") {
    GET_REGISTER(0x0) = 0x0A;
    GET_REGISTER(0x1) = 0x1B;
    cpu->current_opcode = 0x0010;
    cpu->OP_8XY0();
    CHECK(GET_REGISTER(0x0) == GET_REGISTER(0x1));
}

TEST_CASE_FIXTURE(CpuTestFixture, "Op 8xy1") {
    GET_REGISTER(0x0) = 0x22;
    GET_REGISTER(0x1) = 0xFF;
    cpu->current_opcode = 0x0010;
    cpu->OP_8XY1();
    CHECK(GET_REGISTER(0x0) == 0xFF);
}

TEST_CASE_FIXTURE(CpuTestFixture, "Op 8xy2") {
    GET_REGISTER(0x0) = 0x35;
    GET_REGISTER(0x1) = 0x9F;
    cpu->current_opcode = 0x0010;
    cpu->OP_8XY2();
    CHECK(GET_REGISTER(0x0) == 0x15);
}

TEST_CASE_FIXTURE(CpuTestFixture, "Op 8xy3") {
    GET_REGISTER(0x0) = 0x12;
    GET_REGISTER(0x1) = 0x05;
    cpu->current_opcode = 0x0010;
    cpu->OP_8XY3();
    CHECK(GET_REGISTER(0x0) == 0x17);
}

TEST_CASE_FIXTURE(CpuTestFixture, "Op 8xy4") {
    GET_REGISTER(0x0) = 0x66;
    GET_REGISTER(0x1) = 0x77;
    cpu->current_opcode = 0x0010;
    cpu->OP_8XY4();
    CHECK(GET_REGISTER(0x0) == 0xDD);
    CHECK(GET_REGISTER(VF) == 0x0);
}

TEST_CASE_FIXTURE(CpuTestFixture, "Op 8xy5") {
    GET_REGISTER(0x0) = 0x88;
    GET_REGISTER(0x1) = 0x99;
    cpu->current_opcode = 0x0010;
    cpu->OP_8XY5();
    CHECK(GET_REGISTER(0x0) == 0xEF);
    CHECK(GET_REGISTER(VF) == 0x0);
}

TEST_CASE_FIXTURE(CpuTestFixture, "Op 8xy6") {
    GET_REGISTER(0x0) = 0xBC;
    cpu->current_opcode = 0x0010;
    cpu->OP_8XY6();
    CHECK(GET_REGISTER(0x0) == 0x5E);
}

TEST_CASE_FIXTURE(CpuTestFixture, "Op 8xy7") {
    GET_REGISTER(0x0) = 0xFF;
    GET_REGISTER(0x1) = 0x00;
    cpu->current_opcode = 0x0010;
    cpu->OP_8XY7();
    CHECK(GET_REGISTER(0x0) == 0x1);
    CHECK(GET_REGISTER(VF) == 0x0);
}

TEST_CASE_FIXTURE(CpuTestFixture, "Op FX33") {
    GET_REGISTER(0x0) = 128;
    emulator_state->i_register = 0x123;
    cpu->current_opcode = 0x0000;

    cpu->OP_FX33();
    CHECK(GET_MEMORY(emulator_state->i_register) == 1);
    CHECK(GET_MEMORY(emulator_state->i_register + 1) == 2);
    CHECK(GET_MEMORY(emulator_state->i_register + 2)== 8);
}