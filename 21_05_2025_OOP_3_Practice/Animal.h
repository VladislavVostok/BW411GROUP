#pragma once
class Animal
{
protected:
    // ���������� ���� ����� (������������)
    string name;
    int age;

public:
    Animal(const string&, int);
    virtual ~Animal();
    virtual void makeSound() const = 0;
    string getName() const;
    int getAge() const;
    void displayInfo() const;
};

