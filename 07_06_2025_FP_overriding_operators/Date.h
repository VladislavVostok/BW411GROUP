#pragma once

#include <iostream>
#include <cmath>

class Date
{
private:
	int day;
	int month;
	int year;

	bool isLeapYear() const;
	int daysInMonth() const;
	void normalize();
	int toDays() const;

public:
	Date(int, int, int);
	Date(int);

	int operator-(const Date&) const;
	Date& operator+=(int);
	Date operator+(int) const;

	void print() const;
	
};

