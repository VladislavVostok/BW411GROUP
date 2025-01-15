#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{

    setlocale(LC_ALL, "");
    // Теория Двумерные массивы
    ////srand(time(NULL));

    //const int row = 10;
    //const int col = 5;
    //int array[row][col] = {  };

    //for (int i = 0; i < row; i++) {
    //    for (int j = 0; j < col; j++) {
    //        array[i][j] = rand() % 100 + 1;
    //        cout << array[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    //int array1[2][2] = { {1,2}, {7,8} };
    //int array2[3][3] = { {7,8},{10,3,5} };

    //int myNum = array[4][4];


    //int i;
    //cout << "Hello World!\n";

    // Задание 1. 
    // В двумерном массиве целых числе посчитать:
    // ■ Сумму  всех  элементов  массива;
    // ■ Среднее арифметическое  всех  элементов  массива;
    // ■ Минимальный  элемент;
    // ■ Максимальный  элемент.


    //const int row = 10;
    //const int col = 5;

    //int array[row][col];

    //int sz = sizeof(array) / sizeof(array[0][0]);
    //int sum_arr = 0;
    //int count_arr = 0;

    //double average;

    //int max = numeric_limits<int>::min(); 
    //int min = numeric_limits<int>::max();

    //for (int i = 0; i < row; i++) {
    //    for (int j = 0; j < col; j++) {
    //        array[i][j] = rand() % 100 + 1;

    //        if (array[i][j] > max) {
    //            max = array[i][j];
    //        }

    //        if (array[i][j] < min) {
    //            max = array[i][j];
    //        }

    //        sum_arr += array[i][j];
    //        count_arr++;
    //        cout << array[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    //average = static_cast<double>(sum_arr) / sz;

    //cout << "Сумма всех элементов массива: " << sum_arr << endl;
    //cout << "Среднее арифметическое всех элементов массива: " << average << endl;
    //cout << "Максимальный элемент: " << max << endl;
    //cout << "Минимальный элемент: " << min << endl;


    // Задание 2
    // В двумерном массиве целых чисел посчитать сумму элементов: 
    // в каждой строке; в каждом столбце; одновременно по всем 
    // строкам и всем столбцам. Оформить следующим  образом:
    // 3    5   6   7   |  21 
    // 12   1   1   1   |  15   
    // 0    7   12  1   |  20
    // ----------------------
    // 15   3   19  9   |  56
    //

    const int row = 3;
    const int col = 4;

    int array[row][col];
    int rowSums[row] = { 0 };
    int colSums[col] = { 0 };
    int totalSum = 0;

    // Расчёт суммы
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = rand() % 100 + 1;
            
            rowSums[i] += array[i][j];
            colSums[j] += array[i][j];
            totalSum += array[i][j];
        }
        cout << endl;
    }

    // Вывод массива
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(3) << array[i][j] << " ";
        }
        cout << " | " << rowSums[i] << endl;
    }

    cout << string(20, '-') << endl;

    for (int i = 0; i < col; i++) {
        cout << setw(3) << colSums[i] << " ";
    }

    cout << " | " << totalSum << endl;
    
}
