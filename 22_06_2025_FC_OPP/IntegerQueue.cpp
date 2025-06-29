#include "IntegerQueue.h"
#include <iostream>

using namespace std;

IntegerQueue::IntegerQueue(int size) :
	capacity(size), front(0), end(-1), count(0) {
	data = new int[capacity];
}

IntegerQueue::~IntegerQueue() {
	delete[] data;
}

bool IntegerQueue::IsEmpty() const {
	return count == 0;
}

bool IntegerQueue::IsFull() const {
	return count == capacity;
}

void IntegerQueue::Enqueue(int value) {
	if (IsFull()) {
		throw std::overflow_error("Очередь полная!");
	}

	end = (end + 1) % capacity;
	data[end] = value;
	count++;
}

int IntegerQueue::Dequeue() {
	if (IsEmpty()) {
		throw std::underflow_error("Очередь пуста!");
	}

	int value = data[front];

	front = (front + 1) % capacity;

	count--;
	return value;
}

void IntegerQueue::Show() const {
	if (IsEmpty()) {
		cout << "Очередь пуста!" << endl;
		return;
	}

	int i = front;
	int items = count;
	while (items--) {
		cout << data[i] << " ";
		i = (i + 1) % capacity;
	}

	cout << endl;

}