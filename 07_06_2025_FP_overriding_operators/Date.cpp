#include "Date.h"

using namespace std;

bool Date::isLeapYear() const {
	if (year % 4 != 0) return false;
	if (year % 100 == 0 && year % 400 == 0) return true;
}

int Date::daysInMonth() const {
	if (month == 2) 
		return isLeapYear() ? 29 : 28;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;

	return 31;
}	

void Date::normalize() {
	while (day > daysInMonth()) {
		day -= daysInMonth();
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}
}

int Date::toDays() const {
	int totalDays = day;
	for (int m = 1; m < month; ++m) {
		Date temp(1, m, year);
		totalDays += temp.daysInMonth();
	}
	
	totalDays += year * 365;
	totalDays += year / 4 - year / 100 + year / 400;
	return totalDays;

}

Date::Date(int d, int m, int y) :day(d), month(m), year(y) {
	normalize();
}

Date::Date(int y) : Date(1, 1, y) {}

int Date::operator-(const Date& other) const {
	return abs(toDays() - other.toDays());
}

Date& Date::operator+=(int days) {
	day += days;
	normalize();
	return *this;
}

Date Date::operator+(int days) const {
	Date result = *this;
	result += days;
	return result;
}

void Date::print() const {
	cout << day << "." << month << "." << year << endl;
}