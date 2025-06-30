#pragma once
#include "BaseQueue.h"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class PriorityQueue : public BaseQueue
{

private:
	struct Item {
		int value;
		int priority;
		bool operator<(const Item& other) const {

			return priority < other.priority;
		}
	};
		
	vector<Item> heap;

	void heapifyUp(int);
	void heapifyDown(int);


	

public:
	PriorityQueue(int);
	void Enqueue(int) override;
	void EnqueueWithPriority(int, int);
	int Dequeue() override;
	void Show() const override;
};