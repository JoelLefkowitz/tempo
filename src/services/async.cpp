#include "./async.hpp"
#include <chrono>
#include <functional>
#include <future>
#include <thread>
#include <chrono>
#include <functional>

std::future<void> tempo::wait_for(std::function<void()> call, std::chrono::milliseconds delay) {
    return std::async(std::launch::async, [&call, delay]() {
        std::this_thread::sleep_for(delay);
        call();
    });
}