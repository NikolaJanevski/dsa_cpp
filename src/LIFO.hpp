// Copyright 2022 Nikola Janevski. All rights reserved.
// Licensed under GNU Public.

#ifndef SRC_LIFO_HPP_
#define SRC_LIFO_HPP_

#include <memory>
#include <utility>
#include "Interface.hpp"

template <typename E> class LIFO : public Interface<E> {
 public:
    LIFO() {
        _data = std::make_unique<E[]>(this->_capacity);
    };

    explicit LIFO(int capacity) : Interface<E>(capacity) {
        _data = std::make_unique<E[]>(this->_capacity);
    }

    ~LIFO() {
        _data.reset();
    }

    void add(E value) {
        if (this->_size >= this->_capacity) {
            // increase capacity
            std::unique_ptr<E[]> temp =
                std::make_unique<E[]>(this->_capacity * 2);
            for (size_t i = 0; i < this->_capacity; i++) {
                temp[i] = _data[i];
            }

            this->_capacity = this->_capacity * 2;

            _data = std::move(temp);
        }
        this->_size++;
        _data[_top++] = value;
    }

    E get() {
        if (_top == 0) {
            throw std::out_of_range("Stack is empty");
        }

        this->_size--;
        return _data[--_top];
    }

 private:
    size_t _top = 0;
    std::unique_ptr<E[]> _data;
};

#endif  // SRC_LIFO_HPP_
