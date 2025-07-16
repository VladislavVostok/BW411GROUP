#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class LinkedList
{
private:

	class Node {
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
	void InsertAt(size_t, const T&);


	void DeleteFromHead();
	void DeleteFromTail();
	void DeleteAt(size_t);

	void DeleteAll();
	
	int Find(const T&) const;
	int Replace(const T&, const T&);
	void Reverse();

	void Show() const;


};


template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}


template <typename T>
LinkedList<T>::~LinkedList() {
	DeleteAll();
}


// Добваление элемента в начало (Голову) head. O(1)

template <typename T>
void LinkedList<T>::AddToHead(const T& data) {
	Node* newNode = new Node(data);
	if (!head) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	size++;
}

// O(1)
template <typename T>
void LinkedList<T>::AddToTail(const T& data) {
	Node* newNode = new Node(data);
	if (!tail) { // В случае пустого список
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}


// O(n)
template <typename T>
void LinkedList<T>::InsertAt(size_t position, const T& data) {
	if (position > size) {
		throw out_of_range("Позиция за пределами последовательности!");
	}

	if (position == 0) {
		AddToHead(data);
		return;
	}

	if (position == size) {
		AddToTail(data);
		return;
	}


	Node* newNode = new Node(data);
	Node* current = head;

	for (size_t i = 0; i < position - 1; ++i) {
		current = current->next;
	}

	newNode->next = current->next;
	current->next = newNode;
	size++;
}

// O(1)
template <typename T>
void LinkedList<T>::DeleteFromHead() {

	if (!head) {
		throw runtime_error("Список пуст!");
	}

	Node* temp = head;
	head = head->next;
	delete temp;
	size--;

	if (!head) {
		tail = nullptr;
	}
}

// O(1)
template <typename T>
void LinkedList<T>::DeleteFromTail() {

	if (!tail) {
		throw runtime_error("Список пуст!");
	}

	if (head == tail) {
		delete tail;
		head = tail = nullptr;
		size--;
		return;
	}

	Node* current = head;
	while (current->next != tail) {
		current = current->next;
	}

	delete tail;
	tail = current;
	tail->next = nullptr;
	size--;
}


// O(n)
template <typename T>
void LinkedList<T>::DeleteAt(size_t position) {

	if (position >= size) {
		throw out_of_range("Позиция за пределами последовательности!");
	}

	if (position == 0) {
		DeleteFromHead();
		return;
	}

	if (position == size - 1) {
		DeleteFromTail();
		return;
	}

	Node* current = head;
	for (size_t i = 0; i < position - 1; ++i) {
		current = current->next;
	}

	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
	size--;
}

//O(n)
template <typename T>
void LinkedList<T>::DeleteAll() {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	tail = nullptr;
	size = 0;
}


// O(n)
template <typename T>
int LinkedList<T>::Find(const T& data) const {
	Node* current = head;
	int position = 0;

	while (current) {
		if (current->data == data) {
			return position;
		}
		current = current->next;
		position++;
	}

	return -1;
}

//O(n)
template <typename T>
int LinkedList<T>::Replace(const T& dataOld, const T& dataNew) {
	int count = 0;

	Node* current = head;

	while (current) {
		if (current->data == dataOld) {
			current->data = dataNew;
			count++;
		}
		current = current->next;
	}

	return count > 0 ? count : -1;
}

// O(n)
template <typename T>
void LinkedList<T>::Reverse() {
	if (!head || !head->next) {
		return;
	}

	Node* prev = nullptr;
	Node* current = head;
	Node* next = nullptr;

	tail = head;

	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
}

// O(n)
template <typename T>
void LinkedList<T>::Show() const {

	Node* current = head;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}

	cout << endl;
}