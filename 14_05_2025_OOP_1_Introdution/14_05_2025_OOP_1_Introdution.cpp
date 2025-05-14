//// Вычислить среднюю оценку студента
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
//// максимальная длина имени
const int maxNameLength = 20;
// число оценок
const int markCount = 3;
// определение структуры данных
// ------------------------------------
// Студент
struct StudentStruct
{
	// ФИО
	char name[maxNameLength];

	// оценки
	int marks[markCount];
};
// ------------------------------------
// конец определения структуры данных
// функции обработки структуры данных
// ------------------------------------
// заполнение данных о студенте

void initStudent(StudentStruct& st, const char* name, const int marks[])
{
	strcpy_s(st.name, maxNameLength, name);
	for (int i = 0; i < markCount; i++)
	{
		st.marks[i] = marks[i];
	}
}

// вычисление средней оценки
double averMark(StudentStruct st)
{
	double sum = 0;
	for (int i = 0; i < markCount; i++)
	{
		sum += st.marks[i];
	}
	return sum / markCount;
}
// вывод данных о студенте
void printStudent(StudentStruct st)
{
	cout << st.name << endl;
	cout << "Оценки: ";
	for (int i = 0; i < markCount; i++)
	{
		cout << setw(4) << st.marks[i];
	}
	cout << endl;
}
//// ------------------------------------
//// конец списка функций обработки структуры данных
//int main()
//{
//	setlocale(LC_ALL, "");
//	cout << "Успеваемость студента." << endl << endl;
//
//	Student student;
//	const char* studentName{ "Петров А.О." };
//	int studentMarks[]{ 4,4,3 };
//	
//	initStudent(student,studentName, studentMarks);
//	printStudent(student);
//
//	cout << "Средняя оценка: "
//		<< fixed << setprecision(2)
//		<< averMark(student) << endl;
//
//	_getch();
//	return 0;
//}


using namespace std;

// определение класса
// ------------------------------------
// Студент

class Human {

	private:
	char name[maxNameLength];
};


class Student
{
	// ФИО
private:
	char name[maxNameLength];
	// оценки
	

	int marks[markCount];
public:
	// конструктор: создание объекта Студент
	Student(const char* name, const int* marks)
	{
		strcpy_s(Student::name,
			maxNameLength, name);
		for (int i = 0; i < markCount; i++)
		{
			Student::marks[i] = marks[i];
		}
	}

	void setterName(const char* name) {
		strcpy_s(Student::name,
			maxNameLength, name);
	}

	// вычисление средней оценки
	double getAver()
	{
		double sum = 0;
		for (int i = 0; i < markCount; i++)
		{
			sum += marks[i];
		}
		return sum / markCount;
	}

	// вывод данных о студенте
	void print()
	{
		cout << name << endl;
		cout << "Оценки: ";
		for (int i = 0; i < markCount; i++)
		{
			cout << setw(4) << marks[i];
		}
		cout << endl;
	}

	// вывод средней оценки
	void printAver()
	{
		cout << "Средняя оценка: "
			<< fixed << setprecision(2)
			<< getAver() << endl;
	}
};
// ------------------------------------
// конец определения класса
int main()
{
	setlocale(LC_ALL, "");
	cout << "Успеваемость студента."
		<< endl << endl;
	// вызов конструктора класса:
	// создание объекта

	// 1Вариант. Короткая запись инициализация и определение экземпляр класса в статическая памяти 
	//Student student{ "Петров А.О.", new int[3] { 4,4,3 } };

	// 2 вариант. Полная запись. Стекова память.
	Student student1 = Student("Петров А.О.", new int[3] { 4, 4, 3 });

	// вызовы методов класса:
	// работа с данными объекта . модификатор доступа к членам класса, 
	// есль объект находиться в статическая памяти.
	student1.print();
	student1.printAver();
	//student1.marks;		// Если поле класса имеет модификатор доступа public, если private
						// тогда он не будет доступен через модификатор доступа



	// Динамическая память
	Student *student = new Student("Петров А.О.", new int[3] { 4, 4, 3 });

	// вызовы методов класса:
	// работа с данными объекта -> модификатор доступа к членам класса, 
	// есть объект находиться в динамической памяти.
	student->print();
	student->printAver();

	auto st = Student("Петров А.О.", new int[3] { 4, 4, 3 });

	StudentStruct ststruct;
	initStudent(ststruct, "Петров А.О.", new int[3] { 4, 4, 3 });



	st.setterName("Ибрагимов А.О.");

	cout << "Класс: " << sizeof st;
	cout << "Структура: " << sizeof ststruct;



	_getch();
	return 0;
}