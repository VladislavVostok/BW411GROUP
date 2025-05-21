#include "Animal.h"

#include <string>
#include <iostream>

using namespace std;

// ������ ������ ����������� ������������
Animal::Animal(const string& name, int age) : name(name), age(age) {}

// ������ ������ ����������� ������������
//Animal(const string& name, int age) {
//    this->age = age;
//    this->name = name;
//}

// ����������� ������ (�����������)

Animal::~Animal() {
    cout << "�������� c ������ " << name << " �����������" << endl;
}

// �� ����������� ������
string Animal::getName() const { return name; }

int Animal::getAge() const { return age; }

void Animal::displayInfo() const {
    cout << "���: " << name << ", �������: " << age << " ���" << endl;
}