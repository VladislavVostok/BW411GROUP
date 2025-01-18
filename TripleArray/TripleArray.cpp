#include <iostream>
#include <iomanip>

using namespace std;


/* Прототипы функций */
void print_arr(int arr[3][4][2], int x, int y, int z);
int sq(int a);



int main()
{
    const int x = 3;
    const int y = 4;
    const int z = 2;

    int array[x][y][z];

    int value = 1;

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                array[i][j][k] = value++;

    print_arr(array, x, y, z);

    sq(4);
    int res = sq(sq(sq(sq(sq(4)))));

    print_arr(array, x, y, z);
    
    return 0;
}


void print_arr(int arr[3][4][2], int x, int y, int z) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << setw(2) << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
}


int sq(int a) {

    if (a == 0) {
        return 0;
    }
    return a * a;
}
