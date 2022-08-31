#ifndef _LIFO_H
#define _LIFO_H

#include <memory>
#include "Interface.hpp"

template <typename E> class LIFO : public Interface<E> {
public:
    LIFO() {
        _data = std::make_unique<E []>(this->_capacity);
    };

    LIFO(int capacity) : Interface<E>(capacity) {
        _data = std::make_unique<E []>(this->_capacity);
    };

    ~LIFO() {
        _data.reset();
    };

    void add(E value) {
        if (this->_size >= this->_capacity) {
            // increase capacity
            std::unique_ptr<E []> temp = std::make_unique<E []>(this->_capacity * 2);
            for (int i = 0; i < this->_capacity; i++) {
                temp[i] = _data[i];
            }
            
            this->_capacity = this->_capacity * 2;
            
            _data = std::move(temp);
        }
        this->_size++;
        _data[++_top] = value;
    }

    E get() {
        if (_top < 0) {
            throw std::out_of_range ("Stack is empty");
        }

        this->_size--;
        return _data[_top--];
    }
private:
    int _top = -1;
    std::unique_ptr<E []> _data;
};

#endif