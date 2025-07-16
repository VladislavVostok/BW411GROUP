#include <iostream>
#include <string>

using namespace std;

__interface IInterface
{
	void test1();

};



int main() {
	Student student("Никита", "Тихонов", "BW411", 12.0);
	Aspirant aspirant("Альберт", "Эйнштейн", "BW421", 12.0, "Quantum Machine Learning war whith robots!");
	student.printInfo();
	aspirant.printInfo();
	return 0;
}



class Student {
protected:
	string fName;
	string lName;
	string group;
	double averMark;


public:
	Student(const string& fName, const string& lName, const string& group, double averMark) :
		fName(fName), lName(lName), group(group), averMark(averMark) {}

	virtual int getScholarship() const {
		return (averMark >= 10 && averMark <= 12) ? 2000 : 0;
	}

	 void printInfo() const {
		cout << "Student" << fName << " " << lName << endl;
		cout << "Group" << group << endl;
		cout << "Average mark" << averMark << endl;
		cout << "Scholaship" << getScholarship() << "Nepal Ruppie" << endl;

	}


};

class Aspirant : public Student {
private:
	string researchWork;

public:
	Aspirant(const string& fName, const string& lName, const string& group, double averMark, const string& researchWork) 
		: Student(fName, lName, group, averMark), researchWork(researchWork) {}
	
	int getScholarship() const override 
	{
		return (averMark >= 10 && averMark <= 12) ? 6000 : 0;
	}
	void test1();

	void printInfo() const override {
		cout << "Aspirant" << fName << " " << lName << endl;
		cout << "Group" << group << endl;
		cout << "researchWork" << researchWork << endl;
		cout << "Average mark" << averMark << endl;
		cout << "Scholaship" << getScholarship() << "Nepal Ruppie" << endl;

	}

};


