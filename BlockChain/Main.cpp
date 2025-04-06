#include <iostream>
#include "BlockChain.hpp"



int main()
{

    BlockChain myBlockChain; // Создаём блокчейн
    cout << "Mining block 1..." << endl;
    myBlockChain.addBlock(Block("Transaction data 1", ""));    
    
    cout << "Mining block 2..." << endl;
    myBlockChain.addBlock(Block("Transaction data 2", ""));
    
    cout << "Mining block 3..." << endl;
    myBlockChain.addBlock(Block("Transaction data 2", ""));

    cout << "Blockchain contents: " << endl;
    myBlockChain.printChain();

    cout << "Is blockchain valid? " << (myBlockChain.isChainValid() ? "Yes" : "No") << endl;
    
    return 0;
}
