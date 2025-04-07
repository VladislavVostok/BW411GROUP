#include "Transaction.hpp"
#include "SHA256.hpp"

Transaction::Transaction(string sender, string receiver, double amount) :
	sender(sender),
	receiver(receiver),
	amount(amount),
	timestamp(time(nullptr))
{
	hash = calculateHash();
}

string Transaction::calculateHash() const {
	stringstream ss;
	ss << sender << receiver << amount << timestamp;
	return SHA256::hash(ss.str());
}

string Transaction::getHashTx() const {
	return hash;
}
string Transaction::getReceiver() const {
	return receiver;
}

string Transaction::getSender() const {
	return sender;
}
double Transaction::getAmount() const {
	return amount;
}

void Transaction::printTrasaction() const {
	cout << "____________________________" << endl;
	cout << "Transaction: " << hash << endl;
	cout << "Sender: " << sender << endl;
	cout << "Receiver: " << receiver << endl;
	cout << "Amount: " << amount << endl;
	cout << "Timestamp: " << timestamp << endl;
}