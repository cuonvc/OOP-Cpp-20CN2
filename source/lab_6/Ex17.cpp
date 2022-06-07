#include <iostream>
using namespace std;

class Employee {
	protected:
		string fullName;
		string address;
		int yearOfBirth;
		string unit;  //don vi
		
	public:
		Employee();
		
	public:
		virtual long salaryCalculate(long, int);
		virtual void inputData();
		virtual void showData();
		virtual ~Employee();
};

Employee::Employee() {
	
}

Employee::~Employee() {
	
}
//
long Employee::salaryCalculate(long x, int y) {
	return 0;
}

void Employee::inputData() {
	cout << "Nhap ho va ten: ";
	cin >> fullName;
	cout << "Nhap dia chi: ";
	cin >> address;
	cout << "Nhap nam sinh: ";
	cin >> yearOfBirth;
	cout << "Nhap don vi lam viec: ";
	cin >> unit;
}

void Employee::showData() {
	cout << "Ho ten: " << fullName << endl;
	cout << "Dia chi: " << address << endl;
	cout << "Nam sinh: " << yearOfBirth << endl;
	cout << "Don vi lam viec: " << unit << endl;
}

class Worker : public Employee {
	private:
		long salary;
		int workingDay;
		
	public:
		long getSalary() {
			return salary;
		}
		
		int getWorkingDay() {
			return workingDay;
		}
		
		~Worker();
		
	public:
		long salaryCalculate(long, int);
		void inputData();
		void showData();
};

Worker::~Worker() {
	
}

long Worker::salaryCalculate(long baseSalary, int workingDay) {
	return (baseSalary * workingDay) / 26;
}

void Worker::inputData() {
	Employee::inputData();
	cout << "Nhap luong cong nhan: ";
	cin >> salary;
	do {
		cout << "Nhap so ngay lam viec: ";
		cin >> workingDay;
	} while (workingDay > 26);
}

void Worker::showData() {
	Employee::showData();
	cout << "Luong cong nhan: " << salary << endl;
	cout << "So ngay lam viec: " << workingDay << endl;
}

class Manager : public Employee {
	private:
		string position;
		float coefficient; //he so luong  (search google thi ra no la mot so float)
		long bonus;
		
	public:
		float getCoefficient() {
			return coefficient;
		}
		
		long getBonus() {
			return bonus;
		}
		
		~Manager();
		
	public:
		long salaryCalculate(float, long);
		void inputData();
		void showData();
};

void Manager::inputData() {
	Employee::inputData();
	cout << "Nhap chuc vu: ";
	cin >> position;
	cout << "Nhap he so luong: ";
	cin >> coefficient;
	cout << "Nhap tro cap: ";
	cin >> bonus;
}

void Manager::showData() {
	Employee::showData();
	cout << "Chuc vu: " << position << endl;
	cout << "He so luong: " << coefficient << endl;
	cout << "Tro cap: " << bonus << endl;
}

Manager::~Manager() {

}

//??
long Manager::salaryCalculate(float coefficient, long bonus) {
	return (coefficient * 440000 + bonus);
}


int main() {	

	Employee *emp1;
	Employee *emp2;
	
	Worker worker;
	emp1 = &worker;
	
	Manager manager;
	emp2 = &manager;
	
	cout << "Nhap thong tin cong nhan: \n";
	emp1->inputData();
	cout << "Nhap thong tin quan ly: \n";
	emp2->inputData();
	
	cout << "========== Thong tin cong nhan ============\n";
	emp1->showData();
	cout << "========== Thong tin quan ly ===========\n";
	emp2->showData();
	
	
	long salaryWorker = emp1->salaryCalculate(worker.getSalary(), worker.getWorkingDay());
	long salaryManager = emp2->salaryCalculate(manager.getCoefficient(), manager.getBonus());
	cout << "=========================\n";
	cout << "Luong thuc nhan: \n";
	cout << "Cong nhan: " << salaryWorker << endl;;
	cout << "Quan ly: " << salaryManager << endl;
	
	return 0;
}














