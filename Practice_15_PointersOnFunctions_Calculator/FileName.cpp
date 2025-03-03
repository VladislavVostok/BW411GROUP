#include <iostream>
#include <string>

using namespace std;

double add(double a, double b);
double substract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

double (*operations[])(double, double) = { add, substract, multiply, divide };

#include <iostream>



int main() {
	setlocale(LC_ALL, "");

	//char operators[] = { '+', '-', '*', '/' };
	double a, b;
	char op;

	cout << "¬ведите по формуле ( 3 + 4):" << endl;
	cin >> a >> op >> b;

	int index = (string("+-*/").find(op));

	if (index != string::npos) {
		cout << operations[index](a, b) << endl;
	}

	_mm_pause();

	return 0;
}

double add(double a, double b) {
	return a + b;
}

double substract(double a, double b) {
	return a - b;
}

double multiply(double a, double b) {
	return a * b;
}

double divide(double a, double b) {
	return (b != 0) ? (a / b) : 0;
}



