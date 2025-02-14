#ifndef TEMPO_SERVICES_SYSTEM_HPP
#define TEMPO_SERVICES_SYSTEM_HPP

#include "time.hpp"
#include <chrono>
#include <string>

namespace tempo {
    SystemClock::time_point system(SteadyClock::time_point time);

    std::string timestamp(SystemClock::time_point time);
}

#endif
