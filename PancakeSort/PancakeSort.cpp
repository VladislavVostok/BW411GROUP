/*
Есть стопка оладий различного радиуса. Единственная
операция, проводимая с ними — между любыми двумя суем
лопатку и меняем порядок оладий над лопаткой на обратный.
Необходимо за минимальное количество операций таких
отсортировать снизу вверх по убыванию радиуса.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void    printStack(int pancake[], int n);
void    generateRandomSeq(int pancake[], int n);
void    pancakeSort(int pancake[], int n);
int     findMaxIndex(int pancake[], int currSize);
void    flip(int arr[], int index);


int main()
{

    setlocale(LC_ALL, "");
    srand(time(nullptr));

    const int n = 10;
    int pancake[n];

    generateRandomSeq(pancake, n);
    
    cout << "Оригинальный массив: ";
    printStack(pancake, n);

    cout << endl;

    pancakeSort(pancake, n);

    cout << "Отсортированный массив: ";
    printStack(pancake, n);

    return 0;
}


int findMaxIndex(int pancake[], int currSize) {
    
    int maxIndex = 0;

    for ( int i = 1; i < currSize; i++)
    {
        if (pancake[i] > pancake[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void flip(int arr[], int index) {
    int start = 0;
    while (start < index) {
        swap(arr[start], arr[index]);
        start++;
        index--;
    }
}

void pancakeSort(int pancake[], int n) {
    for (int currSize = n; currSize > 1; --currSize) {
        int maxIndex = findMaxIndex(pancake, currSize);

        if (maxIndex == currSize - 1)
        {
            continue;
        }

        if (maxIndex > 0) {
            flip(pancake, maxIndex);
            //cout << "Нач. индекс: " << maxIndex << ": ";

            printStack(pancake, n);
        }

        cout << endl;

        flip(pancake, currSize - 1);
        cout << "Нач. индекс: " << maxIndex << ": ";

        printStack(pancake, n);
        cout << endl;


    }
}

void printStack(int pancake[], int n) {
    for (int i = 0; i < n; i++) {
        cout << pancake[i] << " ";
    }
}

void generateRandomSeq(int pancake[], int n) {
    for (int i = 0; i < n; i++) {
        pancake[i] = rand() % 100 + 1;
    }
}

