#include "Apartament.h"


Apartament::Apartament()
	: residents(nullptr), 
	residentCount(0), 
	numberApartment(0), 
	area(0.0) {}

Apartament::Apartament(int num, double a)
	:residents(nullptr), 
	residentCount(0), 
	numberApartment(num), 
	area(a){}

Apartament::Apartament(const Apartament& other) 
	: residentCount(other.residentCount), 
	numberApartment(other.numberApartment), 
	area(other.area) 
{
	residents = new Human[residentCount];
	for (int i = 0; i < residentCount; ++i) {
		residents[i] = other.residents[i];
	}
}
Apartament::~Apartament() {
	if (residents != nullptr) {
		delete[] residents;
	}
}

Apartament& Apartament::operator=(const Apartament& other) {

	if (this != &other) {

		if (residents != nullptr) {
			delete[] residents;
		}

		residentCount = other.residentCount;
		numberApartment = other.numberApartment;
		area = other.area;

		residents = new Human[residentCount];

		for (int i = 0; i < residentCount; ++i) {
			residents[i] = other.residents[i];
		}
	}

	return *this;
}
void Apartament::print() const {

}

void Apartament::addResident(const Human& human) {
	Human* temp = new Human[residentCount + 1];
	for (int i = 0; i < residentCount; ++i) {
		temp[i] = residents[i];
	}

	temp[residentCount] = human;
	
	delete[] residents;
	residents = temp;
	residentCount++;
}

int Apartament::getNumber() const {
	return numberApartment;
}
double Apartament::getArea() const {
	return area;
}
int Apartament::getResidentCount() const {
	return residentCount;
}