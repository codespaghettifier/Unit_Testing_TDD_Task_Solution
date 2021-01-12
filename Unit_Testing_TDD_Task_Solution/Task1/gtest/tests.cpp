#include "gtest/gtest.h"
#include "../LinkedList.hpp"

TEST(LinkedList, pushFront)
{
    LinkedList<int> list;
    list.pushFront(43);
    list.pushFront(42);
    ASSERT_TRUE(list[0] == 42);
    ASSERT_TRUE(list[1] == 43);
}

TEST(LinkedList, pushBack)
{
    LinkedList<int> list;
    list.pushBack(42);
    list.pushBack(43);
    ASSERT_TRUE(list[0] == 42);
    ASSERT_TRUE(list[1] == 43);
}

TEST(LinkedList, LinkedListInitializerList)
{
    LinkedList<int> list {1, 2, 42};
    ASSERT_TRUE(list[0] == 1);
    ASSERT_TRUE(list[1] == 2);
    ASSERT_TRUE(list[2] == 42);
}

TEST(LinkedList, popFront)
{
    LinkedList<int> list {1, 2, 42};
    list.popFront();
    list.popFront();
    ASSERT_TRUE(list[0] == 42);
}

TEST(LinkedList, popBack)
{
    LinkedList<int> list {1};
    list.popBack();
    list.pushBack(42);
    ASSERT_TRUE(list[0] == 42);
}

TEST(LinkedList, getSize)
{
    LinkedList<int> list {1, 2, 42};
    ASSERT_TRUE(list.getSize() == 3);
}

TEST(LinkedList, isEmpty)
{
    LinkedList<int> list;
    ASSERT_TRUE(list.isEmpty());
    list.pushBack(42);
    ASSERT_TRUE(!list.isEmpty());
}

TEST(LinkedList, clear)
{
    LinkedList<int> list {1, 2, 42};
    list.clear();
    ASSERT_TRUE(list.getSize() == 0);
}
