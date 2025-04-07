#pragma once
#include <vector>
#include "Block.hpp"
#include <map>

using namespace std;

// Класс представления всей цепочки блоков
class BlockChain
{
private:
	vector<Block> chain;	// Вектор блоков
	int difficulty;			// Уровень сложности майнинга
	map<string, double> balances; //Баланс пользователей
	vector<Transaction> pendingTransactions; // Очередь транзакций




public:
	BlockChain();

	// Создание генезис-блока (т.е. самомый первый блок)
	void createBlock(vector<Transaction> transactions);

	// Получение последнего блока цепочки
	Block getLastestBlock() const;

	// Добавление нового блока к цепочке
	void addBlock(Block newBlock);

	// Проверка целостности блокчейна
	bool isChainValid() const;

	void printChain() const;

	// Добавление транзакций для дальнейшего майнинга
	void addTransaction(Transaction tx);


	// Получение баланса кошелька
	double getBalance(string address);

	// Майнинг блока с ожидающими транзакциями
	void minePendingTransactions(string minerAddress);

};
