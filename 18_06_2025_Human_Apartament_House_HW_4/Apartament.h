#pragma once
#include "Human.h"

class Apartament
{
private:
	Human* residents;
	int residentCount;
	int numberApartment;
	double area;

public:

	Apartament();
	Apartament(int, double);
	Apartament(const Apartament&);
	~Apartament();

	Apartament& operator=(const Apartament&);
	void print() const;

	void addResident(const Human&);

	int getNumber() const;
	double getArea() const;
	int getResidentCount() const;

};

