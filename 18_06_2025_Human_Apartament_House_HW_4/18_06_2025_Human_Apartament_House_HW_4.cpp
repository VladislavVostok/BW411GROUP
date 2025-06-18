#include <iostream>
#include "Human.h"
#include "Apartament.h"
#include "House.h"

using namespace std;

Human& getHuman() {
    Human* h1 = new Human("1111111111", 23);
    return *h1;
}


int main()
{
    setlocale(LC_ALL, "");

    Human h1("ВАся", 23);
    Human h2("Петя", 40);
    Human h3("Галина", 96);
    Human h4("Лёха", 80);
    Human h5("Игнасио", 12);
    Human h6("Жанна", 49);
    Human h7("Андрей", 500);

    Human h777 = h7;

   Human h888 = move(Human("Игнасио", 12));
   Human h888444 = Human(Human("Игнасио", 12));

    Human h6666 = move(h1);

    Apartament ap1(101, 45.5);
    ap1.addResident(h1);
    ap1.addResident(h2);

    Apartament ap2(102, 60.5);
    ap2.addResident(h3);
    ap2.addResident(h4);

    Apartament ap3(102, 60.5);
    ap3.addResident(h5);
    ap3.addResident(h6);
    ap3.addResident(h7);

    House house(5, "ул. Затупкина, д. 7");
    house.addApartment(ap1);
    house.addApartment(ap2);
    house.addApartment(ap3);

    House houseCopy = house;

    Apartament aptCopy = ap1;
    
    return 0;
}
