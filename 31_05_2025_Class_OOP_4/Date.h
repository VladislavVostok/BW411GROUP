#pragma once

#include <sstream>
#include <iostream>
#include <string>

#ifndef DATE

#define DATE

class Date {
private:
	const int baseYear;
	int& currentYear;
	int day;
	int month;
	int year;

public:
	Date(int, int, int);
	Date();

	int getDay() const ;
	int getMonth() const;
	int getYear() const;


	void setDay(int);
	void setMonth(int);
	void setYear(int);

	std::string to_string() const;
};

#endif