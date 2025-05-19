#include "Board.h"

// ������� (setters) set - �������������
void Board::setName(std::string name) {
	this->name = name;
}

void Board::setMarks(int mark) {
	this->marks.push_back(mark);
}

// ������� (getters) get - ��������
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