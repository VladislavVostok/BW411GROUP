#include <iostream>

int main()
{
    int** A = new int* [5];

    for (int i = 0; i < 5; i++) {

        A[i] = new int[5];

        for (int j = 0; i < 5; j++) {
            A[i][j] = 6;
        }

    }

    for (int i = 0; i < 5; i++)
    {
        delete[]A[i];
    }
    delete[]A;


}
