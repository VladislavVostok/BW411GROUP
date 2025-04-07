#pragma once
#include <vector>
#include "Block.hpp"
#include <map>

using namespace std;

// ����� ������������� ���� ������� ������
class BlockChain
{


public:
	BlockChain();
	// ���������� ���������� ��� ����������� ��������
	void addTransaction(Transaction tx);

	// ������� ����� � ���������� ������������
	void minePendingTransactions(string minerAddress);

	// ��������� ������� ��������
	double getBalance(string address);

	void printChain() const;

	// �������� ����������� ���������
	bool isChainValid() const;


private:
	vector<Block> chain;	// ������ ������
	int difficulty;			// ������� ��������� ��������
	map<string, double> balances; //������ �������������
	vector<Transaction> pendingTransactions; // ������� ����������

private:
	// �������� �������-����� (�.�. ������� ������ ����)
	void createBlock(vector<Transaction> transactions);

	// ��������� ���������� ����� �������
	Block getLastestBlock() const;

	// ���������� ������ ����� � �������
	void addBlock(Block newBlock);


};