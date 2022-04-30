#include <iostream>
#include <math.h>
using namespace std;

class Bicycle {
	
	private:
		string id;
		string brand;
		string type;
		int manufactureDate;
		string manufactureFactory;
		long price;
		
	public:
		Bicycle();
	
	public:
		void inputData();
		void showData();
		long total(long);
};

Bicycle::Bicycle() {
	
}

void Bicycle::inputData() {
	cout << "Nhap thong tin xe dap: \n";
	cout << "Ma xe dap: \n";
	cin >> id;
	cout << "Thuong hieu: \n";
	cin >> brand;
	cout << "Loai xe: \n";
	cin >> type;
	do {
		cout << "Nam san xuat: \n";
		cin >> manufactureDate;
	} while (manufactureDate <= 1000);
	
	cout << "Xuong san xuat: \n";
	cin >> manufactureFactory;
	do {
		cout << "Gia xuat xuong: \n";
		cin >> price;
	} while (price <= 0);
}

long Bicycle::total(long price) {
	return price + (price * 0.1);
}



void Bicycle::showData() {
	cout << "==========================\n";
	cout << "Thong tin xe dap: \n";
	cout << "Ma xe dap: " << id << endl;
	cout << "Thuong hieu: " << brand << endl;
	cout << "Loai xe: " << type << endl;
	cout << "Nam san xuat: " << manufactureDate << endl;
	cout << "Xuong san xuat: " << manufactureFactory << endl;
	cout << "Gia xuat xuong: " << price << endl;
	cout << "Gia sau thue: " << total(price) << endl;
}

int main() {
	
	Bicycle bicycle;
	bicycle.inputData();
	bicycle.showData();
	
}
