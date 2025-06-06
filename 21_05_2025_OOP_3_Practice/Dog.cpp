#include "Dog.h"

#include <iostream>

using namespace std;

Dog::Dog(const string& name, int age, const string& breed) : Animal(name, age), breed(breed) {}

// ��������������� ������� �������� (�����������)
void Dog::makeSound() const {
    
    cout << name << " ������: ���! ���" << endl;
}

void  Dog::fetch() {
    cout << name << " ���������� ���!" << endl;
}

void Dog::displayInfo() {
    Animal::displayInfo();
    cout << ", ��������� ������: " << breed << " (������)" << endl;
}

Dog::~Dog() {
    cout << "������ ���� ���������� " << name << endl;
}