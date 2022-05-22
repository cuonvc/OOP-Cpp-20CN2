#include <iostream>
using namespace std;
class Shoe {
	
	friend Shoe heightCompare(Shoe[], int);
	
	private:
		static int count;
		int id;
		string brand;
		string material;
		int height;
		float price;
		
	public:
		Shoe();
		Shoe(int, string, string, int, float);
		
	public:
		int getId() {
			return id;
		}
		
		string getBrand() {
			return brand;
		}
		
		string getMaterial() {
			return material;
		}
		
		int getHeight() {
			return height;
		}
		
		float getPrice() {
			return price;
		}
		
	public:
		static void idAscending() {
			count++;
		}
		
		Shoe inputData();
		void showData();
};

Shoe::Shoe() {
	
}

int Shoe::count = 1;

Shoe Shoe::inputData() {
	
	Shoe shoe;
	
	shoe.id = count;
	idAscending();
	
	cout << "Nhap ten thuong hieu: ";
	cin >> shoe.brand;
	cout << "Nhap chat lieu: ";
	cin >> shoe.material;
	do {
		cout << "Nhap chieu cao: ";
		cin >> shoe.height;
	} while (shoe.height <= 0);
	
	do {
		cout << "Nhap gia tien: ";
		cin >> shoe.price;
	} while (shoe.price < 0);
	
	return shoe;
}

void Shoe::showData() {
	cout << "ID: " << id << endl;
	cout << "Thuong hieu: " << brand << endl;
	cout << "Chat lieu san pham: " << material << endl;
	cout << "Chieu cao: " << height << endl;
	cout << "Gia tien: " << price << endl;
}

Shoe heightCompare(Shoe shoe[], int len) {
	int maxHeight = 0;
	for (int i = 0; i < len; i++) {
		if (shoe[i].height > maxHeight) {
			maxHeight = shoe[i].height;
		}
	}
	
	for (int i = 0; i < len; i++) {
		if (shoe[i].height == maxHeight) {
			return shoe[i];
		}
	}
}

int main() {
	
	int length;
	
	cout << "Nhap so luong giay: ";
	cin >> length;
	
	Shoe arrayShoe[length];
	
	for (int i = 0; i < length; i++) {
		Shoe shoe;
		cout << "Nhap thong tin doi giay thu " << (i + 1) << endl;
		arrayShoe[i] = shoe.inputData();
	}
	
	Shoe result = heightCompare(arrayShoe, length);
	cout << "Doi giay co chieu cao cao nhat la: \n";
	result.showData();
	
	return 0;
	
}













