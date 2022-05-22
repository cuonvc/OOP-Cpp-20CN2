#include <iostream>
#include <iomanip>
using namespace std;

//hmmm....

class Student {
	
	friend void sortStudent(Student[], int);
	friend void showData(Student[], int);
	
	private:
		string id;
		float avg;
		
	public:
		Student();
		void input();
};

Student::Student() {
	
}

void Student::input() {
	cout << "Nhap ma sinh vien: ";
	cin >> id;
	cout << "Nhap diem trung binh: ";
	cin >> avg;
};

void showData(Student array[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "ID: " << array[i].id << endl;
		cout << "Diem trung binh: " << array[i].avg << endl;
		cout << ".....................\n";
	}
};

void sortStudent(Student array[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; i++) {
			if (array[i].avg > array[j].avg) {
				Student std = array[i];
				array[j] = array[i];
				array[i] = std;
			}
		}
	}
}



int main() {
	
	Student mainStudent;
	int length;
	string IDinput;
	
	cout << "Nhap so luong sinh vien: \n";
	cin >> length;
	
	Student arrayStudent[length];
	
	for (int i = 0; i < length; i++) {
		cout << "Nhap thong tin sinh vien thu " << (i + 1) << endl;
		arrayStudent[i].input();
	}
	
	cout << "THong tin nhung sinh vien vua nhap: \n";
	showData(arrayStudent, length);
	
	cout << "THong tin sinh vien sau khi sap xep: \n";
	sortStudent(arrayStudent, length);
	
	
}










