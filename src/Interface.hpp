#ifndef _INTERFACE_H
#define _INTERFACE_H

template <typename E>
class Interface {
public:
    Interface() {
        _capacity = 1000;
    };

    Interface(int capacity) {
        _capacity = capacity;
    };

    ~Interface() {
        _capacity = 0;
        _size = 0;
    };

    virtual void add(E value) = 0;
    virtual E get() = 0;
    
    bool isEmpty() {
        return _size == 0;
    };

    int size() {
        return _size;
    };

    int capacity() {
        return _capacity;
    }
protected:
    int _size = 0;
    int _capacity = 0;
};

#endif