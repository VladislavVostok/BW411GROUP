#include "Date.h"


Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}
Date::Date() : Date::Date(1,1,1970){}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }


int Date::setDay(int d) { day = d; }
int Date::setMonth(int m) { month = m; }
int Date::setYear(int y) { year = y; }

void Date::print() const {
	std::cout << day << "." << month << "." << year;
}