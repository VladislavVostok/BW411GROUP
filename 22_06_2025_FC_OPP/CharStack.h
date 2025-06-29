#include "Array.h"
#include <stdexcept>

#pragma once
class CharStack
{
private:
	Array<char> stackArray;
	int top;

public:
	CharStack(int);
	void push(char);
	char pop();
	int count() const;
	bool isEmpty() const;
	bool isFull() const;
	void clear();
	char peek() const;
	int getCapacity() const;
	int getSize() const;
	void shrinkToFit();
};