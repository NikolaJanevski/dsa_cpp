// Copyright 2022 Nikola Janevski. All rights reserved.
// Licensed under GNU Public.

#include <iostream>
#include "Interface.hpp"
#include "FIFO.hpp"
#include "LIFO.hpp"
#include "gtest/gtest.h"

int main() {
    std::cout << "Hello World" << std::endl;
    FIFO<int> queue;
    LIFO<int> stack;
    return 0;
}
