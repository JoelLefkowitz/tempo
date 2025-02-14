#include "debouncer.tpp"
#include <chrono>
#include <functional>
#include <future>
#include <gtest/gtest.h>
#include <thread>
#include <vector>

using namespace tempo;

TEST(Debouncer, Call) {
    std::vector<int> vec;

    std::function<void(int)> push = [&vec](int x) {
        vec.push_back(x);
    };

    std::chrono::milliseconds delay(10);

    Debouncer<int> debouncer(push, delay * 2);

    for (int i = 1; i <= 5; ++i) {
        std::this_thread::sleep_for(delay);
        debouncer(i);
    }

    EXPECT_EQ(vec, std::vector<int>({1, 3, 5}));
}
