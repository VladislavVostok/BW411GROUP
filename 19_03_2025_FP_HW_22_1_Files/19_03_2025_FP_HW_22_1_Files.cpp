#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Employee {
	string surname;
	string name;
	int age;
};

void loadFromFile(vector<Employee>& emploees, const string& filename);
void inputEmployee(Employee& emp);
void editEmployee(vector<Employee>& employees);
void deleteEmployee(vector<Employee>& employees);
void printEmployee(const Employee& emp);
void searchBySurname(const vector<Employee>& employees);
void searchByFirstLetter(const vector<Employee>& employees);
void searchByAge(const vector<Employee>& employees);
void printAllEmployees(const vector<Employee>& employees);
void saveToFile(const vector<Employee>& emploees, const string& filename);

int main()
{
	setlocale(LC_ALL, "");
	system("chcp 1251>nul");

	vector<Employee> employees;
	string filename;

	cout << "Введите имя файла для загрузки данных!\n";
	cin >> filename;

	loadFromFile(employees, filename);

	while (true) {
		cout << endl << "МЕНЮ" << endl;
		cout << "1. Добавление сотрудника" << endl;
		cout << "2. Редактирование сотрудника" << endl;
		cout << "3. Удаление сотрудника" << endl;
		cout << "4. Поиск по фамилии" << endl;
		cout << "5. Поиск по букве" << endl;
		cout << "6. Поиск по возрасту" << endl;
		cout << "7. Вывести всех сотрудников" << endl;
		cout << "8. Сохранить данные в файл" << endl;
		cout << "9. Выйти" << endl;

		int choice;
		cin >> choice;

		Employee emp;

		switch (choice)
		{
		case 1:
			inputEmployee(emp);
			employees.push_back(emp);
			break;
		case 2:
			editEmployee(employees);
			break;
		case 3:
			deleteEmployee(employees);
			break;
		case 4:
			searchBySurname(employees);
			break;
		case 5:
			searchByFirstLetter(employees);
			break;
		case 6:
			searchByAge(employees);
			break;
		case 7:
			printAllEmployees(employees);
			break;
		case 8:
			cout << "Введите имя файла для загрузки данных!\n";
			cin >> filename;
			saveToFile(employees, filename);
			break;		
		case 9:
			saveToFile(employees, "lastSave.txt");
			return 0;
		default:
			break;
		}
	}
	return 0;
}

void loadFromFile(vector<Employee>& emploees, const string& filename) {
	try {
		ifstream file(filename);

		if (file.is_open()) {
			Employee emp;
			while (file >> emp.surname >> emp.name >> emp.age) {
				emploees.push_back(emp);
			}

			file.close();

			cout << "Данные загруженны из файла: " << filename << endl;
		}
		else {
			cerr << "!!! Ошибка открытия файла: " << filename << endl;
		}
	}
	catch (...) {
		cout << "Что-то пошло не так" << endl;
	}
}

void saveToFile(const vector<Employee>& emploees, const string& filename) {
	try {
		ofstream file(filename);

		if (file.is_open()) {
			for (const auto& emp : emploees) {
				file << emp.surname << " " << emp.name << " " << emp.age << endl;
			}
			file.close();
			cout << "Данные сохранены в файл: " << filename << endl;
		}
		else {
			cout << "Что-то пошло не так" << endl;
		}
	}
	catch (...) {
		cout << "Что-то пошло не так" << endl;
	}
}

void inputEmployee(Employee& emp) {
	cout << "Введите фамилию: ";
	cin >> emp.surname;
	cout << "Введите имя: ";
	cin >> emp.name;
	cout << "Введите возраст: ";
	cin >> emp.age;
}

void editEmployee(vector<Employee>& employees) {
	string surname;
	cout << "Введите фамилию сотрудника для редактирования: ";
	cin >> surname;

	for (auto& emp : employees) {
		if (!emp.surname.empty() && emp.surname == surname) {
			inputEmployee(emp);
			break;
		}
	}
}

void deleteEmployee(vector<Employee>& employees) {
	string surname;
	cout << "Введите фамилию сотрудника для удаления: ";
	cin >> surname;

	for (auto& emp : employees) {
		if (!emp.surname.empty() && emp.surname == surname) {

			employees.erase(remove_if(
				employees.begin(),
				employees.end(),
				[&surname](const Employee& emp) { return emp.surname == surname; }),
				employees.end()
			);
		}
	}
}

void printEmployee(const Employee& emp) {
	cout << "Фамилия: " << emp.surname << endl;
	cout << "Имя: " << emp.name << endl;
	cout << "Возраст: " << emp.age << endl;
	cout << "---" << endl;

}

void searchBySurname(const vector<Employee>& employees) {

	vector<Employee> searched;

	string surname;
	cout << "Введите фамилию сотрудника для поиска: ";
	cin >> surname;

	for (const auto& emp : employees) {
		if (!emp.surname.empty() && emp.surname == surname) {
			printEmployee(emp);
			searched.push_back(emp);
		}
	}

	int choice;
	cout << "Вы хотите сохранить результаты поиска в файл: (1- да / 2 - нет)";
	cin >> choice;

	if (choice == 1) {
		saveToFile(searched, "saveBySurname.txt");
	}
}

void searchByFirstLetter(const vector<Employee>& employees) {
	char letter;
	cout << "Введите первую букву фамилии сотрудника для поиска: ";
	cin >> letter;

	for (const auto& emp : employees) {
		if (!emp.surname.empty() && emp.surname[0] == letter) {
			printEmployee(emp);
		}
	}
}


void searchByAge(const vector<Employee>& employees) {
	int age;
	cout << "Введите возраст сотрудника для поиска: ";
	cin >> age;

	for (const auto& emp : employees) {
		if (!emp.surname.empty() && emp.age == age) {
			printEmployee(emp);
		}
	}
}

void printAllEmployees(const vector<Employee>& employees) {
	for (const auto& emp : employees) {
		printEmployee(emp);
	}
}