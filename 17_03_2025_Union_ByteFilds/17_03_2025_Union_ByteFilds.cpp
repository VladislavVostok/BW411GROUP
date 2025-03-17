//#include <iostream>
//using namespace std;
//int main()
//{
//
//	cout << sizeof(long long);
//
//	union
//	{
//		short int component1;  // 2
//		int component2;		   // 4
//		long long component3;   // 4
//	} myUnion; // объект объединения
//
//	cout << sizeof myUnion;
//
//	myUnion.component1 = 22;
//	cout << myUnion.component1 << endl;
//	
//	cout << sizeof myUnion;
//
//	myUnion.component3 = 22672222222;
//	
//	cout << myUnion.component3 << endl;
//
//	cout << sizeof myUnion;
//	
//	cout << myUnion.component1 << endl; // снова обращаемся к component1
//	
//	cout << sizeof myUnion;
//	
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//union Employee {
//	int id;
//	double salary;
//};
//
//
//struct statusField
//{
//	unsigned int JS : 1;
//	unsigned int PHP : 1;
//	unsigned int Python : 1;
//} state;
//
//struct fieldbite
//{
//	unsigned short field1 : 2;
//	unsigned short field2 : 2;
//	unsigned short field3 : 4;
//} field;
//
//int main()
//{
//	cout << sizeof fieldbite << endl;
//
//	Employee myEmployee;
//
//	myEmployee.id = 15;
//
//	cout << "The first value (id) at ";
//
//	cout << "the allocated memory: ";
//
//	cout << myEmployee.id << "\n";
//
//	myEmployee.salary = 100.35;
//	cout << "The next value (salary) stored ";
//	cout << "after removing the previous value: ";
//
//	cout << myEmployee.salary << "\n";
//	return 0;
//
//}


#include <iostream>
using namespace std;
int main()
{
	struct DateTime {
		unsigned short DayNum : 5;
		unsigned short MonthNum : 4;
		unsigned short YearNum : 7;
		unsigned short HourNum : 5;
		unsigned short MinuteNum : 6;
		unsigned short SecondNum : 6;
	};
	DateTime d;

	cout << sizeof d << endl;

	int i;
	cout << "Input the day number (from 1 to 31):" << '\t';
	cin >> i;

	d.DayNum = i;
	cout << "Input the month number (from 1 to 12):"
		<< '\t';
	cin >> i;
	d.MonthNum = i;
	cout << "Input Year (from 00 to 99) :" << '\t';
	cin >> i;
	d.YearNum = i;
	cout << endl << "Input Hours (from 0 to 24):"
		<< '\t';
	cin >> i;
	d.HourNum = i;
	cout << "Input Minutes (from 0 to 60):" << '\t';
	cin >> i;
	d.MinuteNum = i;
	cout << "Input Seconds (0-60):" << '\t';
	cin >> i;
	d.SecondNum = i;
	cout << endl << "Date is: " << d.DayNum << "."
		<< d.MonthNum << ".20" << d.YearNum << " ";
	cout << d.HourNum << ":" << d.MinuteNum << ":"
		<< d.SecondNum << endl;
	cout << sizeof(d) << endl;
	return 0;
}