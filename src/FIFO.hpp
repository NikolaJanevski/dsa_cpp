#ifndef _FIFO_H
#define _FIFO_H

#include <memory>
#include "Interface.hpp"

template <typename E> class FIFO : protected Interface<E> {
public:
    FIFO() {
        _data = std::make_unique<E []>(this->_size);
    };

    FIFO(int capacity) : Interface<E>(capacity) {
        _data = std::make_unique<E []>(this->_capacity);
    };

    ~FIFO() {
        _data.reset();
    };

    void add(E value) {
        if (this->_size >= this->_capacity) {
            // increase capacity
            std::unique_ptr<E []> temp = std::make_unique<E []>(this->_capacity * 2);
            for (int i = _front; i < this->_capacity; i++) {
                temp[i - _front] = _data[i];
            }

            _back = _back - _front;
            _front = 0;
            
            _data = std::move(temp);
        }
        _data[_back++] = value;
    }

    E get() {
        if (_front < 0) {
            throw std::out_of_range ("Queue is empty");
        }

        this->_size--;
        return _data[_front++];
    }
private:
    int _front = -1;
    int _back = -1;
    std::unique_ptr<E []> _data;
};

#endif