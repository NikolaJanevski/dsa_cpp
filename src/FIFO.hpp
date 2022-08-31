#ifndef _FIFO_H
#define _FIFO_H
#include "Interface.hpp"

template <typename E> class FIFO : protected Interface<E> {
public:
    FIFO();
    FIFO(int size);
    ~FIFO();
private:
    E _data [];
};

#endif