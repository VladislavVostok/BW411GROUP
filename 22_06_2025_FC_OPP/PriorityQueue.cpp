#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int size): BaseQueue(size){}

void PriorityQueue::Enqueue(int value) {
	//throw std::logic_error("Используейте функцию EnqueueWithPriority для PriorityQueue!");
	EnqueueWithPriority(value, 0);
}

void PriorityQueue::EnqueueWithPriority(int value, int priority) {
	if (IsFull()) {
		throw std::overflow_error("Приоритетная очередь полная.");
	}

	heap.push_back({ value, priority });
	heapifyUp(heap.size() - 1);
	count++;
}

void PriorityQueue::heapifyUp(int index) {
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (heap[index] < heap[parent]) break;

		swap(heap[index], heap[parent]);
		index = parent;
	}
}

int PriorityQueue::Dequeue() {
	if (heap.empty()) throw underflow_error("Приоритетная очередь пустая.");

	int result = heap[0].value;
	heap[0] = heap.back();
	heap.pop_back();

	if (!heap.empty()) {
		heapifyDown(0);
	}

	count--;

	return result;
}


void PriorityQueue::heapifyDown(int index) {

	while (true) {
		int left = 2 * index + 1;
		int right = 2 * index + 2;

		int largest = index;

		if (left < heap.size() && heap[largest] < heap[left])
			largest = left;

		if (right < heap.size() && heap[largest] < heap[right])
			largest = right;

		if (largest == index) break;

		swap(heap[index], heap[largest]);

		index = largest;
	}

}

void PriorityQueue::Show() const {
	if (IsEmpty()) {
		cout << "Очередь с приоритетом пуста!" << endl;
		return;
	}

	for (const auto& item : heap) {
		cout << item.value << " (приоритет: " << item.priority << ")" << endl;
	}
	cout << "______" << endl;
}