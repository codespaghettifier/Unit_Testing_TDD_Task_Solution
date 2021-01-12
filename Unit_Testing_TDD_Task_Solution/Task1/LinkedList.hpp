#pragma once

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

	T& operator[](unsigned index)
	{
		Node* next = head;
		for(unsigned a = 0; a < index; a++)
		{
			next = head->next;
		}

		return next->value;
	}

private:
	struct Node
	{
		Node(const T& newValue) : value{ newValue } {}
		Node* next = nullptr;
		T value;
	};

	Node* head;
};
