#include <iostream>
using namespace std;

// Функция для выполнения пузырьковой сортировки
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Оптимизация: флаг для проверки, были ли перестановки
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                //swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Если не было перестановок, массив уже отсортирован
        if (!swapped) break;
    }
}

// Функция для вывода массива
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]); // Вычисляем размер массива

    cout << "Исходный массив: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Отсортированный массив: ";
    printArray(arr, n);

    return 0;
}
