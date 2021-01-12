#pragma once

#include <initializer_list>

template<typename T>
class LinkedList
{
public:
	LinkedList() = default;
	LinkedList(const std::initializer_list<T>& elements)
	{

	}
	void pushFront(const T& element)
	{
		Node* temp = head;
		head = new Node(element);
		head->next = temp;
	}
	void pushBack(const T& element)
	{
		if(head == nullptr)
		{
			head = new Node(element);
			return;
		}

		Node* next = head;
		while(next->next != nullptr)
		{
			next = next->next;
		}

		next->next = new Node(element);
	}
	T popFront()
	{
		// to implement
	}
	T popBack()
	{
		// to implement
	}
	unsigned getSize() const
	{
		return 0;
	}
	bool isEmpty() const
	{
		return true;
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
		T value;
		Node* next = nullptr;

		Node(const T& value)
		: value{value} {}
	};

	Node* head = nullptr;
};
