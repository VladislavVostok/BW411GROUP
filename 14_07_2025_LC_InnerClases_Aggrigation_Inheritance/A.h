#pragma once
#include <iostream>
#include <string.h>
using namespace std;

//
//class Outer
//{
//
//private:
//	class HiddenInner {
//	public:
//		static int const Secter = 666;
//		void secret();
//	};
//
//
//public:
//	void reval();
//};
//
//
//
//void Outer::reval() {
//	HiddenInner inner;
//	inner.secret();
//}
//
//
//void Outer::HiddenInner::secret() {
//	cout << "ћой секрет";
//}


//class A {
//public:
//	//...
//private:
//	//объ€вление A::B
//	class B;
//	class Ref {
//		//pli имеет тип A::B*
//		B* pli;
//	};
//	//определение A::B
//	class B {
//		//pref имеет тип A::Ref*
//		Ref* pref;
//	};
//};



//класс "точка"
//class Point {
//
//	//кооординаты
//	int X;
//	int Y;
//
//public:
//	//конструктор
//	Point() {
//		X = Y = 0;
//	}
//
//	//установка координат
//	void SetPoint(int iX, int iY) {
//		X = iX;
//		Y = iY;
//	}
//
//	//демонстраци€ координат
//	void Show() {
//		cout << "----------------------------\n\n";
//		cout << X << "\t" << Y << "\n\n";
//		cout << "----------------------------\n\n";
//	}
//};
//
////класс фигура
//class Figura {
//	//агрегаци€ точки
//	//(координаты углов)
//	Point* obj;
//	//количество углов
//	int count;
//	//цвет фигуры
//	int color;
//
//public:
//	//конструктор
//	Figura() {
//		count = color = 0;
//		obj = NULL;
//	}
//	//создание фигуры
//	void CreateFigura(int cr, int ct) {
//		//если углов меньше трех Ч это не фигура
//		if (ct < 3) exit(0);
//		//инициализаци€ цвета и количества углов
//		count = ct;
//		color = cr;
//		//выдделение пам€ти под массив точек
//		obj = new Point[count];
//		if (!obj) exit(0);
//		//установка координат точек
//		int tempX, tempY;
//		for (int i = 0; i < count; i++) {
//			cout << "Set X\n";
//			cin >> tempX;
//			cout << "Set Y\n";
//			cin >> tempY;
//			obj[i].SetPoint(tempX, tempY);
//		}
//	}
//	//показ фигуры
//	void ShowFigura() {
//		cout << "----------------------------\n\n";
//		cout << "Color" << color << "\n\nPoints Ч " << count << "\n\n";
//		for (int i = 0; i < count; i++) {
//			obj[i].Show();
//		}
//	}
//	//если фигура была очистить пам€ть
//	~Figura() {
//		if (obj != NULL) delete[]obj;
//	}
//};


//class X {
//
//protected:
//	int i;
//	int j;
//
//public:
//	void get_ij() {
//		cout << "Enter two numbers: ";
//		cin >> i >> j;
//	}
//	void put_ij() { 
//		cout << i << " " << j << "\n"; 
//	}
//};
//
//
//
//// в классе Y, i и j класса X защищенными членами
//class Y  {
//protected:
//	int i;
//	int k;
//public:
//
//
//	int get_k() { 
//		return k; 
//	}
//	//void make_k() { k = i * j; }
//};
//
//
//
///* класс Z имеет доступ к i и j класса X, но не к k класса Y, поскольку он €вл€етс€ частным */
//class Z : public X, public Y {
//public:
//	void f();
//};
//// i и j доступны отсюда
//void Z::f()
//{
//
//	k = 4;
//	i = 2; // нормально
//	j = 3; // нормально
//}


// ласс "рога"
class Roga {

protected:
	char color[25];
	int wes;

public:
	Roga() {
		strcpy(color, "Dirty");
		wes = 20;
	}
	Roga(char* c, int w) {
		strcpy(color, c);
		wes = w;
	}
};



// ласс "копыта"
class Kopyta {
protected:
	char forma[25];
	int razmer;
public:
	Kopyta() {
		strcpy(forma, "Big");
		razmer = 10;
	}
	Kopyta(char* c, int w) {
		strcpy(forma, c);
		razmer = w;
	}
};


// ласс "Ћось", производный от
//классов "рога" и "копыта"
class Los : public Roga, public Kopyta {
public:
	char name[255];

	Los(char* c) : Kopyta(), Roga() {
		strcpy(name, c);
	}

	Los(char* c, char* col, int wes, char* form, int razm) : Kopyta(col, wes), Roga(form, razm) {
		strcpy(name, c);
	}

	//‘ункци€ потомка может обращатьс€ к
	//элементам обоих базовых классов
	void DisplayInfo() {
		cout << "Name " << name << "\n";
		cout << "Forma " << forma << "\n";
		cout << "Color " << color << "\n";
		cout << "Wes rogov " << wes << "\n";
		cout << "Razmer kopyt " << razmer << "\n";
	}
};
