#include <string>
#include <vector>
#include <iostream>

#pragma once

class Board
{
	// ���� ������
	// ������ ��������� ������
	// ���� ������ (������� ������, ����-���������� ������)
	// 
	// ���
private:
	std::string name;
	// ������
	std::vector<int> marks;
	int a;

protected:
	int login = 10;

public:
	// ������ ������ (����-����� ������)

	//�����������

	//����������


	// ������� (setters) set - �������������
	void setName(std::string name);

	void setMarks(int mark);

	// ������� (getters) get - ��������
	std::string getName();
	std::vector<int> getMarks();
	double getAver();
};

class Test : Board {

public:
	void Hello() {
		std::cout << login;
	}

};