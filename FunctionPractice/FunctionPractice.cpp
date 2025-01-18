#include <iostream>

// Задание 1. Написать функцию, выводящую на экран 
// прямоугольник с высотой N и шириной K.
void drawRectangle(char sign, int height, int weight) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < weight; j++) {
            std::cout << sign;
        }
        std::cout << std::endl;
    }
}

// Задание 2. Написать функцию, вычисляющую факториал переданного ей числа.

unsigned long long calcFactorial(int n) {
    if (n == 0) return 1;

    int res = 1;

    for (int i = 1; i <= n; i++)
        res *= i;

    return res;
}

// Задание 3. Написать функцию, которая проверяет, является ли переданное ей число простым ? Число называется 
// простым, если оно делится без остатка только на себя и на единицу.


bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return false;
    }

    return true;

}


int main()
{
    setlocale(LC_ALL, "");
    // Задание 1.
    int N;
    int K;
    std::cout << "Введите высоту прямоугольника\n";
    std::cin >> N;
    std::cout << "Введите ширину прямоугольника\n";
    std::cin >> K;

    drawRectangle('*', N, K);

    // Задание 2.

    int n_factorial;
    std::cout << "Введите факторил\n";
    std::cin >> n_factorial;

    std::cout << calcFactorial(n_factorial) << std::endl;

    // Задание 3.

    if (is_prime(2) == true) {
        std::cout << "Все четко";
    }

}
