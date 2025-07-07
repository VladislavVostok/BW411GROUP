#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class DoublyLinkedList
{
private:
	struct Node {
		T data;
		Node* prev;
		Node* next;
		Node(const T& data) : data(data), prev(nullptr), next(nullptr){}
	};

	Node* head;
	Node* tail;
	size_t size;

public:
	DoublyLinkedList();
	~DoublyLinkedList();

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

	size_t Size() const;
	bool isEmpty() const;

};


template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}


template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	DeleteAll();
}


// Добваление элемента в начало (Голову) head. O(1)

template <typename T>
void DoublyLinkedList<T>::AddToHead(const T& data) {
	Node* newNode = new Node(data);
	if (!head) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	size++;
}

// O(1)
template <typename T>
void DoublyLinkedList<T>::AddToTail(const T& data) {
	Node* newNode = new Node(data);
	if (!tail) { // В случае пустого список
		head = tail = newNode;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}


// O(n/2)
template <typename T>
void DoublyLinkedList<T>::InsertAt(size_t position, const T& data) {
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

	Node* current;
	if (position < size / 2) {
		current = head;
		for (size_t i = 0; i < position; ++i) {
			current = current->next;
		}
	}
	else {
		current = tail;
		for (size_t i = size - 1; i > position; --i) {
			current = current->prev;
		}
	}

	Node* newNode = new Node(data);

	newNode->prev = current->prev;

	newNode->next = current;
	current->next = newNode;
	current->prev->next = newNode;
	current->prev = newNode;
	size++;
}

// O(1)
template <typename T>
void DoublyLinkedList<T>::DeleteFromHead() {

	if (!head) {
		throw runtime_error("Список пуст!");
	}

	Node* temp = head;
	head = head->next;

	if (head) {
		head->prev = nullptr;
	}
	else {
		tail = nullptr;
	}

	delete temp;
	size--;

}

// O(1)
template <typename T>
void DoublyLinkedList<T>::DeleteFromTail() {

	if (!tail) {
		throw runtime_error("Список пуст!");
	}

	Node* temp = tail;
	tail = tail->prev;
	if (tail) {
		tail->next = nullptr;
	}
	else {
		head = nullptr;
	}

	delete temp;
	size--;
}


// O(n)
template <typename T>
void DoublyLinkedList<T>::DeleteAt(size_t position) {

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

	Node* current;
	if(position < size / 2){
		current = head;
		for (size_t i = 0; i < position; ++i) {
			current = current->next;
		}
	}
	else {
		current = tail;
		for (size_t i = size - 1; i > position; --i) {
			current = current->prev;
		}
	}

	current->prev->next = current->next;
	current->next->prev = current->next;
	delete current;
	size--;
}

//O(n)
template <typename T>
void DoublyLinkedList<T>::DeleteAll() {

	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	tail = nullptr;
}


// O(n)
template <typename T>
int DoublyLinkedList<T>::Find(const T& data) const {
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
int DoublyLinkedList<T>::Replace(const T& dataOld, const T& dataNew) {
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
void DoublyLinkedList<T>::Reverse() {
	if (!head || !head->next) {
		return;
	}

	Node* current = head;
	Node* temp = nullptr;

	while (current) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;

		current = current->prev;
	}

	temp = head;
	head = tail;
	tail = temp;
}

// O(n)
template <typename T>
void DoublyLinkedList<T>::Show() const {

	Node* current = head;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}

	cout << endl;
}

// O(1)
template <typename T>
size_t DoublyLinkedList<T>::Size() const {
	return size;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
	return size == 0;
}