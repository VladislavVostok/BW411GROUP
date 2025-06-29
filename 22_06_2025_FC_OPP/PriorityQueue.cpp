#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int size):IntegerQueue(size){}

void PriorityQueue::Enqueue(int value) {
	throw std::logic_error("Используейте функцию InsertWithPriority для PriorityQueue!");
}

