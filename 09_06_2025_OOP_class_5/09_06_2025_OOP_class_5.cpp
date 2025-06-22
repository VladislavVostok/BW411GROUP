#include <iostream>
#include <cassert>

class Singelton {
private:
	std::string name{ "IM1" };

	Singelton() = default;


	static Singelton* obj;

public:
	~Singelton() = default;
	static Singelton* getInstance() {
		if (obj) {
			return obj;
		}

		obj = new Singelton();

		return obj;
	}

};

Singelton* Singelton::obj = nullptr;




class DynArray
{
	int* arr;
	int size;


public:

	DynArray(int sizeP) : arr{ new int[sizeP] {} }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size << " elements, for " << this << '\n';
	}
	DynArray() = default;
	

	//DynArray(const DynArray& object)
	//	: arr{ new int[object.size] }, size{ object.size }
	//{
	//	for (int i{ 0 }; i < size; ++i)
	//	{
	//		arr[i] = object.arr[i];
	//	};
	//	std::cout << "DynArr copy constructed for "
	//		<< size << " elements, for " << this
	//		<< '\n';   
	//}

	//DynArray(DynArray&& object)
	//	: arr{ object.arr }, size{ object.size }
	//{
	//	object.arr = nullptr;
	//	object.size = 0;
	//	std::cout << "DynArr move constructed for "
	//		<< size << " elements, for " << this
	//		<< '\n';
	//}


	DynArray& operator=(const DynArray& object) = default;
	//DynArray& operator=(const DynArray&& object) = default;


	//DynArray& operator=(const DynArray& object)
	//{
	//	if (!(this == &object))
	//	{
	//		if (size != object.size)
	//		{
	//			delete arr;
	//			arr = new int[object.size];
	//		}
	//		size = object.size;
	//		int* dest{ arr };
	//		int* src{ object.arr };
	//		int* const end{ arr + size };
	//		while (dest < end)
	//		{
	//			*dest++ = *src++;
	//		}
	//	}

	//	std::cout << "dynarr copy assigned for "
	//		<< size << " elements, for " << this
	//		<< '\n';
	//	return *this;
	//}

	//DynArray& operator=(DynArray&& object)
	//{
	//	if (!(this == &object))
	//	{
	//		delete arr;
	//		arr = object.arr;
	//		size = object.size;
	//		object.arr = nullptr;
	//		object.size = 0;
	//	}
	//	std::cout << "dynarr move assigned for "
	//		<< size << " elements, for " << this
	//		<< '\n';
	//	return *this;
	//}


// константная перегрузка, возвращающая элемент
 // по значению
	int operator[](int idx)const
	{
		assert(idx >= 0 and idx < size and "Index is out "
			"of range!");
		return arr[idx];
	}
	// не константная перегрузка, возвращающая элемент
	// по ссылке
	int& operator[](int idx)
	{
		assert(idx >= 0 and idx < size && "Index is out"
			"of range!");
		return arr[idx];
	}

	void print()const;
	void randomize();

	~DynArray()
	{
		std::cout << "Try to free memory from DynArray for"
			<< arr << " pointer\n";
		delete[] arr;
		std::cout << "DynArr destructed for " << size
			<< " elements, for " << this << '\n';
	}
};
void DynArray::print()const
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
DynArray arrayFactory(int arrSize)
{
	DynArray arr{ arrSize };
	arr.randomize();
	return arr;
}

int main()
{

	Singelton* sing1 = Singelton::getInstance();
	Singelton* sing2 = Singelton::getInstance();

	delete sing1;
	const int arrSize{ 10 };


	DynArray ar1{ arrayFactory(arrSize) };


	for (int i{ 0 }; i < arrSize; ++i)
	{
		ar1[i] *= ar1[i];
		std::cout << "ar1[" << i << "] = " << ar1[i] << '\n';
	}
	DynArray arrrr;
	std::cout << "ar1 elements: ";
	ar1.print();
	std::cout << "\nMove content from ar1 to ar2.\n\n";
	DynArray ar2{ ar1 }; /* ar1 теперь "пуст",но "жив"! */
	std::cout << "ar1 elements: ";
	ar1.print();
	std::cout << "ar2 elements: ";
	ar2.print();
	std::cout << "\nReuse ar1.\n\n";
	ar1 = arrayFactory(5); /* ar1 "жив" а следовательно	может быть повторно	использован */

		std::cout << "ar1 elements: ";
	ar1.print();
	return 0;
}