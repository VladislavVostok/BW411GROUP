#include "Circle.h"


Circle::Circle(double r = 1.0) : radius(r) {}

bool Circle::operator==(const Circle& other) const {
	return abs(radius - other.radius) < 1e-9;
}

bool Circle::operator>(const Circle& other) const {
	return (2 * PI * radius) > (2 * PI * other.radius);
}

Circle& Circle::operator+=(double value) {
	radius += value;
	if (radius < 0) radius = 0;
	return *this;
}


Circle& Circle::operator-=(double value) {
	radius -= value;
	if (radius < 0) radius = 0;
	return *this;
}

double Circle::getRadius() const {
	return radius;
}

double Circle::getLength() const {
	return 2 * PI * radius;
}