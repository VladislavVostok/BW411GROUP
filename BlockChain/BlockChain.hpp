#pragma once
#include <vector>
#include "Block.hpp"

using namespace std;

// ����� ������������� ���� ������� ������
class BlockChain
{
private:
	vector<Block> chain;	// ������ ������
	int difficulty;			// ������� ��������� ��������

public:
	BlockChain();

	// �������� �������-����� (�.�. ������� ������ ����)
	Block createGenesisBlock();

	// ��������� ���������� ����� �������
	Block getLastestBlock() const;

	// ���������� ������ ����� � �������
	void addBlock(Block newBlock);

	// �������� ����������� ���������
	bool isChainValid() const;

	void printChain() const;
};
