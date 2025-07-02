#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class LinkedList
{
private:
	struct Node {
		T data;
		Node* next;
		Node(const T& data) : data(data), next(nullptr){}
	};

	Node* head;
	Node* tail;
	size_t size;

public:
	LinkedList();
	~LinkedList();

	void AddToHead(const T&);
	void AddToTail(const T&);
	void DeleteFromHead();
	void DeleteFromTail();
	void DeleteAll();
	void Show() const;
};

