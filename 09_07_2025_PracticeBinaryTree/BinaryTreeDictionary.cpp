#include "BinaryTreeDictionary.h"


BinaryTreeDictionary::BinaryTreeDictionary() : root(nullptr) {}

DictionaryNode* BinaryTreeDictionary::insertNode(DictionaryNode* node, string eng, string rus) {
	if (node == nullptr) {
		return new DictionaryNode(eng, rus);
	}

	if (eng < node->english) {
		node->left = insertNode(node->left, eng, rus);
	}
	else if (eng > node->english) {
		node->right = insertNode(node->right, eng, rus);
	}
	else {
		node->russian = rus;
	}

	return node;

}


DictionaryNode* BinaryTreeDictionary::findNode(DictionaryNode* node, string eng) {
	if (node == nullptr || node->english == eng) {
		return node;
	}
	
	if (eng < node->english) {
		return findNode(node->left, eng);
	}
	else {
		return findNode(node->right, eng);
	}
}

DictionaryNode* BinaryTreeDictionary::deleteNode(DictionaryNode* node, string eng) {
	if (node == nullptr) return node;

	if (eng < node->english) {
		node->left = deleteNode(node->left, eng);
	}
	else if (eng > node->english) {
		node->right = deleteNode(node->right, eng);
	}
	else {
		if (node->left == nullptr) {
			DictionaryNode* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == nullptr) {
			DictionaryNode* temp = node->left;
			delete node;
			return temp;
		}
		DictionaryNode* temp = minValueNode(node->right);
		node->english = temp->english;
		node->russian = temp->russian;
		node->access_count = temp->access_count;
		node->right = deleteNode(node->right, temp->english);
	}

	return node;
}


DictionaryNode* BinaryTreeDictionary::minValueNode(DictionaryNode* node) {
	DictionaryNode* current = node;
	while (current && current->left != nullptr) {
		current = current->left;
	}
	return current;
}

void BinaryTreeDictionary::inorderTraversal(DictionaryNode* node, vector<DictionaryNode*>& nodes) {
	if (node == nullptr) return;
	inorderTraversal(node->left, nodes);
	nodes.push_back(node);
	inorderTraversal(node->right, nodes);
}

void BinaryTreeDictionary::addWord(string eng, string rus) {
	root = insertNode(root, eng, rus);
}

void BinaryTreeDictionary::findAndDisplay(string eng) {
	DictionaryNode* node = findNode(root, eng);
	if (node != nullptr) {
		node->access_count++;
		cout << "Перевод: " << node->russian << endl;
		cout << "Количество обращений: " << node->access_count << endl;
	}
	else {
		cout << "Слово не найдено в словаре." << endl;
	}
}

void BinaryTreeDictionary::updateTranslation(string eng, string new_rus) {
	DictionaryNode* node = findNode(root, eng);
	if (node != nullptr) {
		node->russian = new_rus;
		cout << "Перевод обновлён. " << endl;
	}
	else {
		cout << "Слово не найдено в словаре.";
	}
}

void BinaryTreeDictionary::removeWord(string eng) {
	root = deleteNode(root, eng);
}

void BinaryTreeDictionary::displayTopPopular() {
	vector<DictionaryNode*> nodes;
	inorderTraversal(root, nodes);
	sort(
		nodes.begin(),
		nodes.end(),
		[](DictionaryNode* a, DictionaryNode* b) {
			return a->access_count > b->access_count;
		}
	);

	cout << "Топ-3 популярных слова: " << endl;
	for (int i = 0; i < min(3, (int)nodes.size()); ++i) {
		cout << nodes[i]->english << " - " << nodes[i]->russian
			<< "(Обращений: " << nodes[i]->access_count << ")" << endl;
	}


}

void BinaryTreeDictionary::displayTreeHepler(DictionaryNode* node, int depth, string label) {
	if (node == nullptr) return;

	displayTreeHepler(node->right, depth + 1, "right");

	for (int i = 0; i < depth; i++) {
		cout << "           ";
	}

	cout << node->english << " (" << node->access_count << ")" << ((label == "right") ? "r" : "l") << endl;

	displayTreeHepler(node->left, depth + 1, "left");
}

void BinaryTreeDictionary::displayTreeWrap() {
	if (root == nullptr) {
		cout << "Дерево пустое." << endl;
		return;
	}
	displayTreeHepler(root, 0, "rt");
}

void BinaryTreeDictionary::displayTopUnpopular() {
	vector<DictionaryNode*> nodes;
	inorderTraversal(root, nodes);

	sort(
		nodes.begin(),
		nodes.end(),
		[](DictionaryNode* a, DictionaryNode* b) {
			return a->access_count < b->access_count;
		}
	);

	cout << "Топ-3 непопулярных слова: " << endl;
	for (int i = 0; i < min(3, (int)nodes.size()); ++i) {
		cout << nodes[i]->english << " - " << nodes[i]->russian
			<< "(Обращений: " << nodes[i]->access_count << ")" << endl;
	}


}

