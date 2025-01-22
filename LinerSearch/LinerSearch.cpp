

#include <iostream>



int LinerSearch(int arr[], int size, int value, int pos);
template <class T> void bubbleSort(T a[], long size);

int main()
{

	int arr[]{ 654, 2,34,12,3,4325,4,5756,8,3233,412,64,4,32 };
	int size = sizeof(arr) / sizeof(arr[0]);


	bubbleSort(arr, size);

	int ind = LinerSearch(arr, size, 4, 2);


    std::cout << "Hello World!\n";
}



template <class T> void bubbleSort(T a[], long size) {
	long i, j;
	T x;
	for (i = 0; i < size; i++) { // i - номер прохода 
		for (j = size - 1; j > i; j--) { // внутренний цикл
			// прохода
			if (a[j - 1] > a[j]) {
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}
		}
	}
}

int LinerSearch(int arr[], int n, int value, int pos) {
	
	for (int i = 0; i < n; i++)
	{

		if (arr[i] == value) {


			if (pos == 1)
				return i;
			
			pos--;
		}
	}

	return -1;
}
