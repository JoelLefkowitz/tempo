#ifndef TEMPO_MODELS_TIMER_HPP
#define TEMPO_MODELS_TIMER_HPP

// cppclean-disable-next-line
#include "../services/time.hpp"

namespace tempo {
    class Timer {
      private:
        SteadyClock::time_point start;

      public:
        double previous = 0;

        explicit Timer();

        double operator()();
    };
}

#endif
