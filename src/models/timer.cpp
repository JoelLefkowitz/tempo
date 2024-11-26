#include "timer.hpp"
#include "../services/time.hpp"

tempo::Timer::Timer() : start(SteadyClock::now()) {}

double tempo::Timer::operator()() {
    SteadyClock::time_point time = SteadyClock::now();

    previous = tempo::delta(start, time);
    start    = time;

    return previous;
}
