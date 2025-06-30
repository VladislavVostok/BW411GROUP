#pragma once

#include <stdexcept>
#include "BaseQueue.h"
#include <vector>

using namespace std;

class IntegerQueue : public BaseQueue
{
protected:
	vector<int> data;
	int front; // ������ ������ �������
	int end;   // ������ ����� �������



public:
	IntegerQueue(int);


	void Enqueue(int) override;
	int Dequeue() override;
	void Show() const override;
	//int Peek() const;


};

