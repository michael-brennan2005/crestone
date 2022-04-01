//
// Created by michaelb on 3/28/22.
//

#ifndef CRESTONE_COMMON_H
#define CRESTONE_COMMON_H

#include <stdint.h>

#define GET_REGISTER( x ) emulator_state->registers[x]
#define GET_MEMORY( x ) emulator_state->memory[x]
#define VF 15

typedef uint8_t u8;
typedef uint16_t u16;

#endif //CRESTONE_COMMON_H
