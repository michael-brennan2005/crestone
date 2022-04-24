#ifndef CRESTONE_TIMERS_H
#define CRESTONE_TIMERS_H

#include "common.hpp"

void create_timer_thread(u8* delay_timer, u8* sound_timer);

class Timer {
public:
    Timer(u8* delay_timer, u8* sound_timer) : delay_timer(delay_timer), sound_timer(sound_timer) {};
    ~Timer();
    u8* delay_timer;
    u8* sound_timer;
    void execute();
};

#endif 