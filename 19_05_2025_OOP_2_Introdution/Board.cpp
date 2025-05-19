#include "Board.h"

// Сеттеры (setters) set - устанавливать
void Board::setName(std::string name) {
	this->name = name;
}

void Board::setMarks(int mark) {
	this->marks.push_back(mark);
}

// Геттеры (getters) get - получить
std::string Board::getName() {
	return name;
}

std::vector<int> Board::getMarks() {
	return marks;
}


double Board::getAver()
{
	double sum = 0;
	for (int i = 0; i < marks.size(); i++)
	{
		sum += marks[i];
	}
	return sum / marks.size();
}