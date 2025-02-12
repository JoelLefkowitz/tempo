#include "debouncer.tpp"
#include "../services/async.hpp"
#include <chrono>
#include <functional>
#include <gtest/gtest.h>
#include <vector>

using namespace tempo;

TEST(Debouncer, Call) {
    std::vector<int> vec;

    std::function<void(int)> push = [&vec](int x) { vec.push_back(x); };

    Debouncer<int> debouncer(push, 0.2);

    wait_for(std::function<void()>([&debouncer]() { debouncer(1); }), std::chrono::milliseconds(100));
    wait_for(std::function<void()>([&debouncer]() { debouncer(2); }), std::chrono::milliseconds(200));
    wait_for(std::function<void()>([&debouncer]() { debouncer(3); }), std::chrono::milliseconds(300));
    wait_for(std::function<void()>([&debouncer]() { debouncer(4); }), std::chrono::milliseconds(400));
    wait_for(std::function<void()>([&debouncer]() { debouncer(5); }), std::chrono::milliseconds(500));

    EXPECT_EQ(vec, std::vector<int>({1, 3}));
}
