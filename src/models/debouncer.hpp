#ifndef TEMPO_MODELS_DEBOUNCER_HPP
#define TEMPO_MODELS_DEBOUNCER_HPP

#include <functional>

// cppclean-disable-next-line
#include "../services/time.hpp"

namespace tempo {
    template <typename T>
    class Debouncer {
        std::function<void(T)> call;
        std::chrono::milliseconds delay;

      public:
        SteadyClock::time_point available = SteadyClock::now();

        explicit Debouncer(const std::function<void(T)> &call, std::chrono::milliseconds delay);

        void operator()(T input);
    };
}

#endif
