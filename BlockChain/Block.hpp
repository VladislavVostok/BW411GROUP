#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Block {

public:
	string previousHash;	// ��� ����������� �����
	string data;			// ������ ������������ � �����
	string hash;			// ��� �������� �����
	time_t timestamp;		// ��������� ����� ������ (��������) �����
	int nonce;				// ����� ����������� ��� ��������

	Block(string data, string previousHash);

	// ���������� ���� ����� (� ������ nonce)
	string calculateHash() const;

	// ����� "��������" ����� - ������� ���, ������������ � ������������ ���������� �����.
	void mineBlock(int difficulty);

};