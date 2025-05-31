// Задание №1
//    Реализуйте класс “Студент”.Необходимо хранить в переменных-членах класса (поля) : 
//      ФИО, 
//      дату рождения, 
//      контактный телефон,
//      город, 
//      страну, 
//      название учебного заведения, 
//      город и страну(где находится учебное заведение), 
//      номер группы.
// 
// Реализуйте функции-члены класса (методы) для 
//      ввода данных, 
//      вывода данных, 
//      реализуйте аксессоры для доступа к отдельным переменным - членам (полям).

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <fstream>


using namespace std;
//
//class Student{
//private:
//    char* fullName;
//    string birthDate;
//    string phone;
//    string city;
//    string country;
//    string institution;
//    string institutionCity;
//    string institutionCountry;
//    string group;
//    static int count;
//
//public:
//
//    // Простые конструкторы
//    Student() :
//        fullName(nullptr),
//        birthDate(""),
//        phone(""),
//        city(""),
//        country(""),
//        institution(""),
//        institutionCity(""),
//        institutionCountry(""),
//        group("") 
//    {
//        count++;
//    }
//
//    Student(const char* name, const string& date) :
//        birthDate(date),
//        phone(""),
//        city(""),
//        country(""),
//        institution(""),
//        institutionCity(""),
//        institutionCountry(""),
//        group("") {
//        
//        fullName = new char[strlen(name) + 1];
//        strcpy_s(fullName, strlen(name) + 1, name);
//        count++;
//    }
//
//    // Делегирующие конструкторы
//    Student(const char* name) : Student(name, "") {}
//
//    // Деструктор
//    ~Student() {
//        delete[] fullName;
//        count--;
//    }
//
//    // Аксессры
//    inline const char* getFullName() const { return fullName; }
//    inline string getBirthDate() const { return birthDate; }
//    inline string getPhone() const { return phone; }
//    inline string getCity() const { return city; }
//    inline string getCountry() const { return country; }
//    inline string getInstitution() const { return institution; }
//    inline string getInstitutionCity() const { return institutionCity; }
//    inline string getInstitutionCountry() const { return institutionCountry; }
//    inline string getGroup() const { return group; }
//
//    inline void setFullName(const char* name) { 
//        delete[] fullName;
//        fullName = new char[strlen(name) + 1];
//        strcpy_s(fullName, strlen(name) + 1, name);
//    }
//
//    inline void setBirthDate(const string& date) { birthDate = date; }
//    inline void setPhone(const string& p) { phone = p; }
//    inline void setCity(const string& c) { city = c; }
//    inline void setCountry(const string& c) { country = c; }
//    inline void setInstitution(const string& i) { institution = i; }
//    inline void setInstitutionCity(const string& ic) { institutionCity = ic; }
//    inline void setInstitutionCountry(const string& ic) { institutionCountry = ic; }
//    inline void setGroup(const string& g) { group = g; }
//    
//    // Вспомогательные методы
//    void input() {
//        char buffer[100];
//        cout << "Введите полное имя";
//        cin.getline(buffer, 100);
//        setFullName(buffer);
//    
//        cout << "Введите дату рождения";
//        getline(cin, birthDate);
//
//        cout << "Введите телефон";
//        getline(cin, phone);
//
//        cout << "Введите город";
//        getline(cin, city);
//
//        cout << "Введите страну";
//        getline(cin, country);
//
//        cout << "Введите название института";
//        getline(cin, institution);
//
//        cout << "Введите город института";
//        getline(cin, institutionCity);
//
//        cout << "Введите страну института";
//        getline(cin, institutionCountry);
//
//        cout << "Введите группу";
//        getline(cin, group);
//    }
//
//    void output() {
//        cout << "Информация о студенте:" << endl;
//        cout << "Полное имя:\t" << (fullName ? fullName : "") << endl;
//        cout << "Дата рождения:\t" << birthDate << endl;
//        cout << "Телефон:\t" << phone << endl;
//        cout << "Город:\t" << city << endl;
//        cout << "Страна:\t" << country << endl;
//        cout << "Институт:\t" << institution << endl;
//        cout << "Город института:\t" << institutionCity << endl;
//        cout << "Страна института:\t" << institutionCountry << endl;
//        cout << "Группа:\t" << group << endl;
//    }
//
//    static int getCount() { return count; }
//
//
//};
//
//int Student::count = 0;
//
//
//
//
//
//
//int main()
//{
//    setlocale(LC_ALL, "");
//
//    cout << Student::getCount() << endl;
//    Student* nikita = new Student();
//    cout << Student::getCount() << endl;
//    Student* alim = new Student("Алим", "1234.12.2");
//    cout << Student::getCount() << endl;
//    Student* victor = new Student();
//    cout << Student::getCount() << endl;
//    Student* dima = new Student();
//    cout << Student::getCount() << endl;
//    Student* andrey = new Student();
//    cout << Student::getCount() << endl;
//    Student* alex = new Student();
//    cout << Student::getCount() << endl;
//    Student* angelina = new Student();
//
//    cout << Student::getCount() << endl;
//    
//
//    alim->output();
//    nikita->input();
//    nikita->output();
//
//
//
//    delete nikita;
//    cout << Student::getCount() << endl;
//
//
//    delete alim;
//    cout << Student::getCount() << endl;
//
//    delete victor;
//    cout << Student::getCount() << endl;
//
//    delete dima;
//    cout << Student::getCount() << endl;
//
//    delete andrey;
//    cout << Student::getCount() << endl;
//
//    delete alex;
//    cout << Student::getCount() << endl;
//
//
//    delete angelina;
//    cout << Student::getCount() << endl;
//
//
//
//}



// Задание №2
// 
// Реализуйте класс “Точка”.
// Необходимо хранить 
//	координаты x, y, z в переменных - членах класса.
// 
// Реализуйте функции - члены класса для 
//	ввода данных, 
//	вывода данных, 
//	реализуйте аксессоры для доступа к переменным - членам, 
//	реализуйте сохранение в файл 
//	загрузку данных из файла.




class Point {
private: 
	double x, y, z;
	
public:
	//Point(): x(0), y(0), z(0){}
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
	Point(double val): Point(val,val,val){}
	Point() {}
	Point(const Point& point) : x(point.x), y(point.y), z(point.z) {}


	inline double getX() const { return x; }
	inline double getY() const { return y; }
	inline double getZ() const { return z; }

	inline void setX(double val1) { x = val1; }
	inline void setY(double val1) { y = val1; }
	inline void setZ(double val1) { z = val1; }

	void input() {
		cout << "Введите x, y, z";
		cin >> x >> y >> z;
		cin.ignore();
	}

	void output() const {
		cout << "Point(" << x << ", " << y << ", " << z << ")" << endl;
	}

	void saveToFile(const string& filename) const {
		ofstream file(filename);
		if (file) {
			file << x << " " << y << " " << z;
		}
	}

	void loadFromFile(const string& filename) {
		ifstream file(filename);
		if (file) {
			file >> x >> y >> z;
		}
	}

};

int main() {

	Point p1(1.5, 2.5, 3.5);
	double i = p1.getZ();

	//p1.output();
	//p1.saveToFile("point.txt");

	Point p2{ 1.5, 2.5, 3.5 };


	Point p3_hidden_construct{ p2 };
	//p2.loadFromFile("point.txt");
	//p2.output();

	//Point p3(14.0);
	//p3.output();

	return 0;
}
