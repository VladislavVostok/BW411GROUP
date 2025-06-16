#include <iostream>
#include "Circle.h"
#include "Airplane.h"

using namespace std;

int main()
{

    Circle r1(5.0);
    Circle r2(5.0);
    Circle r3(3.0);


    cout << "r1 == r2 " << (r1 == r2) << endl;
    cout << "r1 > r3 " << (r1 > r3) << endl;

    r1 += 1.0;
    cout << "r1 new radius " << r1.getRadius() << " " << r1.getLength() << endl;

    r2 -= 2.0;
    cout << "r2 new radius " << r2.getRadius() << " " << r2.getLength() << endl;

    Airplane a1("Boeing 737", 150);
    Airplane a2("Airbus A320", 180);
    Airplane a3("Boeing 737", 200);



    cout << "a1 == a2 " <<  (a1 == a2) << endl;
    cout << "a1 == a3 " <<  (a1 == a3) << endl;

    ++a1; ++a1;
    --a2;
    a1.printStatus();
    a2.printStatus();

    cout << "a2 > a1 " << (a2 > a1) << endl;
    cout << "a3 > a2 " << (a3 > a2) << endl;

    Airplane aa777 = move(a1);

    return 0;
}

