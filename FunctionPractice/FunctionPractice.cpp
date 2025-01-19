#include <iostream>
#define CONSTANNTA 54.34235;

#pragma region MyRegion

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

#pragma endregion
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
    // Задание 4. Написать функцию, которая возвращает куб числа.


    // Задание 5. Написать функцию для нахождения наибольшего из двух чисел.
    int getMax(int a, int b) {
        if (a > b) 
            return a;

        return b;
    }


    float getMax(float a, float b) {
        if (a > b)
            return a;

        return b;
    }


    double getMax(double a, double b) {
        if (a > b)
            return a;

        return b;
    }

    double getMax(double a, double b, double c) {
        if (a > b && a > c)
            return a;
        else if (b > c && b > a)
            return b;

        return c;
    }    
    
    double getMax(double a=1.0, double b=1.0, double c=1.0, double d = 1.0) {
        if (a > b && a > c)
            return a;
        else if (b > c && b > a)
            return b;

        return c;
    }

    // Задание 6. Написать функцию, которая возвращает истину, 
    // если передаваемое значение положительное и ложь, если отрицательное.
    
    bool isPositive(int a = -15) {
        if (a >= 0)
            return true;

        return false;
    }


int main()
{
    setlocale(LC_ALL, "");

    std::cout << CONSTANNTA;

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


    // Задание 5.
    std::cout << getMax(1, 1000) << std::endl;
    std::cout << getMax(3.4f, 6.2f) << std::endl;
    std::cout << getMax(54.2, 234.7) << std::endl;
    std::cout << getMax(54.2, 234.7, 345.1, 34.2) << std::endl;



    // Задание 6.

    int x = -40;
    if (isPositive()) {
        std::cout << "Положительное!";
    }
    else {
        std::cout << "Отрицательное!";
    }

    std::cout << isPositive(-40) << std::endl;

}
