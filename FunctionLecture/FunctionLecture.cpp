// FunctionLecture.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void ShowArray(int arr[], int size);
void InitArray(int arr[], int size);
int summa(int array[][5], int size_row, int size_col);
void InitMatrix(int matr[][3], int rows, int cols);
void ShowMatrix(int matr[][3], int rows, int cols);

int A = 10;

int main()
{

    int A = 66;
    cout << ::A << endl;



    srand(time(nullptr));

    

    const int aSize = 10;
    int iArr[aSize];

    InitArray(iArr, aSize);
    cout << A << endl;

    ShowArray(iArr, aSize);
    cout << A << endl;

    const int mRows = 3;
    const int mCols = 3;
    int iMatr[mRows][mCols];
    InitMatrix(iMatr, mRows, mCols);


    ShowMatrix(iMatr, mRows, mCols);


    //int temp = 4;

    //if(temp == 4) {
    //    int b = 5;
    //    cout << b;
    //}



    return 0;
}


// отображение массива
void ShowArray(int arr[], int size) {
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


/* инициализируем массив внутри функции случайными
числами в отличии от обычных переменных изменения
элементов массива, происходящие внутри функции
при выходе из функции сохраняются
*/
void InitArray(int arr[], int size) {
    

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}



int summa(int array[][5], int size_row, int size_col) {
    int res = 0;
    for (int i = 0; i < size_row; i++)
        for (int j = 0; j < size_col; j++)
            res += array[i][j];
    return res;
}

// отображение матрицы
void ShowMatrix(int matr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void InitMatrix(int matr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matr[i][j] = rand() % 10;
        }
    }
    cout << endl;
}




