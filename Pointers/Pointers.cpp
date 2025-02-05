//#include <stdio.h>
#include <stdlib.h>   // для подключения функции malloc
#include <iostream>

#define NULL 0;


void swap(int* x, int* y);

void sum(int* px, int* py, int* pr) {
    *pr = *px + *py;
}

double* calculator(int* a, int* b, char* op) {
    double res = 0.;
    double * pres = &res;
    switch (*op)
    {
    case '+':
        *pres = *a + *b;
        break;    
    case '-':
        *pres = *a - *b;
        break;    
    case '/':
        *pres = *a / *b;
        break;    
    case '*':
        *pres = *a * *b;
        break;
    default:
        std::cout << "Нет такой операции!" << std::endl;
        break;
    }
    return pres;
}

bool isGrandThen(int* a, int* b) {
    
    return (*a > *b) ? true : false;
}

void checkSign(int* num) {

    if (*num > 0) std::cout << "Положительное!" << std::endl;
    else if (*num < 0) std::cout << "Отрицательное!" << std::endl;
    else std::cout << "Это 0!" << std::endl;
}


int main(void)
{
    //int* ptr = (int*)malloc(sizeof(int[10])); // выделяем память для одного int
    //  new int[10]
    //*ptr = 24;      // помещаем значение в выделенную память

    int x = 5;
    int* px = &x;       // & - изъятие адреса по которому находиться переменная

    std::cout << *px << std::endl;  // * - перед переменной тип <type_data> * - разыменование


    //int y = *(px + 1);

    //int* py = px;


    int arr[10]{1,2,3,4,5,6,7,8,9,10};
    int* pFirstItem = &arr[0];

    for (int i = 0; i < 16; i++) {
        std::cout << *(pFirstItem + i) << ", ";
        *(pFirstItem + i) = i * 2;
        std::cout << arr[i] << ", ";
    }

    std::cout << *pFirstItem << std::endl;
    
    int y = 555;


    int a = 50;
    int b = 50;
    char op = '/';

    double* pRes = calculator(&a, &b, &op);


    //int y = 6;
    //int* py = &y;

    //int res;
    //int* pr = &res;

    //sum(px, py, pr);


    ////printf("%p \n", ptr);
    //free(pr);
    //free(py);
    //free(px);

    /*
Указатель не инициализирован
В нём случайное значение
*/
    int* ptr;
    // сейчас ptr нулевой указатель
    // так делать не рекомендуется
    ptr = 0;
    std::cout << ptr << std::endl;
    // Наследие языка С
    // так делать не рекомендуется
    ptr = NULL;
    std::cout << ptr << std::endl;
    // современный способ С++
    // создания нулевого указателя
    ptr = nullptr;
    std::cout << ptr << std::endl;
    if (ptr == nullptr) {
        std::cout << "\n\nNull pointer was found!" << std::endl;
    }

}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
