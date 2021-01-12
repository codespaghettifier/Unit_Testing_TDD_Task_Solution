#pragma once

#include <initializer_list>

#include <iostream>

template<typename T>
class LinkedList
{
public:
	LinkedList() = default;
	LinkedList(const std::initializer_list<T>& elements)
	{
		auto iterator = elements.begin();
		while(iterator != elements.end())
		{
			pushBack(*iterator);
			iterator++;
		}
	}

	void pushFront(const T& element)
	{
		Node* temp = head;
		head = new Node(element);
		head->next = temp;
		size++;
	}
	void pushBack(const T& element)
	{
		if(head == nullptr)
		{
			head = new Node(element);
			size++;
			return;
		}

		getNode(size - 1).next = new Node(element);
		size++;
	}
	void popFront()
	{
		if(size == 0) return;
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	void popBack()
	{
		if(size == 0) return;

		if(size == 1)
		{
			delete head;
			head = nullptr;
			size = 0;
			return;
		}

		Node* node = &getNode(size - 2);
		node->next = nullptr;
		delete node->next;
		size--;
	}
	unsigned getSize() const
	{
		return size;
	}
	bool isEmpty() const
	{
		return size == 0;
	}
	void clear()
	{
		while(!isEmpty())
		{
			popFront();
		}
	}

	T& operator[](unsigned index)
	{
		return getNode(index).value;
	}

	~LinkedList()
	{
		clear();
	}

private:
	struct Node
	{
		T value;
		Node* next = nullptr;

		Node(const T& value)
		: value{value} {}
	};

	Node& getNode(unsigned index)
	{
		Node* next = head;
		for(unsigned a = 0; a < index; a++)
		{
			next = next->next;
		}

		return *next;
	}

	Node* head = nullptr;
	unsigned size = 0;
};
