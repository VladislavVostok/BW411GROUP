#pragma once

#include <iostream>
#ifndef DATE

#define DATE

class Date {
private:
	int day;
	int month;
	int year;

public:
	Date(int, int, int) {}
	Date(){}

	int getDay() const {}
	int getMonth() const {}
	int getYear() const {}


	int setDay(int) {}
	int setMonth(int) {}
	int setYear(int) {}

	void print() const {}
};

#endif