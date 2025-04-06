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

void Transaction::printTrasaction() const {
		cout << "Transaction: " << hash << endl;
		cout << "Sender: " << sender << endl;
		cout << "Receiver: " << receiver << endl;
		cout << "Amount: " << amount << endl;
		cout << "Timestamp: " << timestamp << endl;
}