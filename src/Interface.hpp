#ifndef _INTERFACE_H
#define _INTERFACE_H

template <typename E>
class Interface {
public:
    Interface();
    ~Interface();
    virtual void add(E value);
    virtual E get();
    bool isEmpty();
    int size();
private:
    int _size;
    E _data [];
};

#endif