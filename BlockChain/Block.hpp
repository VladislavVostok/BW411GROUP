#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Block {

public:
	string previousHash;	// Хэш предыдущего блока
	string data;			// Данные содержащиеся в блоке
	string hash;			// Хэш текущего блока
	time_t timestamp;		// Временная метка добычи (создания) блока
	int nonce;				// Число подбираемое для майнинга

	Block(string data, string previousHash);

	// Вычесление хэша блока (с учетом nonce)
	string calculateHash() const;

	// Метод "майнинга" блока - находит хэш, ничинающийся с определённого количества нулей.
	void mineBlock(int difficulty);

};