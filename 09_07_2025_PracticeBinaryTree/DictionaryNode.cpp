#include "DictionaryNode.h"
#include"BinaryTreeDictionary.h"

DictionaryNode::DictionaryNode(string eng, string rus)
	: english(eng), russian(rus), access_count(0), left(nullptr), right(nullptr) {}

