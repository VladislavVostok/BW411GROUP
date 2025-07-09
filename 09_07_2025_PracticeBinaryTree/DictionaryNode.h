#include <string>

using namespace std;

#pragma once
class DictionaryNode
{
public: 
	string english;
	string russian;
	int access_count;
	DictionaryNode* left;
	DictionaryNode* right;

	DictionaryNode(string, string);
};

