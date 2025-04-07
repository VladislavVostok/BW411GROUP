#pragma once

#include <string>
#include <ctime>
#include <sstream>

using namespace std;

class Transaction
{
public:
	Transaction(string sender, string receiver, double amount);
	void printTrasaction() const;
	string getHashTx() const;
	string getSender() const;
	string getReceiver() const;
	double getAmount() const;

private:
	string calculateHash() const;

private:
	string sender;		// Отправитель
	string receiver;	// Получатель
	double amount;		// Сума
	time_t timestamp;	// Временная метка
	string hash;		// Хэш транзакции
};

