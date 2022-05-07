#include <iostream>
using namespace std;

class Shoe {
	
	private:
		string id;
		string brand;
		string material;
		float height;
		float price;
		
	public:
		Shoe();
		Shoe(string, string, string, float, float);
		
	public:
		string getId() {
			return id;
		}
		
		string getBrand() {
			return brand;
		}
		
		string getMaterial() {
			return material;
		}
		
		float getHeight() {
			return height;
		}
		
		float getPrice() {
			return price;
		}
		
	public:
		void inputData();
		void showData();
		float totalPrice(float);
		void compareHeight(float, float);
};

Shoe::Shoe() {
	
}

Shoe::Shoe(string maSP, string thuongHieu, string chatLieu, float chieuCao, float gia) {
	id = maSP;
	brand = thuongHieu;
	material = chatLieu;
	height = chieuCao;
	price = gia;
}

void Shoe::inputData() {
	cout << "Nhap ma san pham: ";
	cin >> id;
	cout << "Thuong hieu: ";
	cin >> brand;
	cout << "Chat lieu: ";
	cin >> material;
	do {
		cout << "Chieu cao de: ";
		cin >> height;
	} while (height <= 0);
	
	do {
		cout << "Gia san pham: ";
		cin >> price;
	} while (height < 0);
}

void Shoe::showData() {
	cout << "Ma san pham: " << id << endl;
	cout << "Thuong hieu: " << brand << endl;
	cout << "Chat lieu: " << material << endl;
	cout << "Chieu cao: " << height << "mm." << endl;
	cout << "Gia san pham: " << price << " VND" << endl;
	cout << "Gia san pham sau VAT: " << totalPrice(price) << " VND" << endl;
}
float Shoe::totalPrice(float p) {
	return p + p * 0.1;
}

void Shoe::compareHeight(float h1, float h2) {
	if (h1 > h2) {
		cout << "San pham thu nhat co chieu cao lon hon: " << (h1 - h2) << "mm.";
	} else if (h1 < h2) {
		cout << "San pham thu nhat co chieu cao nho hon: " << (h2 - h1) << "mm.";
	} else {
		cout << "Hai san pham co chieu cao bang nhau.";
	}
}

int main() {
	
	Shoe shoe;
	Shoe shoe1;
	Shoe shoe2;
	
	cout << "=====================================\n";
	cout << "Nhap thong tin San pham thu nhat: \n";
	shoe1.inputData();
	cout << "Nhap thong tin san pham thu hai: \n";
	shoe2.inputData();
	
	cout << "===============================\n";
	cout << "Thong tin san pham thu nhat: \n";
	shoe1.showData();
	cout << "===============================\n";
	cout << "Thong tin san pham thu hai: \n";
	shoe2.showData();
	
	float height1 = shoe1.getHeight();
	float height2 = shoe2.getHeight();
	
	cout << "\nSo sanh ket qua: \n";
	shoe.compareHeight(height1, height2);
	return 0;
}
