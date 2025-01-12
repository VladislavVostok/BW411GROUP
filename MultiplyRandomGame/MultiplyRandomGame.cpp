/*
Модуль 4. Циклы, использование отладчика(3 пары). 
Практическое занятие Неделя 7. 
Задания для самостоятельной работы 2.

Написать программу, которая проверяет пользователя на знание таблицы умножения. Программа выводит на экран два числа, пользователь должен ввести их
произведение. Разработать несколько уровней сложности
(отличаются сложностью и количеством вопросов). Вывести пользователю оценку его знаний.
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция для генерации случайного числа в заданном диапазоне
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Функция для выполнения теста на знание таблицы умножения
void multiplicationTest(int level) {
    int numQuestions; // Количество вопросов
    int maxNum;       // Максимальное число для умножения
    int correctAnswers = 0; // Количество правильных ответов

    // Настройки в зависимости от уровня сложности
    switch (level) {
    case 1:
        numQuestions = 5;  // 5 вопросов
        maxNum = 5;        // Числа от 1 до 5
        break;
    case 2:
        numQuestions = 7;  // 7 вопросов
        maxNum = 10;       // Числа от 1 до 10
        break;
    case 3:
        numQuestions = 10; // 10 вопросов
        maxNum = 15;       // Числа от 1 до 15
        break;
    default:
        cout << "Неверный уровень сложности. Выберите 1, 2 или 3." << endl;
        return;
    }

    // Задаем вопросы
    for (int i = 0; i < numQuestions; i++) {
        int num1 = generateRandomNumber(1, maxNum);
        int num2 = generateRandomNumber(1, maxNum);
        int correctAnswer = num1 * num2;

        cout << "Вопрос " << i + 1 << ": " << num1 << " * " << num2 << " = ";
        int userAnswer;
        cin >> userAnswer;

        if (userAnswer == correctAnswer) {
            cout << "Правильно!" << endl;
            correctAnswers++;
        }
        else {
            cout << "Неправильно. Правильный ответ: " << correctAnswer << endl;
        }
    }

    // Выводим итоговую оценку
    cout << "Ваши результаты: " << correctAnswers << " из " << numQuestions << " правильных ответов." << endl;
    double percentage = (double)correctAnswers / numQuestions * 100;

    if (percentage == 100) {
        cout << "Отлично!" << endl;
    }
    else if (percentage >= 75) {
        cout << "Хорошо!" << endl;
    }
    else if (percentage >= 50) {
        cout << "Удовлетворительно." << endl;
    }
    else {
        cout << "Неудовлетворительно. Попробуйте еще раз." << endl;
    }
}

int main() {
    // Инициализация генератора случайных чисел
    srand(time(0));

    int level;
    cout << "Выберите уровень сложности (1 - легкий, 2 - средний, 3 - сложный): ";
    cin >> level;

    multiplicationTest(level);

    return 0;
}
