

#include <iostream>
#include <cmath>
#include <numeric>

//Задание 1. Создать структуру, описывающую прямоугольник.
// Написать функции для работы с этой структурой : 
// * перемещение прямоугольника, 
// * изменение размера прямоугольника, 
// * печать прямоугольника, 
// * вычисления периметра,
// * вычисление площади. 

using namespace std;

struct Point {
    int x;
    int y;
    Point(int x, int y) :
        x(x),
        y(y) {}
};

struct Rectangle {
    Point point;
    int width, height;

    Rectangle(Point& point, int width, int height) : 
        point(point),
        width(width), 
        height(height) {}

    void move(int dx, int dy) {
        point.x += dx;
        point.y += dy;
    }

    void resize(int new_width, int new_height) {
        width = new_width;
        height = new_height;
    }

    int perimetr() {
        return width * 2 + height * 2;
    }

    int square() {
        return width * height;
    }

    void info() {
        cout << "Координаты (" << point.x << ", " << point.y << ")" << endl
             << " Ширина: " << width << endl
             << "Высота: " << height << endl
             << "Периметр: " << perimetr() << endl
             << "Площадь: " << square() << endl;
    }
};

//Задание 2. Создайте структуру, описывающую точку
//в двумерной системе координат (x, y).
// С помощью этой структуры задайте две точки.
// Напишите функцию, которая вычисляет расстояние 
// между этими двумя точками ?

double distance(const Point& p1, const Point& p2) {
    return sqrt(pow((double)p2.x - p1.x, 2.) + pow((double)p2.y - p1.y, 2.));
}

/*
Задание 3. Создайте структуру, описывающую простую
дробь. 
Реализуйте арифметические операции с дробями:
* сумму, 
* разность, 
* умножение, 
* деление.
- Учесть возможность сокращения дробей и перевод
из неправильной дроби в простую.

*/

struct Fraction {
    int numerator, denominator; // числитель и знаменатель.

    void reduce() {
        int _gcd = gcd(numerator, denominator);
        numerator /= _gcd;
        denominator /= _gcd;
    }

    Fraction operator+(const Fraction& her) {
        Fraction result = { this->numerator * her.denominator + denominator * her.numerator, denominator * her.denominator };
        result.reduce();
        return result;
    }

    Fraction operator-(const Fraction& other) {
        Fraction result = { numerator * other.denominator - denominator * other.numerator, denominator* other.denominator };
        result.reduce();
        return result;
    }

    Fraction operator*(const Fraction& other) {
        Fraction result = { numerator * other.numerator,  denominator * other.denominator };
        result.reduce();
        return result;
    }

    Fraction operator/(const Fraction& other) {
        Fraction result = { numerator * other.denominator,  denominator * other.numerator };
        result.reduce();
        return result;
    }

    void info() {
        cout << numerator << "/" << denominator;
    }
};

struct test {
    int a;
    char b;
    char b1;
    double c;
};

int main()
{
    setlocale(LC_ALL, "");
    Point p1(5, 3);
    Rectangle r1(p1, 30, 10);

    Point p2(7, 2);
    Rectangle r2(p2, 40, 60);

    // задание 2.
    cout << "Дистанция меджу точками: " << distance(p1, p2) << endl;

    r1.info();
    r2.info();
    r1.move(5, 5);
    r2.move(5, 5);
    r1.info();
    r2.info();
    r1.resize(10, 20);
    r2.resize(10, 20);
    r1.info();
    r2.info();

    // задание 3.

    Fraction f1{ 2,3 }, f2{ 3,4 };

    Fraction sum = f1 + f2;
    Fraction diff = f1 - f2;
    Fraction prod = f1 * f2;
    Fraction del = f1 / f2;

    cout << "Сумма: "; sum.info();
    cout << endl;
    cout << "Вычитание: "; diff.info();
    cout << endl;
    cout << "Умножение: "; prod.info();
    cout << endl;
    cout << "Деление: "; del.info();
    cout << endl;


    int a;
    char b;
    double c;
    int* p;
    cout << "sizeof(a)=" << sizeof(a) << "\n";
    cout << "sizeof(b)=" << sizeof(b) << "\n";
    cout << "sizeof(c)=" << sizeof(c) << "\n";
    cout << "sizeof(test)=" << sizeof(test) << "\n";
    cout << "sizeof(p)=" << sizeof(p) << "\n";
    cout << "sizeof(int)=" << sizeof(int) << "\n";
    cout << "sizeof(int *)=" << sizeof(int*) << "\n";

}
