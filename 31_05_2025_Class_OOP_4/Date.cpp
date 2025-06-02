

#include "Date.h"


Date::Date(int d, int m, int y) : day(d), month(m), year(y), baseYear(2000), currentYear(year) {}
Date::Date() : Date(1,1,1970){}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }


void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int y) { year = y; }

std::string Date::to_string() const {
	std::stringstream ss;
	ss << day << "." << month << "." << year;
	return ss.str();
}
