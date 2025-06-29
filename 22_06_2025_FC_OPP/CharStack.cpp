#include "CharStack.h"

CharStack::CharStack(int size = 10) 
	: stackArray(size), top(-1) {}


bool CharStack::isFull() const {
	return top == stackArray.GetSize() - 1;
}

bool CharStack::isEmpty() const {
	return top == - 1;
}

void CharStack::push(char c) {
	if (isFull()) {
		//throw std::overflow_error("Стек полон!");
		stackArray.SetSize(stackArray.GetSize() * 2);
	}
	stackArray.Add(c);
	top = stackArray.GetUpperBound();
}

char CharStack::pop() {
	if (isEmpty()) {
		throw std::underflow_error("Стек пуст!");
	}
	char popPeek = stackArray.GetAt(top);
	stackArray.RemoveAt(top);

	top = stackArray.GetUpperBound();

	return popPeek;
}

int CharStack::count() const {
	return stackArray.GetSize();
}

void CharStack::clear() {
	stackArray.RemoveAll();
	top = stackArray.GetUpperBound();
}

char CharStack::peek() const {
	if (isEmpty()) {
		throw std::underflow_error("Стек пуст!");
	}

	return stackArray[top];
}

int CharStack::getCapacity() const {
	return stackArray.GetSize();
}

int CharStack::getSize() const {
	return top + 1;
}

void CharStack::shrinkToFit() {
	if (getSize() < getCapacity()) {
		stackArray.SetSize(getSize());
	}
}


















