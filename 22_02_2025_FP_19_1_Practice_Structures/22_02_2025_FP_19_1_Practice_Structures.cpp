
#include <iostream>
#include <string>

using namespace std;

struct WashingMachine {
    string brand;
    string color;
    double with;
    double length;
    double height;
    int power;
    int speen_speed;
    int temperature;

    // 1 способ объявления конструктора
    WashingMachine(string brand,
        string color,
        double with,
        double length,
        double height,
        int power,
        int speen_speed,
        int temperature
    ) {

        this->color = color;
        this->with = with;
        this->length = length;
        this->height = height;
        this->power = power;
        this->speen_speed = speen_speed;
        this->temperature = temperature;
    }

    // 2 способ объявления конструктора
   /* WashingMachine(string brand,
        string color,
        double with,
        double length,
        double height,
        int power,
        int speen_speed,
        int temperature
    ) : color(color), 
        with(with),
        length(length),
        height(height),
        power(power),
        speen_speed(speen_speed),
        temperature(temperature)
    {}*/

    void display_info() {
        cout << "Стиральная машинка " << brand << ",  цвет: " << color << endl;

    }
};


struct Animal {
    string name;
    string class_name;
    string nickname;

    Animal(string name, string class_name, string nickname) {
        this->name = name;
        this->class_name = class_name;
        this->nickname = nickname;
        
    }

    void display_info() {
        cout << "Животное: " << name << endl;
        cout << "Класс: " << class_name << endl;
        cout << "Кличка: " << nickname << endl;
        cout << endl;
    }

    void makeSound() {
        if (name == "Собака") {
            cout << nickname << "Гав" << endl;
        }
        else if (name == "Кошка") {
            cout << nickname << "Мяу" << endl;
        }
        else {
            cout << nickname << " издаёт звук!" << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "");

    WashingMachine wm("Samsung", "Белый", 60, 50, 85, 2000, 1200, 90);
    wm.display_info();

    Animal animal1("Собака", "Млекопитающее", "Бима");
    Animal animal2("Кошка", "Млекопитающее", "Мурка");
    Animal animal3("Олень", "Млекопитающее", "Беймби");
    
    animal1.display_info();
    animal1.makeSound();

    animal2.display_info();
    animal2.makeSound();

    animal3.display_info();
    animal3.makeSound();

    std::cout << "Hello World!\n";
}

