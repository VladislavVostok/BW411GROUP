#include <iostream>
#include "Date.h"
#include "Human.h"


/* Внимание!Программа завершается аварийно! Для этого
 примера это нормально.*/
class DynArray
{
	int* arr;
	int size;
public:


	DynArray(int sizeP)
		: arr{ new int[sizeP] {} }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size << " elements, for " << this << " for address " << this->arr << '\n';

	}
	DynArray() : DynArray(5) {}
	DynArray(const DynArray& object) : arr{ new int[object.size] {} }, size{ object.size }
	{
		for (size_t i = 0; i < object.size; ++i)
			arr[i] = object.arr[i];
		std::cout << "DynArr copy constructed for " << size << " elements, for " << this << "for address " << this->arr << '\n';
	}


	//static void print_stat(DynArray dArr);

	static void print_stat(const DynArray& dArr) {
		std::cout << &dArr << "\n";
	}

	int getElem(int idx) { return arr[idx]; }
	void setElem(int idx, int val) { arr[idx] = val; }
	void print();
	void randomize();

	~DynArray()
	{
		delete[] arr;
		std::cout << "DynArr destructed for"
			<< size << " elements, for"
			<< this << '\n';
	}
};
void DynArray::print()
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}


void DynArray::randomize()
{
	for (int i{ 0 }; i < size; ++i)
	{
		arr[i] = rand() % 10;
	}
}


void main()
{

	setlocale(LC_ALL, "");
	//DynArray ar1{ 10 };
	//ar1.randomize();
	//DynArray::print_stat(ar1);

	//std::cout << &ar1 << "\n";

	const Date days{ 29,30, 31 };
	Date days1{ 29,30, 31 };


	days.getDay();
	//std::cout << "ar1 elements: ";

	//ar1.print();
	//DynArray ar2{ ar1 };
	//std::cout << "ar2 elements: ";
	//ar2.print();

	Date birthDate(15, 5, 2025);
	Human person1(1, "Казначей", "Виктор", "Вячеславович", birthDate);
	person1.print();

	Human person2;
	person2.print();

	Human person3 = person1;
	person3.setId(3);
	person3.print();

	std::cout << person3.getCount() << std::endl;
	std::cout << Human::getCount() << std::endl;
}