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


/*
 * #pragma once

#include <initializer_list>

template<typename T>
class LinkedList
{
public:
	LinkedList()
	{
		// to implement
	}
	LinkedList(const std::initializer_list<T>& newValues)
	{
		// to implement
	}
	void pushFront(const T& newValue)
	{
		// to implement
	}
	void pushBack(const T& newValue)
	{
		// to implement
	}
	[[nodiscard]]  T popFront()
	{
		// to implement
	}
	[[nodiscard]]  T popBack()
	{
		// to implement
	}
	[[nodiscard]] unsigned getSize() const
	{
		// to implement
	}
	[[nodiscard]] bool isEmpty() const
	{
		// to implement
	}
	void clear()
	{
		// to implement
	}

private:
	Node* head;
	struct Node
	{
		Node(const T& newValue) : value{ newValue } {}
		Node* next = nullptr;
		T value;
	};

};
 *
 */
