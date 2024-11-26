#ifndef TEMPO_MODELS_DEBOUNCER_TPP
#define TEMPO_MODELS_DEBOUNCER_TPP

#include "../services/time.hpp"
#include "debouncer.hpp"
#include <functional>

template <typename T>
tempo::Debouncer<T>::Debouncer(const std::function<void(T)> &call, double delay) : call(call)
                                                                                 , delay(delay) {}

template <typename T>
void tempo::Debouncer<T>::operator()(T input) {
    if (tempo::SteadyClock::now() > available) {
        available += tempo::duration(delay);
        call(input);
    }
}

#endif
