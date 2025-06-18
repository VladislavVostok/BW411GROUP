#include "Human.h"

using namespace std;

Human::Human() :fullName(nullptr), age(0) {}

Human::Human(const char* name, int age) : age(age) {
	fullName = new char[strlen(name) + 1];
	strcpy_s(fullName, strlen(name) + 1, name);
}

Human::Human(const Human& other) : age(other.age) {
	fullName = new char[strlen(other.fullName) + 1];
	strcpy_s(fullName, strlen(other.fullName) + 1, other.fullName);
}

Human::Human(Human&& other) : age(other.age), fullName(other.fullName) {
	other.fullName = nullptr;
	other.age = 0;
}

Human& Human::operator=(const Human& other) {
	if (this != &other) {
		if (fullName != nullptr) {
			delete[] fullName;
		}
		fullName = new char[strlen(other.fullName) + 1];
		strcpy_s(fullName, strlen(other.fullName) + 1, other.fullName);
		age = other.age;
	}
	return *this;
}

Human& Human::operator=(Human&& other) {
	
		delete[] fullName;

		fullName = other.fullName;
		age = other.age;

		other.fullName = nullptr;
		other.age = 0;
	
	return *this;
}

void Human::print() const {
	cout << "ФИО: " << (fullName ? fullName : "Имени нет!")
		<< ", Возраст: " << age << endl;
}


