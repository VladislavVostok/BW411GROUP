#include "Dog.h"

#include <iostream>

using namespace std;

Dog::Dog(const string& name, int age, const string& breed) : Animal(name, age), breed(breed) {}

// Переопределение методов родителя (Полиморфизм)
void Dog::makeSound() const override {
    
    cout << name << " сказал: Гав! Гав" << endl;
}

void  Dog::fetch() {
    cout << name << " перехватил мяч!" << endl;
}

void Dog::displayInfo() {
    Animal::displayInfo();
    cout << ", Остальные данные: " << breed << " (Собака)" << endl;
}

Dog::~Dog() override {
    cout << "Собака была уничтожена " << name << endl;
}