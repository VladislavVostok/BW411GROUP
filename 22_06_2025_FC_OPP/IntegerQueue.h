#pragma once
#include <stdexcept>
class IntegerQueue
{
private:
	int* data;
	int capacity;
	int front; // Индекс начала очереди
	int end;   // Индекс конца очереди
	int count;
public:
	IntegerQueue(int);
	~IntegerQueue();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(int);
	int Dequeue();
	void Show() const;

};

