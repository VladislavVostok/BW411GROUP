#pragma once

#include <iostream>
#include <cstring>

class Human
{
private:
	char* fullName;
	int age;

public:
	Human();
	Human(const char*, int);
	Human(const Human&);
	Human(Human&&);

	inline ~Human() {
		if (fullName != nullptr) {
			delete[] fullName;
		}
	}

	Human& operator=(const Human&);
	Human& operator=(Human&&);
	void print() const;

	inline const char* getFullName() const {
		return fullName;
	};

	inline int getAge() const {
		return age;
	};

};

