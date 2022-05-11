#include <iostream>
using namespace std;

class Shoe {
	
	friend void heightCompare(Shoe, Shoe);
	
	private:
		string brand;
		string material;
		float price;
		float height;
		
	public:
		Shoe();
		Shoe(string, string, float, float);
		
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
		
		float getHeight() {
			return height;
		}
		
	public:
		void inputData();
		void showData();
};

Shoe::Shoe() {
	
}

void Shoe::inputData() {
	cout << "Nhap ten thuong hieu: ";
	getline(cin, brand);
	cout << "Chat lieu: ";
	getline(cin, material);
	do {
		cout << "Gia tien: ";
		cin >> price;
	} while (price < 0);
	
	do {
		cout << "Chieu cao: ";
		cin >> height;
	} while (height <= 0);
	
	cin.ignore();
}

void Shoe::showData() {
	cout << "Thuong hieu: " << brand << endl;
	cout << "Chat lieu: " << material << endl;
	cout << "Gia tien: " << price << endl;
	cout << "Chieu cao: " << height << endl;
}

void heightCompare(Shoe s1, Shoe s2) {
	if (s1.height < s2.height) {
		cout << "Doi thu nhat co chieu cao nho hon.\n";
		s1.showData();
	} else if (s1.height > s2.height) {
		cout << "Doi thu hai co chieu cao nho hon.\n";
		s2.showData();
	} else {
		cout << "Hai doi giay co chieu cao bang nhau.\n";
	}
}

int main() {
	
	Shoe shoe1;
	Shoe shoe2;
	
	cout << "Nhap thong tin doi giay thu nhat: \n";
	shoe1.inputData();
	cout << "Nhap thong tin doi giay thu hai: \n";
	shoe2.inputData();
	
	heightCompare(shoe1, shoe2);
	
	return 0;
}













