#include "BlockChain.hpp"

BlockChain::BlockChain() : difficulty(4) {
	Transaction genesisTx("system", "miner", 1000);
	pendingTransactions.push_back(genesisTx);
	createBlock(pendingTransactions);
	pendingTransactions.clear();
}

void BlockChain::createBlock(vector<Transaction> transactions) {
	string previousHash = chain.empty() ? "0" : chain.back().hash;
	chain.emplace_back(transactions, previousHash);
	chain.back().mineBlock(difficulty);

	for (const auto& tx : transactions) {
		balances[tx.getSender()] -= tx.getAmount();
		balances[tx.getReceiver()] += tx.getAmount();
	}
}

// 
void BlockChain::addTransaction(Transaction tx) {
	if (tx.getSender() != "system" && getBalance(tx.getSender()) < tx.getAmount()) {
		cout << "Transaction failed: insufficien funs!" << endl;
		return;
	}
		
	pendingTransactions.push_back(tx);
	cout << "Transaction added to pending pool!" << endl;
}

double BlockChain::getBalance(string address) {
	return balances.count(address) ? balances.at(address) : 0.0;
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

void BlockChain::minePendingTransactions(string minerAddress) {
	Transaction rewardTx("system", minerAddress, 10);
	pendingTransactions.push_back(rewardTx);

	createBlock(pendingTransactions);
	pendingTransactions.clear();
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

		if (current.merkeleRoot != current.calculateMerkeleRoot()) {
			cout << "Invalid Markele root for block " << i << endl;
			return false;
		}

		return true;
	}
}

void BlockChain::printChain() const {

	for (size_t i = 0; i < chain.size(); i++) {


		const Block& block = chain[i];
		cout << "Block: " << i << endl;
		cout << "Prev. hash: " << block.previousHash << endl;
		cout << "Merkle root:  " << block.merkeleRoot << endl;
		cout << "Hash : " << block.hash << endl;
		cout << "Timestamp: " << block.timestamp << endl;
		cout << "Nonce: " << block.nonce << endl;
		cout << "Transactions(" << block.transactions.size() << "):" << endl;

		for (const auto& tx : block.transactions) {
			tx.printTrasaction();
		}

		cout << string(40, '-') << endl;
	}

}
