#include "IntegerQueue.h"
#include <iostream>

using namespace std;

IntegerQueue::IntegerQueue(int size) : BaseQueue(size),
	front(0), end(-1){
	data.resize(capacity);
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