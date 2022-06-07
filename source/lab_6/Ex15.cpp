#include <iostream>
using namespace std;

class Cay {
	protected:
		float height;
		int age;
		float circum;
		
	public:
		Cay();
		
	public:
		virtual void inputData();
		virtual void showData();
};

Cay::Cay() {
	
}

//implement chinh no
void Cay::inputData() {
	cout << "Nhap chieu cao: ";
	cin >> height;
	cout << "Nhap tuoi cay: ";
	cin >> age;
	cout << "Nhap chu vi: ";
	cin >> circum;
}

//implement chinh no
void Cay::showData() {
	cout << "Chieu cao: " << height << endl;
	cout << "Tuoi: " << age << endl;
	cout << "Chu vi: " << circum << endl;
}

class CayCanh : public Cay {
	private:
		long price;  //gia
		string species;  //chung loai
		
	public:
		void inputData();
		void showData();
};

//Override tu Cay class
void CayCanh::inputData() {
	Cay::inputData();
	cout << "Gia thanh: ";
	cin >> price;
	cout << "Chung loai: ";
	cin >> species;
}

//Override tu Cay class
void CayCanh::showData() {
	Cay::showData();
	cout << "Gia thanh: " << price << endl;
	cout << "Chung loai: " << species << endl;
}

int main() {
	
	Cay *cayPointer;
	
	Cay cay;
	CayCanh cayCanh;
	
	cayPointer = &cayCanh;
	
	//chi co mot con tro nen khong the thuc thi ca hai doi tuong (chac the :D)
	
	cout << "Nhap thong tin cay: \n";
	cay.inputData();
	cout << "Nhap thong tin cay canh: \n";
	cayPointer->inputData();
	
	cout << "========== Thong tin cay ==========\n";
	cay.showData();
	cout << "========== Thong tin cay canh ==========\n";
	cayPointer->showData();
	
	return 0;
}














