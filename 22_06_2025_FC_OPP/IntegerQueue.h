#pragma once
#include <stdexcept>
class IntegerQueue
{
private:
	int* data;
	int capacity;
	int front; // ������ ������ �������
	int end;   // ������ ����� �������
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

