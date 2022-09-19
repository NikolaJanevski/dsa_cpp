// Copyright 2022 Nikola Janevski. All rights reserved.
// Licensed under GNU Public.

#ifndef SRC_FIFO_HPP_
#define SRC_FIFO_HPP_

#include <memory>
#include <utility>
#include "Interface.hpp"

template <typename E> class FIFO : public Interface<E> {
 public:
    FIFO() {
        _data = std::make_unique<E[]>(this->_capacity);
    };

    explicit FIFO(int capacity) : Interface<E>(capacity) {
        _data = std::make_unique<E[]>(this->_capacity);
    }

    ~FIFO() {
        _data.reset();
    };

    void add(E value) {
        if (this->_size >= this->_capacity) {
            // increase capacity
            std::unique_ptr<E[]> temp =
                std::make_unique<E[]>(this->_capacity * 2);

            for (int i = 0; i < this->_size; i++) {
                temp[i] = _data[(i + _back) % this->_capacity];
            }

            _back = 0;
            _front = this->_size;

            _data = std::move(temp);
            this->_capacity = this->_capacity * 2;
        }
        this->_size++;
        _data[_front] = value;
        _front = (++_front) % this->_capacity;
    }

    E get() {
        if (this->_size == 0) {
            throw std::out_of_range("Queue is empty");
        }

        this->_size--;
        
        E value = _data[_back];
        _back = (++_back) % this->_capacity;
        return value;
    }

 private:
    size_t _front = 0;
    size_t _back = 0;
    std::unique_ptr<E[]> _data;
};

#endif  // SRC_FIFO_HPP_
