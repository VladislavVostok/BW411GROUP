#include "BinaryTreeDictionary.h"


void displayMenu();

int main()
{
	setlocale(LC_ALL, "");

	BinaryTreeDictionary dictionary;
	int choice;
	string eng, rus;


	dictionary.addWord("book", "книга");
	dictionary.addWord("cat", "кошка");
	dictionary.addWord("dog", "собака");
	dictionary.addWord("apple", "яблоко");
	dictionary.addWord("elephant", "слон");

	do {
		displayMenu();
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:
			cout << "Введите англ. слово:";
			getline(cin, eng);
			cout << "Введите рус. слово:";
			getline(cin, rus);
			dictionary.addWord(eng, rus);
			break;
		case 2:
			cout << "Введите англ. слово для поиска перевода:";
			getline(cin, eng);
			dictionary.findAndDisplay(eng);
			break;
		case 3:
			cout << "Введите англ. слово:";
			getline(cin, eng);
			cout << "Введите новое рус. слово:";
			getline(cin, rus);
			dictionary.updateTranslation(eng, rus);
			break;
		case 4:
			cout << "Введите англ. слово для удаления:";
			getline(cin, eng);
			dictionary.removeWord(eng);
			break;
		case 5:
			dictionary.displayTopPopular();
			break;
		case 6:
			dictionary.displayTopUnpopular();
			break;
		case 7:
			dictionary.displayTreeWrap();
			break;
		case 8:
			cout << "Выход из программы." << endl;
			break;

		default:
			cout << "Неверный выбор. Попробуйте снова." << endl;
		}
	} while (choice != 8);
}


void displayMenu() {
	cout << endl << "Меню англо-русского словаря: " << endl;
	cout << "1. Добавить слово" << endl;
	cout << "2. Найти и показать перевод" << endl;
	cout << "3. Обновить перевод" << endl;
	cout << "4. Удалить слово" << endl;
	cout << "5. Показать топ-3 популярных слов" << endl;
	cout << "6. Показать топ-3 непопулярных слов" << endl;
	cout << "7. Показать дерево" << endl;
	cout << "8. Выход" << endl;
	cout << "Выберите действие: ";
}
