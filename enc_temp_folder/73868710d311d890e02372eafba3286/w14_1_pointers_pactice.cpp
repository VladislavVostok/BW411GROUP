// ���� ��� �������: �[M] � B[N] (M � N �������� � ����������). 
// ���������� ������� ������ ������ ���������� ���������� �������, 
// � ������� ����� ������� �������� ����� ��������.


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


// �������� �������, ������� �������� ��������� �� ������ 
// � ��� ������, � ���������� ����� � ������������ ��� 
// ��������� � ���� ����������-����������.
void calcSumProd(int* pArr, int& size, int* sum, int* prod) {
	for (int i = 0; i < size; i++) {
		//*sum += *(pArr + i);
		*sum += pArr[i];
		*prod *= pArr[i];
	}
}



int main() {

	int N, M;
	cout << "������� ���������� ��������� ������� A[N]";
	cin >> N;

	cout << "������� ���������� ��������� ������� B[M]";
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

	return 0;
}
