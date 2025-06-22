#include <iostream>
#include <conio.h>

//class MyInt {
//private:
//    int value;
//
//public:
//    explicit MyInt(int x) : value(x){}
//    int getValue() const {
//        return value;
//    }
//
//};
//
//void printInt(const MyInt& num) {
//    std::cout << num.getValue() << std::endl;
//}
//
//
//int main()
//{
//    //printInt(42);         // Передаём другой тип, если убрать explicit, то произойдёт неявное преобразование int в MyInt
//    //printInt(MyInt(42));  // Передаём объект, т.к. explicit заперщает неявное преобразование.
//    printInt((MyInt)45);    // Но можем явно преобразовать тип int в MyInt 
//
//}



//#include <iostream>
//#include <stdio.h>
//class Date
//{
//private:
//	int day;
//	int month;
//	int year;
//
//public:
//	Date(int day, int month, int year) : day{ day }, month{ month }, year{ year }{}
//	Date(int year) : Date(1, 1, year){}
//
//	friend void displayDate(Date date);
//
//};
//
//void displayDate(Date date)
//{
//	std::cout << date.day << "." << date.month << "." <<
//		date.year << std::endl;
//}
//
//Date baseDate()
//{
//	return 2000;
//}
//
//
////Про friend ключевое слово
//
////class SecretKeeper {
////private:
////	int secretCode = 1234;
////	friend class Hacker;
////};
////
////class Hacker {
////public:
////	void giveSecret(const SecretKeeper& keeper) {
////		std::cout << "Хакнули код: " << keeper.secretCode << std::endl;
////	}
////
////};
//
//
//
//int main()
//{
//
//	//SecretKeeper keeper;
//	//Hacker hacker;
//	//hacker.giveSecret(keeper);
//
//
//
//	displayDate(2020.0);
//	Date date = 2010.0;
//	displayDate(date);
//	Date date2000 = baseDate();
//	displayDate(date2000);
//	getchar();
//	return 0;
//}



//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//
//class Array
//{
//	int size;
//	int* array;
//public:
//	explicit Array(int size = 10);
//	~Array();
//	int getSize() const;
//	int getValue(int index) const;
//	void setValue(int index, int value);
//	void display(int index) const;
//};
//
//
//Array::Array(int size)
//{
//	Array::size = size;
//	array = new int[size];
//}
//
//Array::~Array()
//{
//	delete[] array;
//}
//
//int Array::getSize() const
//{
//	return size;
//}
//
//int Array::getValue(int index) const
//{
//	return array[index];
//}
//
//void Array::setValue(int index, int value)
//{
//	array[index] = value;
//}
//
//void Array::display(int index) const
//{
//	cout << array[index] << " ";
//}
//
//
//
//
//void display(const Array& array)
//{
//	for (int i = 0; i < array.getSize(); i++)
//	{
//		array.display(i);
//	}
//	cout << endl;
//}

class Point
{
private:
	double x;
	double y;

public:

	Point(double x, double y): x(x), y(y){}
	Point(): Point(1,1){}

	//Метод-член
	Point operator+ (const Point& other) {
		return Point{ this->x * other.x, this->y * other.y };
	}

	Point operator+(int a) {
		return Point{ this->x * a, this->y * a };
	}

	const Point& operator++(int)
	{
		
		x++; y++;
		return *this; // возвращается временный объект

	}

	static const Point add(const Point& point1, const Point& point2)
	{
		return Point(point1.x + point2.x, point1.y + point2.y);
	}


	friend std::ostream& operator<< (std::ostream& output, const Point& point)
	{
		output << "(" << point.x << "," << point.y << ")";
		return output;
	}
	friend std::istream& operator>> (std::istream& input, Point& point)
	{
		input >> point.x;
		input.ignore(1);
		input >> point.y;
		return input;
	}
	//

	// Функция друг
	//friend Point operator+ (const Point&, const Point&);


};

// Метод вынесенные за пределы класса
//Point Point::operator+(const Point& other) {
//	return Point{ this->x + other.x, this->y + other.y };
//}

// реализация функция друга   если поля класса public Глобальная фукнция
//Point operator+(const Point& first, const Point& second) {
//	return Point{ first.x + second.x, first.y + second.y };
//}


int main()
{

	//cout << "Dynamic integer array" << endl;

	/*int size = 4;

	Array array(size);

	for (int i = 0; i < size; i++)
	{
		array.setValue(i, size - i);
	}

	display(array);

	cout << "!!!" << endl;*/

	//display(3);
	//Array arr = 3;

	//Array array10{ 10 };

	Point p1{1,2};
	Point p2{2,1};

	Point p_res = p1 + p2;
	Point p_res2 = p1 + 10;
	//Point p_res2 = Point::add(p1, p2);

	p_res++;

	std::cout << p_res << p1 << p2 << std::endl;

	Point ppp;
	std::cin >> ppp;
	std::cout << ppp;

	_getch();

	return 0;
}