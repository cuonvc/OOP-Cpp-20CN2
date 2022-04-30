#include <iostream>
#include <math.h>
using namespace std;

class Employee {
	//prototies
	private:
		string fullName;
		string address;
		string idCard;
		string idEmployee;
		long basicSalary;
		float factorSalary;  //he so luong
		long bonus;
		
	//contructors
	public:
		Employee();
		Employee(string, string, string, 
				string, long, float, long);
				
	//methods
	public:
		void inputEmployee();
		void showEmployee();
		long totalSalary(long, float, long);
};

Employee::Employee() {
	
}

void Employee::inputEmployee() {
	cout << "Nhap thong tin nhan vien: \n";
	cout << "Ho va ten: \n";
	cin >> fullName;
	cout << "Dia chi: \n";
	cin >> address;
	cout << "So CMND: \n";
	cin >> idCard;
	cout << "Ma nhan vien: \n";
	cin >> idEmployee;
	do {
		cout << "Luong co ban: \n";
		cin >> basicSalary;
	} while (basicSalary <= 0);
	
	do {
		cout << "He so luong: \n";
		cin >> factorSalary;
	} while (factorSalary <= 0);
	
	do {
		cout << "Phu cap: \n";
		cin >> bonus;
	} while (bonus < 0);
}

long Employee::totalSalary(long basic, float factor, long bonus) {
	return (basic * factor + bonus);
}

void Employee::showEmployee() {
	cout << "==========================\n";
	cout << "Thong tin nhan vien: \n";
	cout << "Ho va ten: " << fullName << endl;
	cout << "Dia chi: " << address << endl;
	cout << "So CMND: " << idCard << endl;
	cout << "Ma nhan vien: " << idEmployee << endl;
	cout << "Luong co ban: " << basicSalary << endl;
	cout << "He so luong: " << factorSalary << endl;
	cout << "Phu cap: " << bonus << endl;
	cout << "Tong thu nhap: " << totalSalary(basicSalary, factorSalary, bonus) << endl;
}

int main() {
	
	Employee Emp;
	Emp.inputEmployee();
	Emp.showEmployee();
	
	return 0;
}
