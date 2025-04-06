#include "BlockChain.hpp"

BlockChain::BlockChain() : difficulty(4) {
	chain.push_back(BlockChain::createGenesisBlock());
}

Block BlockChain::createGenesisBlock() {
	return Block("Genesis Block", "0");
}

Block BlockChain::getLastestBlock() const {
	return chain.back();
}

void BlockChain::addBlock(Block newBlock) {
	// ������ ������ �� ���������� ����
	newBlock.previousHash = getLastestBlock().hash;

	// �������� ������� ������ �����
	newBlock.mineBlock(difficulty);

	// ��������� ����� ���� � �������
	chain.push_back(newBlock);
}

bool BlockChain::isChainValid() const {
	for (size_t i = 1; i < chain.size(); ++i) {

		const Block& current = chain[i];
		const Block& previous = chain[i - 1];

		// �������� ����������� �������� �����
		if (current.hash != current.calculateHash()) {
			cout << "Invalid hash at block " << i << endl;
			return false;
		}

		// �������� ������������ ����������� ����
		if (current.previousHash != previous.hash) {
			cout << "Invalid previous hash at block " << i << endl;
			return false;
		}

		return true;
	}
}

void BlockChain::printChain() const {
	for (const Block& block : chain) {
		cout << "------------------------" << endl;
		cout << "Timestamp: " << block.timestamp << endl;
		cout << "Data: " << block.data << endl;
		cout << "Hash: " << block.hash << endl;
		cout << "PreviousHash: " << block.previousHash << endl;
	}
}
