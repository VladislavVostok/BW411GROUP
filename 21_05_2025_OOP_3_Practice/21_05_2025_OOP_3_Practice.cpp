#include <iostream>
#include <string>
#include <vector>


using namespace std;

// Базовый абстрактный класс
class Animal {
protected:
    // Защищённые поля класа (Инкапсуляция)
    string name;
    int age;

public:

    // Первый способ организации конструктора
    Animal(const string& name, int age) : name(name), age(age) {}

    // Второй способ организации конструктора
    //Animal(const string& name, int age) {
    //    this->age = age;
    //    this->name = name;
    //}

    // Виртуальные методы (полиморфизм)

    virtual ~Animal() {
        cout << "Животное c именем " << name << " уничтоженно" << endl;
    }

    virtual void makeSound() const = 0;

    // не виртуальные методы
    string getName() const { return name; }
    int getAge() const { return age; }

    void displayInfo() const {
        cout << "Имя: " << name << ", Возраст: " << age << " лет" << endl;
    }
};


class Dog : public Animal {
private:
    string breed;

public:
    Dog(const string& name, int age, const string& breed) : Animal(name, age), breed(breed) {}

    // Переопределение методов родителя (Полиморфизм)
    void makeSound() const override {
        cout << name << " сказал: Гав! Гав" << endl;
    }

    void  fetch() {
        cout << name << " перехватил мяч!" << endl;
    }

    void displayInfo() {
        Animal::displayInfo();
        cout << ", Остальные данные: " << breed << " (Собака)" << endl;
    }

    ~Dog() override {
        cout << "Собака была уничтожена " << name << endl;
    }
    
};


class Cat : public Animal {
private:
    bool isCat;

public:
    Cat(const string& name, int age, bool isCat) : Animal(name, age), isCat(isCat) {}

    // Переопределение методов родителя (Полиморфизм)
    void makeSound() const override {
        cout << name << " сказал: Мяу! Мяу" << endl;
    }

    void  scratch() {
        cout << name << " катается на диване!" << endl;
    }

    void displayInfo() {
        Animal::displayInfo();
        cout << ", " << (isCat ? "(Кот)" : "(не Кот)") << endl;
    }

    ~Cat() override {
        cout << "Кот был уничтожен " << name << endl;
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
