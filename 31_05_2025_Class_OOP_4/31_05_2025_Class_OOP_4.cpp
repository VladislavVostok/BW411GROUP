#include <iostream>
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




int main()
{
	DynArray ar1{ 10 };
	ar1.randomize();
	DynArray::print_stat(ar1);

	std::cout << &ar1 << "\n";



	std::cout << "ar1 elements: ";

	ar1.print();
	DynArray ar2{ ar1 };
	std::cout << "ar2 elements: ";
	ar2.print();
	return 0;
}