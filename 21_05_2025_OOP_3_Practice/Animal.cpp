#include "Animal.h"

#include <string>
#include <iostream>

using namespace std;

// Первый способ организации конструктора
Animal::Animal(const string& name, int age) : name(name), age(age) {}

// Второй способ организации конструктора
//Animal(const string& name, int age) {
//    this->age = age;
//    this->name = name;
//}

// Виртуальные методы (полиморфизм)

Animal::~Animal() {
    cout << "Животное c именем " << name << " уничтоженно" << endl;
}

// не виртуальные методы
string Animal::getName() const { return name; }

int Animal::getAge() const { return age; }

void Animal::displayInfo() const {
    cout << "Имя: " << name << ", Возраст: " << age << " лет" << endl;
}