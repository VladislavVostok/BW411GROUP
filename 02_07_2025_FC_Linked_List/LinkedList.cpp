#include "LinkedList.h"


template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}


template <typename T>
LinkedList<T>::~LinkedList(){
	DeleteAll();
}


// Добваление элемента в начало (Голову) head

template <typename T>
void LinkedList<T>::AddToHead(const T& data) {
	Node* newNode = new Node(data);
	if (!head) {
		head = tail = newNode;
	} else {
		newNode->next = head;
		head = newNode;
	}
	size++;
}

template <typename T>
void LinkedList<T>::AddToTail(const T& data) {
	Node* newNode = new Node(data);
	if (!tail) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}

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

template <typename T>
void LinkedList<T>::DeleteAll(){
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	tail = nullptr;
	size = 0;
}

template <typename T>
void LinkedList<T>::Show() const {

	Node* current = head;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}

	cout << endl;
}