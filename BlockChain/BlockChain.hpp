#pragma once
#include <vector>
#include "Block.hpp"
#include <map>

using namespace std;

// ����� ������������� ���� ������� ������
class BlockChain
{
private:
	vector<Block> chain;	// ������ ������
	int difficulty;			// ������� ��������� ��������
	map<string, double> balances; //������ �������������
	vector<Transaction> pendingTransactions; // ������� ����������




public:
	BlockChain();

	// �������� �������-����� (�.�. ������� ������ ����)
	void createBlock(vector<Transaction> transactions);

	// ��������� ���������� ����� �������
	Block getLastestBlock() const;

	// ���������� ������ ����� � �������
	void addBlock(Block newBlock);

	// �������� ����������� ���������
	bool isChainValid() const;

	void printChain() const;

	// ���������� ���������� ��� ����������� ��������
	void addTransaction(Transaction tx);


	// ��������� ������� ��������
	double getBalance(string address);

	// ������� ����� � ���������� ������������
	void minePendingTransactions(string minerAddress);

};
