#include <iostream>
using namespace std;

class Table {
	
	friend bool materialCompare(Table, Table);
	
	private:
		string brand;
		string material;
		float price;
		
	public:
		Table();
		Table(string, string, float);
		
	public:
		
		string getBrand() {
			return brand;
		}
		
		string getMaterial() {
			return material;
		}
		
		float getPrice() {
			return price;
		}
		
	public:
		void inputData();
		void showData();
};

Table::Table() {
	
}

void Table::inputData() {
	cout << "Nhap ten thuong hieu: ";
	getline(cin, brand);
	cout << "Chat lieu: ";
	getline(cin, material);
	cout << "Gia tien: ";
	cin >> price;
	
	cin.ignore();
}

void Table::showData() {
	cout << "Thuong hieu: " << brand << endl;
	cout << "Chat lieu: " << material << endl;
	cout << "Gia tien: " << price << endl;
}

bool materialCompare(Table t1, Table t2) {
	string m1 = t1.material;
	string m2 = t2.material;
	if (m1.compare(m2) == 0) {
		return true;
	} else {
		return false;
	}
}

int main() {
	
	Table table1;
	Table table2;
	
	cout << "Nhap thong tin ban thu nhat: \n";
	table1.inputData();
	cout << "Nhap thong tin ban thu hai: \n";
	table2.inputData();
	
	cout << "Thong tin ban thu nhat: \n";
	table1.showData();
	cout << "Thong tin ban thu hai: \n";
	table2.showData();
	
	bool resultEqual = materialCompare(table1, table2);
	
	if(resultEqual) {
		cout << "Hai ban co chat lieu giong nhau\n";
	} else {
		cout << "Hai ban co chat lieu khac nhau\n";
	}
	
	return 0;
}









