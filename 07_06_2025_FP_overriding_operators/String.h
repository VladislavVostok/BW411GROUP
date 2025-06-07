#pragma once

#include <cstring>
#include <iostream>

#define BUFFER 256

using namespace std;

class String
{
private:
	char* str;
	int length;


public:
	String(const char*);
	String(const String&);
	~String();

	String& operator=(const String&);
	String operator*(const String&) const;
	void print() const;

};

