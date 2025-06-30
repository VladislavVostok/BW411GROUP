#include "BaseQueue.h"


BaseQueue::BaseQueue(int size) : capacity(size), count(0) {}

bool BaseQueue::IsEmpty() const {
	return count == 0;
}
bool BaseQueue::IsFull() const {
	return count == capacity;
}