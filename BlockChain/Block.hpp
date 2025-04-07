#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Transaction.hpp"

using namespace std;

class Block {

public:
	string previousHash;	// Хэш предыдущего блока
	vector<Transaction> transactions;			// Вектор транзакций в блоке
	string hash;			// Хэш текущего блока
	time_t timestamp;		// Временная метка добычи (создания) блока
	int nonce;				// Число подбираемое для майнинга
	string merkeleRoot;		// Корень дерева Меркела для транзакций

	Block(vector<Transaction> transactions, string previousHash);

	// Вычесление хэша блока (с учетом nonce)
	string calculateHash() const;

	// Метод "майнинга" блока - находит хэш, ничинающийся с определённого количества нулей.
	void mineBlock(int difficulty);

	string calculateMerkeleRoot() const;

};