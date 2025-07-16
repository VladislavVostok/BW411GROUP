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
//	cout << "��� ������";
//}


//class A {
//public:
//	//...
//private:
//	//���������� A::B
//	class B;
//	class Ref {
//		//pli ����� ��� A::B*
//		B* pli;
//	};
//	//����������� A::B
//	class B {
//		//pref ����� ��� A::Ref*
//		Ref* pref;
//	};
//};



//����� "�����"
//class Point {
//
//	//�����������
//	int X;
//	int Y;
//
//public:
//	//�����������
//	Point() {
//		X = Y = 0;
//	}
//
//	//��������� ���������
//	void SetPoint(int iX, int iY) {
//		X = iX;
//		Y = iY;
//	}
//
//	//������������ ���������
//	void Show() {
//		cout << "----------------------------\n\n";
//		cout << X << "\t" << Y << "\n\n";
//		cout << "----------------------------\n\n";
//	}
//};
//
////����� ������
//class Figura {
//	//��������� �����
//	//(���������� �����)
//	Point* obj;
//	//���������� �����
//	int count;
//	//���� ������
//	int color;
//
//public:
//	//�����������
//	Figura() {
//		count = color = 0;
//		obj = NULL;
//	}
//	//�������� ������
//	void CreateFigura(int cr, int ct) {
//		//���� ����� ������ ���� � ��� �� ������
//		if (ct < 3) exit(0);
//		//������������� ����� � ���������� �����
//		count = ct;
//		color = cr;
//		//���������� ������ ��� ������ �����
//		obj = new Point[count];
//		if (!obj) exit(0);
//		//��������� ��������� �����
//		int tempX, tempY;
//		for (int i = 0; i < count; i++) {
//			cout << "Set X\n";
//			cin >> tempX;
//			cout << "Set Y\n";
//			cin >> tempY;
//			obj[i].SetPoint(tempX, tempY);
//		}
//	}
//	//����� ������
//	void ShowFigura() {
//		cout << "----------------------------\n\n";
//		cout << "Color" << color << "\n\nPoints � " << count << "\n\n";
//		for (int i = 0; i < count; i++) {
//			obj[i].Show();
//		}
//	}
//	//���� ������ ���� �������� ������
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
//// � ������ Y, i � j ������ X ����������� �������
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
///* ����� Z ����� ������ � i � j ������ X, �� �� � k ������ Y, ��������� �� �������� ������� */
//class Z : public X, public Y {
//public:
//	void f();
//};
//// i � j �������� ������
//void Z::f()
//{
//
//	k = 4;
//	i = 2; // ���������
//	j = 3; // ���������
//}


//����� "����"
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



//����� "������"
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


//����� "����", ����������� ��
//������� "����" � "������"
class Los : public Roga, public Kopyta {
public:
	char name[255];

	Los(char* c) : Kopyta(), Roga() {
		strcpy(name, c);
	}

	Los(char* c, char* col, int wes, char* form, int razm) : Kopyta(col, wes), Roga(form, razm) {
		strcpy(name, c);
	}

	//������� ������� ����� ���������� �
	//��������� ����� ������� �������
	void DisplayInfo() {
		cout << "Name " << name << "\n";
		cout << "Forma " << forma << "\n";
		cout << "Color " << color << "\n";
		cout << "Wes rogov " << wes << "\n";
		cout << "Razmer kopyt " << razmer << "\n";
	}
};
