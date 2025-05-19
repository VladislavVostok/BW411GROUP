#include <string>
#include <vector>
#include <iostream>

#pragma once

class Board
{
	// Тело класса
	// Списки элементов класса
	// Поле класса (Атрибут класса, член-переменная класса)
	// 
	// ФИО
private:
	std::string name;
	// оценки
	std::vector<int> marks;
	int a;

protected:
	int login = 10;

public:
	// Методы класса (член-метод класса)

	//Конструктор

	//Деструктор


	// Сеттеры (setters) set - устанавливать
	void setName(std::string name);

	void setMarks(int mark);

	// Геттеры (getters) get - получить
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