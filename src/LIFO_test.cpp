#include "gtest/gtest.h"
#include "LIFO.hpp"

namespace {
    TEST(LIFO_Test, CreateEmptyLIFO) {
        LIFO<int> stack;
        ASSERT_EQ(stack.size(), 0);
        ASSERT_TRUE(stack.isEmpty());
        ASSERT_EQ(stack.capacity(), 1000);
    }

    TEST(LIFO_Test, CreateEmptyLIFOWithCapacity) {
        LIFO<int> stack(100);
        ASSERT_EQ(stack.size(), 0);
        ASSERT_TRUE(stack.isEmpty());
        ASSERT_EQ(stack.capacity(), 100);
    }
}