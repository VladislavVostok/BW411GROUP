#include "Airplane.h"

Airplane::Airplane(const char * t, int maxP) 
	: passengers(0), maxPassengers(maxP) {

	type = new char[strlen(t) + 1];
	strcpy_s(type, strlen(t) + 1 , t);
}

Airplane::Airplane(Airplane&& other) {
	type = other.type;
	passengers = other.passengers;
	maxPassengers = other.maxPassengers;
	other.type = nullptr;
	other.passengers = 0;
	other.maxPassengers = 0;
}

Airplane& Airplane::operator++() {
	if (passengers < maxPassengers) {
		passengers++;
	}
	return *this;
}

Airplane& Airplane::operator--() {
	if (passengers > 0) {
		passengers--;
	}
	return *this;
}

bool Airplane::operator==(const Airplane& other) const {
	return type == other.type;
}

bool Airplane::operator>(const Airplane& other) const {
	return maxPassengers > other.maxPassengers;
}

void Airplane::printStatus() const {
	cout << "Тип: " << type
		<< ", Пассажиры: " << passengers
		<< "/" << maxPassengers << endl;
}