#pragma once

#include <iostream>
#include <string>

using namespace std;

class Airplane
{
	char* type;
	int passengers;
	int maxPassengers;

public:
	Airplane(const char*, int);
	Airplane(Airplane&&);
	Airplane& operator++();
	Airplane& operator--();
	bool operator==(const Airplane&) const;
	bool operator>(const Airplane&) const;


	void printStatus() const;
	
};