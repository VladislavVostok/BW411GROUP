#pragma once

#include <iostream>
#include <cmath>

#define PI 3.141592653589793

class Circle
{
	double radius;

public:
	Circle(double);
	bool operator==(const Circle&) const;
	bool operator>(const Circle&) const;
	Circle& operator+=(double);
	Circle& operator-=(double);

	double getRadius() const;
	double getLength() const;
};

