#include "BusPark.h"


BusPark::BusPark() : root(nullptr) {}
BusPark::~BusPark() {
	clearTree(root);
}


Bus* BusPark::addBus(Bus* node, int number, string driver, int route, int seats) {
	if (node == nullptr) {
		node = new Bus;
		node->number = number;
		node->driver = driver;

		node->route = route;
		node->seats = seats;
		node->left = node->right = nullptr;
	}
	else if (number < node->number) {
		node->left = addBus(node->left, number, driver, route, seats);
	}
	else {
		node->right = addBus(node->right, number, driver, route, seats);
	}

	return node;
}

void BusPark::addBus(int number, string driver, int route, int seats) {
	root = addBus(root, number, driver, route, seats);
}

Bus* BusPark::findBus(Bus* node, int number) {
	if (node == nullptr) return nullptr;
	if (number == node->number) return node;
	if (number < node->number) return findBus(node->left, number);
	return findBus(node->right, number);
}

void BusPark::clearTree(Bus* node) {
	if (node == nullptr) return;
	clearTree(node->left);
	clearTree(node->right);
	delete node;
}

void BusPark::inorder(Bus* node, ostream& out) {
	if (node != nullptr) {
		inorder(node->left, out);
		out << "Номен автобуса: " << node->number << endl;
		out << "Водитель: " << node->driver << endl;
		out << "Маршрут: " << node->route << endl;
		out << "Кол-во месе: " << node->seats << endl;
		out << "-------------------------- " << endl;
		inorder(node->right, out);
	}
}