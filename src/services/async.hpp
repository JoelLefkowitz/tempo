#ifndef TEMPO_SERVICES_ASYNC_HPP
#define TEMPO_SERVICES_ASYNC_HPP

#include <chrono>
#include <functional>
#include <future>

namespace tempo {
    std::future<void> wait_for(std::function<void()> call, std::chrono::milliseconds delay);
}

#endif
