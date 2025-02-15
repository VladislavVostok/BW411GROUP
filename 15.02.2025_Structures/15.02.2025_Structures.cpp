#include <iostream>
#include <string>

using namespace std;

const int namesize = 6;
const int adrsize = 6;


struct DynamicArray {
	int* data;
	int size;

	DynamicArray(int size) : size(size) {
		data = new int[size];
	}

	~DynamicArray() {
		delete[] data;
	}
};


struct date
{
	int day; // День.
	int year; // Год.
	char month[10]; // Месяц.
};
struct Person {
	std::string name;
	int age;
	static int count;

	void introduce() const {
		std::cout << "Hi, my name is " << name << " and I am " << age << " years old.\n";
	}

	static void printCount() {
		std::cout << "Total persons: " << count << std::endl;
	}

};

struct complex_digit {
	int Im;
	int Re;

	//complex_digit(int im, int re) : Im(im), Re(re){}
	complex_digit(int im, int re) {
		Im = im;
		Re = re;
	}

	complex_digit operator+(complex_digit other) {
		return complex_digit{ Im + other.Im, Re + other.Re };
	}

	friend ostream& operator <<(ostream& os, const complex_digit& p) {
		os << p.Im << " + " << p.Re << "i";
		return os;
	}


};




void printPerson(const Person* p) {
	std::cout << p->name << " is " << p->age << " years old.\n";
}

int main()
{
	Person t;
	Person* pPers = &t;

	pPers->age;
	(*pPers).age;

	Person* p3 = new Person{ "" };
	p3->age;

	printPerson(&t);
	printPerson(pPers);


	Person persons[] = { {"Alice", 25} , {"Vasya", 25}, t };

	for(int  i = 0; i < 3; i++)
	{
		persons[i].introduce();
	}


	// обращение к статическим переменным и методам без создания объекта
	Person::count = 3;
	Person::printCount();

	complex_digit cd1(1,3);
	complex_digit cd2(1,5);

	complex_digit res = cd1 + cd2;
	cout << res;


	DynamicArray da(5);
	da.~DynamicArray();

	delete p3;


}