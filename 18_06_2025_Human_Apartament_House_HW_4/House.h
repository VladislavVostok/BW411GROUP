#pragma once
#include "Apartament.h"

class House {
private:
	Apartament* apartments;
	int apartmentCount;
	int floors;
	char* address;

public:

	House();
	House(int, const char*);
	House(const House&);
	~House();

	House& operator=(const House&);
	void print() const;

	void addApartment( const Apartament&);

	const char* getAddress() const;
	int getFloors() const;
	int getApartmentCount() const;
};