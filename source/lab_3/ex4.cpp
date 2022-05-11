#include <iostream>
#include <string>
using namespace std;

//De bai yeu cau nhap thong tin cua hai doi tuong cu the

class Student {
	
	friend void ageCompare(Student, Student);
	
	private:
		string name;
		int age;
		string address;
		string classroom;
		
		//contructors
	public:
		Student();
		Student(string, int, string, string);
		
		//getters
	public:
		string getName() {
			return name;
		}
		
		int getAge() {
			return age;
		}
		
		string getAddress() {
			return address;
		}
		
		string getClassroom() {
			return classroom;
		}
		
		//methods
	public:
		void inputData();
		void showData();
};

Student::Student() {
	
}

void Student::inputData() {
	cout << "Nhap ten: ";
	getline(cin, name);
	do {
		cout << "Nhap tuoi: ";
		cin >> age;
	} while (age <= 0);
	
	cout << "Nhap Dia chi: ";
	getline(cin, address);
	cin.ignore();
	cout << "Lop hoc: ";
	getline(cin, classroom);
}

void Student::showData() {
	cout << "Ten: " << name << endl;
	cout << "Tuoi: " << age << endl;
	cout << "Dia chi: " << address << endl;
	cout << "Lop hoc: " << classroom << endl;
}

void ageCompare(Student s1, Student s2) {
	if (s1.age > s2.age) {
		cout << "Tuoi cua sinh vine thu nhat lon hon.\n";
		s1.showData();
	} else if (s1.age < s2.age) {
		cout << "Tuoi cua sin vien thu hai lon hon.\n";
		s2.showData();
	} else {
		cout << "Hai sinh vien bang tuoi nhau\n";
	}
}

int main() {
	
	Student student1;
	Student student2;
	
	cout << "Nhap thong tin sinh vien thu nhat: \n";
	student1.inputData();
	cout << "Nhap thong tin sinh vien thu hai: \n";
	student2.inputData();
	
	ageCompare(student1, student2);
	
	return 0;
}















