// Copyright 2022 Nikola Janevski. All rights reserved.
// Licensed under GNU Public.

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

    TEST(LIFO_Test, RemovingFromAnEmptyLIFO) {
        LIFO<int> stack;

        EXPECT_THROW(stack.get(), std::out_of_range);
    }

    TEST(LIFO_Test, AddingAnElementToAnEmptyLIFO) {
        LIFO<int> stack;

        stack.add(5);
        ASSERT_EQ(stack.size(), 1);
        ASSERT_FALSE(stack.isEmpty());

        ASSERT_EQ(stack.get(), 5);
        ASSERT_TRUE(stack.isEmpty());
        ASSERT_EQ(stack.size(), 0);
    }

    TEST(LIFO_Test, AddingMultipleElementsToAnEmptyLIFO) {
        LIFO<int> stack;

        stack.add(1);
        stack.add(2);
        stack.add(3);
        stack.add(4);
        stack.add(5);
        ASSERT_EQ(stack.size(), 5);
        ASSERT_FALSE(stack.isEmpty());

        ASSERT_EQ(stack.get(), 5);
        ASSERT_EQ(stack.get(), 4);
        ASSERT_EQ(stack.get(), 3);
        ASSERT_EQ(stack.get(), 2);
        ASSERT_EQ(stack.get(), 1);
        ASSERT_TRUE(stack.isEmpty());
        ASSERT_EQ(stack.size(), 0);
    }

    TEST(LIFO_Test, TestLIFOAutomaticCapacityIncrease) {
        LIFO<int> stack(10);

        ASSERT_EQ(stack.size(), 0);
        ASSERT_TRUE(stack.isEmpty());
        ASSERT_EQ(stack.capacity(), 10);

        for (int i = 0; i < 20; i++) {
            stack.add(i);
        }

        ASSERT_EQ(stack.capacity(), 20);
    }

    TEST(LIFO_Test, TestLIFOContentAfterAutomaticCapacityIncrease) {
        LIFO<int> stack(10);

        ASSERT_EQ(stack.size(), 0);
        ASSERT_TRUE(stack.isEmpty());
        ASSERT_EQ(stack.capacity(), 10);

        for (int i = 0; i < 20; i++) {
            stack.add(i);
        }

        ASSERT_EQ(stack.capacity(), 20);

        for (int i = 19; i >= 0; i--) {
            ASSERT_EQ(stack.get(), i);
        }
    }
}  // namespace
