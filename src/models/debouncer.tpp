#ifndef TEMPO_MODELS_DEBOUNCER_TPP
#define TEMPO_MODELS_DEBOUNCER_TPP

#include "../services/time.hpp"
#include "debouncer.hpp"
#include <functional>
#include <iostream>

template <typename T>
tempo::Debouncer<T>::Debouncer(const std::function<void(T)> &call, std::chrono::milliseconds delay)
    : call(call)
    , delay(delay) {
}

template <typename T>
void tempo::Debouncer<T>::operator()(T input) {
    auto now = tempo::SteadyClock::now();

    if (now > available) {
        available = now + delay;
        call(input);
    }
}

#endif
