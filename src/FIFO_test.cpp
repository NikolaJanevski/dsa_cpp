#include "gtest/gtest.h"
#include "FIFO.hpp"

namespace {
    TEST(FIFO_Test, CreateEmptyFIFO) {
        FIFO<int> queue;
        ASSERT_EQ(queue.size(), 0);
        ASSERT_TRUE(queue.isEmpty());
        ASSERT_EQ(queue.capacity(), 1000);
    }

    TEST(FIFO_Test, CreateEmptyFIFOWithCapacity) {
        FIFO<int> queue(100);
        ASSERT_EQ(queue.size(), 0);
        ASSERT_TRUE(queue.isEmpty());
        ASSERT_EQ(queue.capacity(), 100);
    }

    TEST(FIFO_Test, RemovingFromAnEmptyFIFO) {
        FIFO<int> queue;

        EXPECT_THROW(queue.get(), std::out_of_range);
    }

    TEST(FIFO_Test, AddingAnElementToAnEmptyFIFO) {
        FIFO<int> queue;

        queue.add(5);
        ASSERT_EQ(queue.size(), 1);
        ASSERT_FALSE(queue.isEmpty());

        ASSERT_EQ(queue.get(), 5);
        ASSERT_TRUE(queue.isEmpty());
        ASSERT_EQ(queue.size(), 0);
    }

    TEST(FIFO_Test, AddingMultipleElementsToAnEmptyFIFO) {
        FIFO<int> queue;

        queue.add(1);
        queue.add(2);
        queue.add(3);
        queue.add(4);
        queue.add(5);
        ASSERT_EQ(queue.size(), 5);
        ASSERT_FALSE(queue.isEmpty());

        ASSERT_EQ(queue.get(), 1);
        ASSERT_EQ(queue.get(), 2);
        ASSERT_EQ(queue.get(), 3);
        ASSERT_EQ(queue.get(), 4);
        ASSERT_EQ(queue.get(), 5);
        ASSERT_TRUE(queue.isEmpty());
        ASSERT_EQ(queue.size(), 0);
    }

    TEST(FIFO_Test, TestFIFOAutomaticCapacityIncrease) {
        FIFO<int> queue(10);

        ASSERT_EQ(queue.size(), 0);
        ASSERT_TRUE(queue.isEmpty());
        ASSERT_EQ(queue.capacity(), 10);

        for (int i = 0; i < 20; i++) {
            queue.add(i);
        }

        ASSERT_EQ(queue.capacity(), 20);
    }

    TEST(FIFO_Test, TestFIFOContentAfterAutomaticCapacityIncrease) {
        FIFO<int> queue(10);

        ASSERT_EQ(queue.size(), 0);
        ASSERT_TRUE(queue.isEmpty());
        ASSERT_EQ(queue.capacity(), 10);

        for (int i = 0; i < 20; i++) {
            queue.add(i);
        }

        ASSERT_EQ(queue.capacity(), 20);

        for (int i = 0; i < 20; i++) {
            ASSERT_EQ(queue.get(), i);
        }
    }

    TEST(FIFO_Test, AddingAndThenRemovingFromAnEmptyFIFO) {
        FIFO<int> queue;

        ASSERT_EQ(queue.size(), 0);
        ASSERT_TRUE(queue.isEmpty());

        for (int i = 0; i < 20; i++) {
            queue.add(i);
        }

        for (int i = 0; i < 20; i++) {
            ASSERT_EQ(queue.get(), i);
        }

        ASSERT_EQ(queue.size(), 0);
        ASSERT_TRUE(queue.isEmpty());
        ASSERT_EQ(queue.capacity(), 1000);
        EXPECT_THROW(queue.get(), std::out_of_range);
    }
}