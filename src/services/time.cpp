#include "time.hpp"
#include <array>
#include <chrono>
#include <cmath>
#include <ctime>
#include <string>

tempo::SteadyClock::time_point tempo::now() { return SteadyClock::now(); }

tempo::SteadyClock::duration tempo::duration(double time) {
    return std::chrono::duration_cast<SteadyClock::duration>(std::chrono::duration<double>(time));
}

double tempo::delta(SteadyClock::time_point t1, SteadyClock::time_point t2) {
    auto ticks = static_cast<double>((t2 - t1).count());
    return ticks * std::pow(0.1, 9);
}

double tempo::since(SteadyClock::time_point time) { return delta(time, now()); }

std::string tempo::timestamp() {
    auto time = SystemClock::to_time_t(SystemClock::now());

    std::array<char, 30> buffer = {};
    strftime(buffer.begin(), 30, "%FT%TZ", gmtime(&time));

    return {buffer.data()};
}
