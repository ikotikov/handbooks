#include <iostream>

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) {
        return last;
    }

    Iter end = first;
    for (Iter i = first; i != last; ++i) {
        if (*i != *end && ++end != i) {
            *end = std::move(*i);
        }
    }

    return ++end;
}