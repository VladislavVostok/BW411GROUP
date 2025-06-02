#pragma once

#include <iostream>
#include "Date.h"

#ifndef HUMAN

#define HUMAN

//2. Создать класс Человек.

//Поля:
	// ■ идентификационный номер;
	// ■ фамилия;
	// ■ имя;
	// ■ отчество(для фамилии, имени и отчества память выделять динамически!);
	// ■ дата рождения(рекомендуется создать дополнительный класс Дата(день, месяц, год);

//Функции - члены:
	// ■ конструктор с  параметрами: 
	//  -> идентификационный
	//	-> номер, 
	//	-> фамилия, 
	//	-> имя, 
	//	-> отчество, 
	//	-> дата рождения.
	// В конструкторе использовать список инициализаторов полей класса;
	// ■ конструктор по умолчанию. В конструкторе использовать делегирование конструктора;
	// ■ конструктор копирования;
	// ■ деструктор;
	// ■ функцию - член для подсчета созданных экземпляров класса «Человек»;
	// ■ сеттеры / геттеры для соответствующих полей класса;
	// ■ вывод на экран информации о человеке

class Human
{
private:
	int id;
	char* lastName;
	char* firstName;
	char* middleName;
	Date birthDate;

	static int count;

public:
	Human(int, const char*, const char*, const char*, const Date&);
	Human();
	Human(const Human&);
	~Human();

	static int getCount();

	int getId() const;
	const char* getlastName() const;
	const char* getfirstName() const;
	const char* getmiddleName() const;
	Date getbirthDate() const;

	void setId(int);
	void setlastName(const char*);
	void setfirstName(const char*);
	void setmiddleName(const char*);
	void setbirthDate(const Date&);


	void print() const;

};



#endif // DEBUG