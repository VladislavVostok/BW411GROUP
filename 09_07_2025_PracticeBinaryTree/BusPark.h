#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Bus {
	int number;			// Ключ Номер автобуса
	string driver;
	int route;
	int seats;
	Bus* left;
	Bus* right;
};

class BusPark
{
private:
	Bus* root;
	void clearTree(Bus*);
	Bus* addBus(Bus* node, int number, string driver, int route, int seats);
	Bus* findBus(Bus* node, int number);
	void inorder(Bus* node, ostream& out);

public:
	BusPark();
	~BusPark();
	void addBus(int number, string driver, int route, int seats);


};

