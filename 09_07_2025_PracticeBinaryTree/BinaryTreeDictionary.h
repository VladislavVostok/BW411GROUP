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
	void displayTreeHepler(DictionaryNode*, int, string);

public:
	BinaryTreeDictionary();
	void updateTranslation(string, string);
	void findAndDisplay(string);
	void addWord(string, string);
	void removeWord(string);
	void displayTopPopular();
	void displayTopUnpopular();
	void displayTreeWrap();
};