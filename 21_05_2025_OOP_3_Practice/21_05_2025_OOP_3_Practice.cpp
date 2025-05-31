#include <iostream>
#include <string>
#include <vector>

#include "Animal.h"
#include "Dog.h"


using namespace std;

// Базовый абстрактный класс
class Animal {
protected:
    // Защищённые поля класа (Инкапсуляция)
    string _name;
    int _age;

public:

    // Первый способ организации конструктора
    //Animal(const string& name, int age) : _name(name), _age(age) {}


    // Второй способ организации конструктора
    Animal(const string& name, int age) {
        _age = age;
        _name = name;
    }


    Animal() : Animal("Hello", 18) {}

    // Виртуальные методы (полиморфизм)

    virtual ~Animal() {
        cout << "Животное c именем " << _name << " уничтоженно" << endl;
    }

    virtual void makeSound() const = 0;

    // не виртуальные методы
    string getName() const { return _name; }

    int getAge() const { return _age; }

    Animal& setName(const string& name) {
        _name = name;
        return *this;
    }

    Animal& setAge(int age) {
        _age = age;
        return *this;
    }

    void displayInfo() const {
        cout << "Имя: " << _name << ", Возраст: " << _age << " лет" << endl;
    }
};


//class Dog : public Animal {
//private:
//    string breed;
//
//public:
//    Dog(const string& name, int age, const string& breed) : Animal(name, age), breed(breed) {}
//
//    // Переопределение методов родителя (Полиморфизм)
//    void makeSound() const override {
//        cout << name << " сказал: Гав! Гав" << endl;
//    }
//
//    void  fetch() {
//        cout << name << " перехватил мяч!" << endl;
//    }
//
//    void displayInfo() {
//        Animal::displayInfo();
//        cout << ", Остальные данные: " << breed << " (Собака)" << endl;
//    }
//
//    ~Dog() override {
//        cout << "Собака была уничтожена " << name << endl;
//    }
//    
//};


class Cat : public Animal {
private:
    bool isCat;
    int lenth_hvost;

public:

    //Cat() : Animal() {}    // Конструктор по умолчанию, пустой конструктор
    Cat(const string& name, int age, bool isCat) : Animal(name, age), isCat(isCat) {}


    Cat& setIsCat(bool isCat) {
        this->isCat = isCat;
        return *this;
    }


    Cat& setLenthHvost(bool lenth_hvost) {
        this->lenth_hvost = lenth_hvost;
        return *this;
    }


    // Переопределение методов родителя (Полиморфизм)
    void makeSound() const override {
        cout << _name << " сказал: Мяу! Мяу" << endl;
    }

    void  scratch() {
        cout << _name << " катается на диване!" << endl;
    }

    void displayInfo() {
        Animal::displayInfo();
        cout << ", " << (isCat ? "(Кот)" : "(не Кот)") << endl;
    }

    ~Cat() override {
        cout << "Кот был уничтожен " << _name << endl;
    }
    
};




// Функция для демонстрации полиморфизма

void animalConcert(const vector<Animal*>& animals) {
    cout << "\n=== Концерт животных === " << endl;

    for (const Animal* animal : animals) {
        animal->makeSound();  // Вызывает разные реализации методов в зависимости от типа объекта
    }
    cout << "====================================" << endl;
}


int main()
{
    setlocale(LC_ALL, "");



    Dog dog("Rex", 3, "Labrador");
    Cat cat("Meower", 5, true);

    Cat ag = cat.setName("2").setIsCat(true).setLenthHvost(10);


    cout << "Имя собаки: " << dog.getName() << endl;
    cout << "Имя кота: " << cat.getName() << endl;


    dog.displayInfo();
    cat.displayInfo();

    vector<Animal*> animals;
    animals.push_back(new Dog("The Blue Dog", 50, "Бигель"));
    animals.push_back(new Cat("Гарффилд", 50, false));
    animals.push_back(new Dog("Мухтар", 12, "Овчарка"));
    animals.push_back(new Cat("Снежок", 7, true));

    animalConcert(animals);

    cout << "Информация о всех животных" << endl;

    for (const Animal* animal : animals) {
        animal->displayInfo();
    }

    for (const Animal* animal : animals) {
        delete animal;
    }

    return 0;
}
