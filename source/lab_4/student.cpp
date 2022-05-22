#include <iostream>
#include <string>
using namespace std;

//vi de bai khong yeu cau cu the sap xep theo fields nao nen em tu chon theo diem trung binh (avg)

class Student {
	
	friend void sortDecreasingAVG(Student[], int);
	
	private:
		static int count;
		string id;
		string fullName;
		string className;
		int yearOfBirth;
		float avg;
		
	public:
		Student();
		
	public:
		static int idAscending() {
			count++;
		}
		
		string contrainId();
		Student inputData();
		void showData();
		
	
		
};

int Student::count = 0;

//ham rang buoc ma sinh vien theo format de bai
//cach lam hoi sida :D
string Student::contrainId() {
	string extensionNumber = to_string(count);
	
	if (count < 10) {
		string zero = "0";
		extensionNumber = zero.append(extensionNumber);
	}
	
	string name = "HAU205";
	return name.append(extensionNumber);  //id day du
}

Student::Student() {
	
}

Student Student::inputData() {
	
	Student student;
	
	student.id = contrainId();
	idAscending();
	
	
	cout << "Nhap ten sinh vien: ";
	cin >> student.fullName;
	cout << "Nhap ten lop: ";
	cin >> student.className;
	do {
		cout << "Nhap nam sinh: ";
		cin >> student.yearOfBirth;
	} while (student.yearOfBirth < 1900 || student.yearOfBirth > 2002);
	
	do {
		cout << "Nhap diem trung binh: ";
		cin >> student.avg;
	} while (student.avg < 0 || student.avg > 10);
	
	return student;
	
}

void Student::showData() {
	cout << "Ma sinh vien: " << id << endl;
	cout << "Ho va ten: " << fullName << endl;
	cout << "Lop: " << className << endl;
	cout << "Nam sinh: " << yearOfBirth << endl;
	cout << "Diem trung binh: " << avg << endl;
}

void showList(Student array[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Thong tin sinh vien: \n";
		array[i].showData();
	}
}

void sortDecreasingAVG(Student array[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (array[i].avg < array[j].avg) {
				Student student = array[i];
				array[i] = array[j];
				array[j] = student;
			}
		}
	}
}

int main() {
	
	int length;
	
	do {
		cout << "Nhap so luong sinh vien: ";
		cin >> length;
	} while (length < 1 || length > 100);  //vi  0<=XX<=99 theo de bai
	
	Student arrayStudent[length];
	
	for (int i = 0; i < length; i++) {
		Student student;
		cout << "Nhap thong tin sinh vien thu " << (i + 1) << endl;
		arrayStudent[i] = student.inputData();
	}
	
	sortDecreasingAVG(arrayStudent, length);
	cout << ">>>>>>>>>>>>>> Danh sach sinh vien sau khi sap xep theo diem trung binh giam dan <<<<<<<<<<<<<\n";
	showList(arrayStudent, length);
	cout << ">>>>>>>>>>>>>>> 10 ban co diem trung binh cao nhat <<<<<<<<<<<<<<<\n";
	//den day co the tan dung ham sap xep ben tren de lay 10sv dau tien
	for (int i = 0; i < 10; i++) {
		cout << "Sinh vien thu " << (i + 1) << ":\n";
		arrayStudent[i].showData();
	}
	
	return 0;
}






