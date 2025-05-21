#include "Animal.h"

#include <string>


using namespace std;

#pragma once
class Dog : public Animal
{

private:
	string breed;

public:
	Dog(const string&, int, const string&);
	void makeSound() const override;
	void  fetch();
	void displayInfo();
	~Dog() override;
};

