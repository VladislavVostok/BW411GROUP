#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void printArr(const vector<int>& numbers) {
    cout << "[ ";
    for (int i : numbers)
    {
        cout << i << " ";
    }
    cout << " ]";
}


// Функция для выполнения пузырьковой сортировки
void bubbleSort( int numbers[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Оптимизация: флаг для проверки, были ли перестановки
        bool swapped = false;
        int temp = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
                swapped = true;
            }
        }
        // Если не было перестановок, массив уже отсортирован
        if (!swapped) break;
    }
}


// Функция для быстрой сортировки
vector<int> quickSort(const vector<int>& numbers) {


    if (numbers.size() < 2) {
        return numbers; // Базовый случай: если массив состоит из 0 или 1 элемента, он уже отсортирован
    }

    // Выбираем опорный элемент (pivot)
    int pivot = numbers[numbers.size() / 2]; // Опорный элемент выбирается как элемент из середины массива
    vector<int> left, right; // Два массива для элементов, меньших и больших опорного

    // Разделение элементов на меньше и больше опорного
    for (int num : numbers) { // Проходим по всем элементам массива
        if (num < pivot) {
            left.push_back(num); // Добавляем элементы, меньшие опорного, в массив left
        }
        else if (num > pivot) {
            right.push_back(num); // Добавляем элементы, большие опорного, в массив right
        }
        // Равные pivot элементы игнорируются, так как они автоматически включатся позже
    }

    // Рекурсивная сортировка левой и правой частей, добавление опорного элемента
    vector<int> sortedLeft = quickSort(left); // Рекурсивно сортируем левую часть
    vector<int> sortedRight = quickSort(right); // Рекурсивно сортируем правую часть

    // Слияние отсортированных частей
    sortedLeft.push_back(pivot); // Добавляем опорный элемент в конец отсортированной левой части
    sortedLeft.insert(sortedLeft.end(), sortedRight.begin(), sortedRight.end()); // Добавляем отсортированную правую часть


    return sortedLeft; // Возвращаем результат: объединенный отсортированный массив
}



// Функция для слияния двух отсортированных частей
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result; // Вектор для хранения результата слияния
    int i = 0, j = 0;   // Индексы для итерации по массивам left и right

    // Сливаем два массива, сравнивая их элементы
    while (i < left.size() && j < right.size()) { // Пока есть элементы в обоих массивах
        if (left[i] < right[j]) { // Если текущий элемент из left меньше
            result.push_back(left[i]); // Добавляем его в результат
            i++; // Переходим к следующему элементу в left
        }
        else { // Если текущий элемент из right меньше или равен
            result.push_back(right[j]); // Добавляем его в результат
            j++; // Переходим к следующему элементу в right
        }
    }

    // Добавляем оставшиеся элементы из left, если они остались
    while (i < left.size()) {
        result.push_back(left[i]); // Добавляем элемент из left в результат
        i++; // Переходим к следующему элементу
    }

    // Добавляем оставшиеся элементы из right, если они остались
    while (j < right.size()) {
        result.push_back(right[j]); // Добавляем элемент из right в результат
        j++; // Переходим к следующему элементу
    }

    return result; // Возвращаем результат слияния
}

// Функция сортировки слиянием
vector<int> mergeSort(const vector<int>& numbers) {
    if (numbers.size() < 2) { // Базовый случай: если массив состоит из 0 или 1 элемента
        return numbers;       // Он уже отсортирован, возвращаем его
    }

    int mid = numbers.size() / 2; // Находим середину массива

    // Разделяем массив на левую и правую части
    vector<int> left(numbers.begin(), numbers.begin() + mid); // Создаем вектор из первой половины массива
    vector<int> right(numbers.begin() + mid, numbers.end());  // Создаем вектор из второй половины массива


    // Рекурсивная сортировка левой части
    left = mergeSort(left);

    // Рекурсивная сортировка правой части
    right = mergeSort(right);

    // Слияние отсортированных частей
    return merge(left, right); // Возвращаем объединенный отсортированный массив
}


int main() {

    setlocale(LC_ALL, "");
    //srand(time(NULL));

    const int MAX_ELEM_ARR = 10000;

    vector<int> numbers;
    int num[MAX_ELEM_ARR];

    for (int i = 0; i < MAX_ELEM_ARR; i++) {
        numbers.push_back(rand() % 1000 + 1);
        num[i] = rand() % 1000 + 1;
    }

    auto start_time = std::chrono::steady_clock::now();
    // Сортировка слиянием
    vector<int> sortedNumbers1 = mergeSort(numbers);

    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << " Сортировка слиянием: " << elapsed_ns.count() << " ns\n";

    start_time = std::chrono::steady_clock::now();
    // Быстрая сортировака
    vector<int> sortedNumbers2 = quickSort(numbers);

    end_time = std::chrono::steady_clock::now();
    elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Быстрая сортировка: " << elapsed_ns.count() << " ns\n";

    start_time = std::chrono::steady_clock::now();
    // Пузырьковая сортировака
    bubbleSort(num, MAX_ELEM_ARR);

    end_time = std::chrono::steady_clock::now();
    elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Пузырьковая сортировака: " << elapsed_ns.count() << " ns\n";

  

    return 0;
}