#include <iostream>
using namespace std;

class Student {
	private: 
		string fullName;
		int age;
		float avg;
		
	public:
		void inputData();
		void showData();
		void studentFilterByName(string, Student, Student);
		
	public:
		void setFullName(string ten) {
			fullName = ten;
		}
		
		string getFullName() {
			return fullName;
		}
		
		int getAge() {
			return age;
		}
		
		float getAvg() {
			return avg;
		}
};

void Student::inputData() {
	cout << "Nhap ten: ";
	cin >> fullName;
	cout << "Tuoi: ";
	cin >> age;
	cout << "Diem trung binh: ";
	cin >> avg;
}

void Student::showData() {
	cout << "Ho va ten: " << fullName << endl;
	cout << "Tuoi: " << age << endl;
	cout << "Diem trung binh: " << avg << endl;
}

void Student::studentFilterByName(string nameInput, Student std1, Student std2) {
	if(nameInput == std1.getFullName()) {
		std1.showData();
	} else if (nameInput == std2.getFullName()) {
		std2.showData();
	} else {
		cout << "Khong tim thay thong tin.....\n";
	}
}

int main() {
	
	Student student1;
	Student student2;
	Student student;
	
	string name;
	
	cout << "Nhap thong tin sinh vien thu nhat: \n";
	student1.inputData();
	
	cout << "Thong tin sinh vien thu nhat: \n";
	student1.showData();
	
	cout << "Nhap thong tin sinh vien thu hai: \n";
	student2.inputData();
	
	cout << "Thong tin sinh vien thu hai: \n";
	student2.showData();
	
	cout << "Nhap tu khoa theo ten: ";
	cin >> name;
	
	cout << "Thong tin tim kiem sinh vien: \n";
	student.studentFilterByName(name, student1, student2);
	
	
	return 0;
}
