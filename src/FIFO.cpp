#include "FIFO.hpp"

template <typename E> FIFO<E>::FIFO() {
    _data = new E[this->_size];
}

template <typename E> FIFO<E>::FIFO(int size) : Interface<E>(size) {
    _data = new E[this->_size];
}

template <typename E> FIFO<E>::~FIFO() {
    delete _data;
    _data = nullptr;
}