#include <iostream>
#include "Date.h"
#include "String.h"

using namespace std;

int main()
{
	//Date d1(15, 6, 2023);
	//Date d2(20, 5, 2023);

	//cout << (d1 - d2) << endl;

	//d1 += 100;

	//Date d3 = d1 + 70;

	//d1.print();
	//d3.print();

	String s1("sdqcg");
	String s2("rgfas34");
	String intersection = s1 * s2;
	intersection.print();
	
	return 0;
}

