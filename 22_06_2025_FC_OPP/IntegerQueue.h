#pragma once
#include <stdexcept>
class IntegerQueue
{
protected:
	int* data;
	int capacity;
	int front; // ������ ������ �������
	int end;   // ������ ����� �������
	int count;


public:
	IntegerQueue(int);
	virtual ~IntegerQueue();
	virtual bool IsEmpty() const;
	virtual bool IsFull() const;
	virtual void Enqueue(int);
	virtual int Dequeue();
	virtual int Peek() const;
	virtual void Show() const;

};

