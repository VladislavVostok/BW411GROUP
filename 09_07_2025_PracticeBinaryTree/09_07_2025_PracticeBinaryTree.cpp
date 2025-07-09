#include "BinaryTreeDictionary.h"


void displayMenu();

int main()
{
	setlocale(LC_ALL, | "");

	BinaryTreeDictionary dictionary;
	int choice;
	string eng, rus;

	dictionary.addWord("apple", "яблоко");
	dictionary.addWord("book", "книга");
	dictionary.addWord("cat", "кошка");
	dictionary.addWord("dog", "собака");
	dictionary.addWord("elephant", "слон");

	do {
		displayMenu();
		cin >> choice;
		cin.ignore();
		switch (choice) {

		}
	} while (choice != 7);
}


void displayMenu() {
	cout << endl << "Меню англо-русского словаря: " << endl;
	cout << "1. Добавить слово" << endl;
	cout << "2. Найти и показать перевод" << endl;
	cout << "3. Обновить перевод" << endl;
	cout << "4. Удалить слово" << endl;
	cout << "5. Показать топ-3 популярных слов" << endl;
	cout << "6. Показать топ-3 непопулярных слов" << endl;
	cout << "7. Выход" << endl;
	cout << "Выберите действие: ";
}
