#pragma once
class BaseQueue
{
protected:
	int capacity;
	int count;

public:
	BaseQueue(int);
	virtual ~BaseQueue(){}

	virtual void Enqueue(int value) = 0;
	virtual int Dequeue() = 0;

	virtual bool IsEmpty() const;
	virtual bool IsFull() const;
	virtual void Show() const = 0;
};

