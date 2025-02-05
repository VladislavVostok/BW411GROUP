#include <iostream>

using namespace std;


//void interchange_ptr(int* u, int* v) {
//	int temp = *u;
//	*u = *v;
//	*v = temp;
//}
//
//int interchange_ref(int& u, int& v) {
//	int temp = u;
//	u = v;
//	v = temp;
//}

int main() {
	//int x = 5, y = 10;
	//cout << "Change with pointers:\n";
	//cout << "x = " << x << " y = " << y << "\n";
	//
	//// используем указатели
	//interchange_ptr(&x, &y);

	//cout << "x = " << x << " y = " << y << "\n";
	//cout << "-------------------------- " << "\n";
	//cout << "Change with references:\n";
	//cout << "x = " << x << " y = " << y << "\n";
	//// используем ссылки
	//interchange_ref(x, y);
	//cout << "x = " << x << " y = " << y << "\n";
	int size;
	int* dar;

	int *r = new int;

	cin >> size;

	dar = new int[size];

	for (int i = 0; i < size; i++) {
		dar[i] = rand() % 100;
		cout << dar[i] << "\t";
	}

	cout << "\n\n";

	delete r;
	delete [] dar;
	return 0;
}
