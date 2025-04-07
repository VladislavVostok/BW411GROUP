#include <iostream>
#include "BlockChain.hpp"



int main()
{

    BlockChain blockchain; // Создаём блокчейн
    blockchain.addTransaction(Transaction("miner", "alice", 100));
    blockchain.addTransaction(Transaction("alice", "bob", 50));
    blockchain.addTransaction(Transaction("bob", "miner", 25));

    cout << endl << "Mining block with pending transactions..." << endl;
    blockchain.minePendingTransactions("miner");

    cout << endl << "Blockchain:" << endl;
    blockchain.printChain();

    cout << endl << "Blances:" << endl;
    cout << "miner -> " << blockchain.getBalance("miner") << endl;
    cout << "alice -> " << blockchain.getBalance("alice") << endl;
    cout << "bob -> " << blockchain.getBalance("bob") << endl;
    
    
    
    cout << "Is blockchain valid? " << (blockchain.isChainValid() ? "Yes" : "No");

    

    return 0;
}
