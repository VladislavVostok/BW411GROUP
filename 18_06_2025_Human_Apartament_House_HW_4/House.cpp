#include "House.h"
#include "Apartament.h"

using namespace std;

House::House(): apartments(nullptr), apartmentCount(0), floors(0), address(nullptr) {}

House::House(int f, const char* addr): apartments(nullptr), apartmentCount(0), floors(f) {
	address = new char[strlen(addr) + 1];
	strcpy_s(address, strlen(addr) + 1, addr);
}

House::House(const House& other) {
	
		if (apartments != nullptr) {
			delete[] apartments;
		}

		apartmentCount = other.apartmentCount;
		floors = other.floors;

		if (address != nullptr) {
			delete[] address;
		}

		address = new char[strlen(other.address) + 1];
		strcpy_s(address, strlen(other.address) + 1, other.address);

		apartments = new Apartament[apartmentCount];

		for (int i = 0; i < apartmentCount; ++i) {
			apartments[i] = other.apartments[i];
		}
}


House::~House() {

		if (apartments != nullptr) {
			delete[] apartments;
		}

		if (address != nullptr) {
			delete[] address;
		}
	}


House& House::operator=(const House& other) {
	if (this != &other) {

		if (apartments != nullptr) {
			delete[] apartments;
		}

		apartmentCount = other.apartmentCount;
		floors = other.floors;

		if (address != nullptr) {
			delete[] address;
		}

		address = new char[strlen(other.address) + 1];
		strcpy_s(address, strlen(other.address) + 1, other.address);

		apartments = new Apartament[apartmentCount];

		for (int i = 0; i < apartmentCount; ++i) {
			apartments[i] = other.apartments[i];
		}
	}
	return *this;
}
void House::print() const {
	cout << address << endl;
}

void House::addApartment(const Apartament& apartment) {
	Apartament* temp = new Apartament[apartmentCount + 1];
	for (int i = 0; i < apartmentCount; ++i) {
		temp[i] = apartments[i];
	}

	temp[apartmentCount] = apartment;

	delete[] apartments;
	apartments = temp;
	apartmentCount++;
}

const char* House::getAddress() const {
	return address;
}
int House::getFloors() const {
	return floors;
}
int House::getApartmentCount() const {
	return apartmentCount;
}