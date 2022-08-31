#include "Interface.hpp"

template <typename E> Interface<E>::Interface() {
    _size = 1000;
}

template <typename E> Interface<E>::~Interface() {
    _size = 0;
}

template <typename E> bool Interface<E>::isEmpty() {
    return _size == 0;
}