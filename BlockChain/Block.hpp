#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Transaction.hpp"

using namespace std;

class Block {

public:
	string previousHash;	// ��� ����������� �����
	vector<Transaction> transactions;			// ������ ���������� � �����
	string hash;			// ��� �������� �����
	time_t timestamp;		// ��������� ����� ������ (��������) �����
	int nonce;				// ����� ����������� ��� ��������
	string merkeleRoot;		// ������ ������ ������� ��� ����������

	Block(vector<Transaction> transactions, string previousHash);

	// ���������� ���� ����� (� ������ nonce)
	string calculateHash() const;

	// ����� "��������" ����� - ������� ���, ������������ � ������������ ���������� �����.
	void mineBlock(int difficulty);

	string calculateMerkeleRoot() const;

};