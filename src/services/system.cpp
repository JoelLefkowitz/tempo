#include "system.hpp"
#include "../services/time.hpp"
#include "time.hpp"
#include <array>
#include <cmath>
#include <ctime>
#include <string>

tempo::SystemClock::time_point tempo::system(SteadyClock::time_point time) {
    return SystemClock::now() + duration_cast<SystemClock::duration>(time - SteadyClock::now());
}

std::string tempo::timestamp(SystemClock::time_point time) {
    auto ticks = SystemClock::to_time_t(time);

    std::array<char, 30> buffer = {};
    strftime(buffer.begin(), 30, "%FT%TZ", gmtime(&ticks));

    return {buffer.data()};
}
