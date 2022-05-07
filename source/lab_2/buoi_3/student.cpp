#include <iostream>
using namespace std;

class Student {
	private:
		string fullName;
		int age;
		float toan;
		float van;
		float anh;
		
	public:
		Student();
		Student(string);
		Student(string, int, float);
		Student(string, int, float, float);
		Student(string, int, float, float, float);
		//...
		~Student();
		
	public:
		void dataInput();
		void showData();
		float avgCalc(float, float, float);
};

Student::Student() {
	
}

Student::~Student(){
	
}

void Student::dataInput() {
	cout << "Ho va ten: ";
	cin >> fullName;
	cout << "Tuoi: ";
	cin >> age;
	cout << "Diem Toan: ";
	cin >> toan;
	cout << "Diem Van: ";
	cin >> van;
	cout << "Diem Anh: ";
	cin >> anh;
}

float Student::avgCalc(float T, float V, float A) {
	return (T + V + A) / 3;
}

void Student::showData() {
	cout << "Ho va ten: " << fullName << endl;
	cout << "Tuoi: " << age << endl;
	cout << "Diem Toan: " << toan << endl;
	cout << "Diem Van: " << van << endl;
	cout << "Diem Anh: " << anh << endl;
	cout << "Diem trung binh: " << avgCalc(toan, van, anh) << endl;
}

int main() {
	
	Student student;
	
	cout << "Nhap thong tin sinh vien: \n";
	student.dataInput();
	
	cout << "=========================\n";
	cout << "Thong tin sinh vien: \n";
	student.showData();
	
	
	return 0;
}
