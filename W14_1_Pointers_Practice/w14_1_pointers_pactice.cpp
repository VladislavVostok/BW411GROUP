// Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
// Необходимо создать третий массив минимально возможного размера, 
// в котором нужно собрать элементы обоих массивов.


#include <iostream>

using namespace std;




void randomPush(int* A, int &N) {
	for (int i = 0; i < N; i++) {
		*(A + i) = rand() % 10 + 1;
	}
}


void printArr(int* A, int& N) {
	for (int i = 0; i < N; i++) {
		cout << *(A + i) << " ";
	}
	cout << endl;

}

int* mergeArr(int* A, int& N, int* B, int& M) {

	int* C = new int[N + M];

	for (int i = 0; i < N; i++) {
		*(C + i) = *(A + i);
	}

	for (int i = N; i < N+M; i++) {
		*(C + i) = *(B + (i - N));
	}
	return C;
}





// Написать функцию, которая получает указатель на массив 
// и его размер, и возвращает сумму и произведение его 
// элементов в двух параметрах-указателях.
void calcSumProd(int* pArr, int& size, int* sum, int* prod) {
	for (int i = 0; i < size; i++) {
		//*sum += *(pArr + i);
		*sum += pArr[i];
		*prod *= pArr[i];
	}
}


//Задание 2. Написать функцию, которая получает указатель
//на массив и его размер, и возвращает количество отрица -
//тельных, положительных и нулевых элементов массива.

void count_negative_posit_zero_item(int* pArr, int& size, int* count_neg, int* count_pos, int* count_zero) {

	for (int i = 0; i < size; i++) {
		if (*(pArr + i) > 0)
			(*count_pos)++;
		else if (*(pArr + i) < 0)
			*count_neg += 1;
		else
			*count_zero += 1;
	}
}


int main() {

	setlocale(LC_ALL, "");
	int N, M;
	cout << "Введите количество элементов массива A[N]";
	cin >> N;

	cout << "Введите количество элементов массива B[M]";
	cin >> M;

	int* A = new int[N];
	int* B = new int[M];

	randomPush(A, N);
	randomPush(B, M);
	printArr(A, N);
	printArr(B, M);

	int* C = mergeArr(A, N, B, M);

	int Size = N + M;
	printArr(C, Size);


	delete[] A;
	delete[] B;
	delete[] C;

	int size = 10;
	int* Z = new int[size];
	int s = 0;
	int p = 1;
	int* sum = &s;
    int * prod = &p;


	*sum = 0;
	*prod = 1;

	randomPush(Z, size);
	printArr(Z, size);

	calcSumProd(Z, size, sum, prod);

	cout << *sum << " " << *prod << endl;

	delete[] Z;

	int size1 = 14;

	int* count_neg = new int(0);
	int* count_pos = new int(0);;
	int* count_zero = new int(0);;
	int* pArr = new int[size1];
	randomPush(pArr, size1);
	printArr(pArr, size1);
	count_negative_posit_zero_item(pArr, size1, count_neg, count_pos, count_zero);

	delete count_neg;
	delete count_pos;
	delete count_zero;
	delete[] pArr;

	return 0;
}
