#include "Human.h"


int Human::count = 0;

Human::Human(
		int id,
		const char* lastName,
		const char* firstName,
		const char* middleName,
		const Date& birthDate
) : id(id),
	birthDate(birthDate)
{
	this->lastName = new char[strlen(lastName) + 1];
	strcpy_s(this->lastName, strlen(lastName) + 1, lastName);

	this->firstName = new char[strlen(firstName) + 1];
	strcpy_s(this->firstName, strlen(firstName) + 1, firstName);

	this->middleName = new char[strlen(middleName) + 1];
	strcpy_s(this->middleName, strlen(middleName) + 1, middleName);

	count++;
}

Human::Human() : Human(0, "DontKnow", "DontKnow", "DontKnow", Date()) {}


Human::Human(const Human& other) : id(other.id), birthDate(other.birthDate)
{
	this->lastName = new char[strlen(other.lastName) + 1];
	strcpy_s(this->lastName, strlen(other.middleName) + 1, other.lastName);

	this->firstName = new char[strlen(other.firstName) + 1];
	strcpy_s(this->firstName, strlen(other.middleName) + 1, other.firstName);

	this->middleName = new char[strlen(other.middleName) + 1];
	strcpy_s(this->middleName, strlen(other.middleName) + 1, other.middleName);

	count++;
}

Human::~Human() {
	delete[] lastName;
	delete[] firstName;
	delete[] middleName;

	std::cout << "Объект c номером " << id << "удалён!" << std::endl; 
	count--;
}

int Human::getCount() {
	return count;
}

int Human::getId() const {
	return id;
}

const char* Human::getlastName() const {
	return lastName;
}

const char* Human::getfirstName() const {
	return firstName;
}

const char* Human::getmiddleName() const {
	return middleName;
}

Date Human::getbirthDate() const {
	return birthDate;
}

void Human::setId(int id) {
	this->id = id;
}

void Human::setlastName(const char* lastName) {
	delete[] this->lastName;
	this->lastName = new char[strlen(lastName) + 1];
	strcpy_s(this->lastName, strlen(lastName) + 1, lastName);
}

void Human::setfirstName(const char* firstName) {
	delete[] this->firstName;
	this->firstName = new char[strlen(firstName) + 1];
	strcpy_s(this->firstName, strlen(lastName) + 1, firstName);
}

void Human::setmiddleName(const char* middleName) {
	delete[] this->middleName;
	this->middleName = new char[strlen(middleName) + 1];
	strcpy_s(this->middleName, strlen(lastName) + 1, middleName);
}

void Human::setbirthDate(const Date& date) {
	birthDate = date;
}

void Human::print() const {
	std::cout << "Ид: " << id << std::endl;
	std::cout << "Фамилия: " << lastName << std::endl;
	std::cout << "Имя: " << firstName << std::endl;
	std::cout << "Отчество: " << middleName << std::endl;
	std::cout << "Дата рождения: " << birthDate.to_string() << std::endl;
}