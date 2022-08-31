#include <iostream>
#include "Interface.hpp"
#include "FIFO.hpp"
#include "LIFO.hpp"
#include "gtest/gtest.h"

using namespace std;

int main() {
    std::cout << "Hello World" << std::endl;
    FIFO<int> queue;
    LIFO<int> stack;
    return 0;
}

TEST(someTest, testOne) {
    ASSERT_EQ(5, 5);
}