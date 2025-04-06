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
	// Ставим ссылку на предыдущий блок
	newBlock.previousHash = getLastestBlock().hash;

	// Проводим майнинг ногого блока
	newBlock.mineBlock(difficulty);

	// Добавляем новый блок в цепочку
	chain.push_back(newBlock);
}

bool BlockChain::isChainValid() const {
	for (size_t i = 1; i < chain.size(); ++i) {

		const Block& current = chain[i];
		const Block& previous = chain[i - 1];

		// Проверка целостности текущего блока
		if (current.hash != current.calculateHash()) {
			cout << "Invalid hash at block " << i << endl;
			return false;
		}

		// Проверка соответствия предыдущего хэша
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
