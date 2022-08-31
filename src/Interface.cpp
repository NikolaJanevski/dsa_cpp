#include "Interface.hpp"

template <typename E> Interface<E>::Interface() {
    _size = 1000;
    _data = new E[_size];
}

template <typename E> Interface<E>::~Interface() {
    free(_data);
    _size = 0;
}
