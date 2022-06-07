#include <iostream>
using namespace std;

class Employee {
	protected:
		string name;
		int age;
		
	public:
		Employee();
		Employee(string, int);
		~Employee();
		
		//getters
	public:
		string getName() {
			return name;
		}
		
		int getAge() {
			return age;
		}
		
	public:
		long calculatorSalary(long);
		virtual void inputEmployeeInfo();
		virtual void showEmployeeInfo();
};

Employee::Employee() {
	
}

Employee::~Employee() {
	
}

Employee::Employee(string name, int age) {
	this->name = name;
	this->age = age;
}

class Officer: public Employee {
	private:
		long basicSalary;
		int workingDay;
		
	public:
		Officer officer();
		Officer officer(string, int);
		
	public:
		long calculatorSalary(long);
		void showEmployeeInfo();
		void inputEmployeeInfo();
};

class Worker: public Employee {
	private:
		int numOfProduct;
		int wageOfOneProduct;
		
	public:
		void showEmployeeInfo();
		void inputEmployeeInfo();
};

void Employee::showEmployeeInfo() {
	cout << "Ten: " << name << endl;
	cout << "Tuoi: " << age << endl;
}

void Employee::inputEmployeeInfo() {
	cout << "Nhap ten: ";
	cin >> name;
	cout << "Nhap tuoi: ";
	cin >> age;
}

long Officer::calculatorSalary(long money) {
	return money;
}

void Officer::inputEmployeeInfo() {
	Employee::inputEmployeeInfo();
	cout << "Nhap luonog co ban: ";
	cin >> basicSalary;
	cout << "Nhap so ngay lam viec: ";
	cin >> workingDay;
}

void Worker::inputEmployeeInfo() {
	Employee::inputEmployeeInfo();
	cout << "Nhap so san pham: ";
	cin >> numOfProduct;
	cout << "Nhap gia tien 1 san pham: ";
	cin >> wageOfOneProduct;
}

void Officer::showEmployeeInfo() {
	cout << "Thong tin nhan vien van phong: \n";
	Employee::showEmployeeInfo();
	cout << "Luong co ban: " << basicSalary << endl;
	cout << "So ngay lam viec: " << workingDay << endl;
}

void Worker::showEmployeeInfo() {
	cout << "Thong tin cong nhan: \n";
	Employee::showEmployeeInfo();
	cout << "So san pham: " << numOfProduct << endl;
	cout << "Gia tien 1 san pham: " << wageOfOneProduct << endl;
}

int main() {
	
	Employee *emp1;
	Employee *emp2;
	
	Officer officer;
	emp1 = &officer;
	
	Worker worker;
	emp2 = &worker;
	
	cout << "Nhap thong tin nhan vien van phong: \n";
	emp1->inputEmployeeInfo();
	cout << "Nhap thong tin cong nhan: \n";
	emp2->inputEmployeeInfo();
	
	cout << "=================\n";
	emp1->showEmployeeInfo();
	cout << "=================\n";
	emp2->showEmployeeInfo();
	
	
	return 0;
}










