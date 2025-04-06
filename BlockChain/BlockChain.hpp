#pragma once
#include <vector>
#include "Block.hpp"

using namespace std;

// Класс представления всей цепочки блоков
class BlockChain
{
private:
	vector<Block> chain;	// Вектор блоков
	int difficulty;			// Уровень сложности майнинга

public:
	BlockChain();

	// Создание генезис-блока (т.е. самомый первый блок)
	Block createGenesisBlock();

	// Получение последнего блока цепочки
	Block getLastestBlock() const;

	// Добавление нового блока к цепочке
	void addBlock(Block newBlock);

	// Проверка целостности блокчейна
	bool isChainValid() const;

	void printChain() const;
};
