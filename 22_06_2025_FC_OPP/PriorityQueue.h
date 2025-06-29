#pragma once
#include "IntegerQueue.h"
#include <stdexcept>

class PriorityQueue : public IntegerQueue
{

private:
	struct PriorityItem {
		int value;
		int priority;

		PriorityItem(int v = 0, int p = 0) : value(v), priority(p) {}

		bool operator<(const PriorityItem& other) const {

			return priority < other.priority;
		}
	};
		
	PriorityItem* priorityData;

public:
	PriorityQueue(int);
	void Enqueue(int) override;
	void InsertWithPriority(int, int);
	int Dequeue() override;
	int Peek() const override;
	void Show()const override;
};