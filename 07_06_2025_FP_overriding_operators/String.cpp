#include "String.h"



String::String(const char* s = "") {
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length+1, s);
}

String::String(const String& other) {
	length = other.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, other.str);
}

String::~String() {
	delete[] str;
}

String& String::operator=(const String& other) {
	if (this != &other) {
		delete[] str;
		length = other.length;
		str = new char[length + 1];
		strcpy_s(str, length + 1, other.str);

	}
	return *this;
}

String String::operator*(const String& other) const {
	char temp[BUFFER] = { 0 };
	int count = 0;

	// Маски для символов
	bool mask1[BUFFER] = { false };
	bool mask2[BUFFER] = { false };

	for (int i = 0; i < length; ++i) {
		mask1[(unsigned char)str[i]] = true;
	}

	for (int i = 0; i < other.length; ++i) {
		mask2[(unsigned char)other.str[i]] = true;
	}

	for(int i = 0; i < 256; ++i){
		if (mask1[i] && mask2[i]) {
			temp[count++] = (char)i;
		}
	}

	temp[count] = '\0';
	return String(temp);

}

void String::print() const {
	cout << str << endl;
}