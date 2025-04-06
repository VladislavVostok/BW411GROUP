#pragma once

#include <string>
#include <ctime>
#include <sstream>

using namespace std;

class Transaction
{
public:
	string sender;		// �����������
	string receiver;	// ����������
	double amount;		// ����
	time_t timestamp;	// ��������� �����
	string hash;		// ��� ����������

	Transaction(string sender, string receiver, double amount);
	string calculateHash() const;
	void printTrasaction() const;
};

