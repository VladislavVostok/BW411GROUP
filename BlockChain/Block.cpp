#include "Block.hpp"
#include "SHA256.hpp"

Block::Block(string data, string previousHash) : data(data), previousHash(previousHash), timestamp(time(nullptr)), nonce(0) {
	hash = calculateHash();

}

string Block::calculateHash() const {
	stringstream ss;
	ss << previousHash << timestamp << data << nonce;
	return SHA256::hash(ss.str());
}

void Block::mineBlock(int difficulty) {
	string target(difficulty, '0');

	while (hash.substr(0, difficulty) != target) {
		++nonce;
		hash = calculateHash(); // обновляем хэш после изменения nonce
	}
	cout << "Block mined: " << hash << endl;
}