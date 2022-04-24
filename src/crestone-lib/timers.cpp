#include "timers.hpp"
#include <thread>

void create_timer_thread(u8* delay_timer, u8* sound_timer) {
    auto timer = new Timer(delay_timer, sound_timer);

    timer->execute();
}

void Timer::execute() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1 / 60));

        if (*delay_timer > 0) {
            *delay_timer--;
        }

        if (*sound_timer > 0) {
            *sound_timer--;
        }
    }
}