#ifndef TEMPO_SERVICES_TIME_HPP
#define TEMPO_SERVICES_TIME_HPP

#include <chrono>
#include <string>

namespace tempo {
    using SteadyClock = std::chrono::steady_clock;
    using SystemClock = std::chrono::system_clock;
    
    SteadyClock::time_point now();
    SteadyClock::duration duration(double time);

    double delta(SteadyClock::time_point t1, SteadyClock::time_point t2);
    double since(SteadyClock::time_point time);

    std::string timestamp(SteadyClock::time_point time);
}

#endif
