#include "DictionaryNode.h"
#include "vector"
#include "iostream"
#include <algorithm>

using namespace std;


#pragma once
class BinaryTreeDictionary
{
private:
	DictionaryNode* root;

	DictionaryNode* insertNode(DictionaryNode*, string, string);
	DictionaryNode* findNode(DictionaryNode*, string);
	DictionaryNode* deleteNode(DictionaryNode*, string);
	DictionaryNode* minValueNode(DictionaryNode*);
	void inorderTraversal(DictionaryNode*, vector<DictionaryNode*>&);
	void updateTranslation(string, string);
public:
	BinaryTreeDictionary();
	void findAndDisplay(string);
	void addWord(string, string);
	void removeWord(string);
	void displayTopPopular();
	void displayTopUnpopular();
};

