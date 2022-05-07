#include <iostream>
using namespace std;

class MusicInstrument {
	
	private:
		string id;
		string brand;
		string type;
		float price;
		
	public:
		MusicInstrument();
		MusicInstrument(string, string, string, float);
		
	public:
		string getId() {
			return id;
		}
		
		string getBrand() {
			return brand;
		}
		
		string getType() {
			return type;
		}
		
		float getPrice() {
			return price;
		}
		
	public:
		void inputData();
		void showData();
		float totalPrice(float);
		void comparePrice(float, float);
};

MusicInstrument::MusicInstrument() {
	
}

MusicInstrument::MusicInstrument(string maSP, string thuongHieu, string loai, float gia) {
	id = maSP;
	brand = thuongHieu;
	type = loai;
	price = gia;
}

void MusicInstrument::inputData() {
	cout << "Nhap ma san pham: ";
	cin >> id;
	cout << "Thuong hieu: ";
	cin >> brand;
	cout << "Loai san pham: ";
	cin >> type;
	cout << "Gia san pham: ";
	cin >> price;
}

void MusicInstrument::showData() {
	cout << "Ma san pham: " << id << endl;
	cout << "Thuong hieu: " << brand << endl;
	cout << "Loai san pham: " << type << endl;
	cout << "Gia san pham: " << price << " VND" << endl;
	cout << "Gia san pham sau VAT: " << totalPrice(price) << " VND" << endl;
	
}

float MusicInstrument::totalPrice(float p) {
	return p + p * 0.1;
}

void MusicInstrument::comparePrice(float price1, float price2) {
	if (price1 > price2) {
		cout << "San pham thu nhat cao hon: " << (price1 - price2) << " VND." << endl;
	} else if(price1 < price2) {
		cout << "San pham thu nhat thap hon: " << (price2 - price1) << " VND." << endl;
	} else {
		cout << "Hai san pham co gia tien bang nhau";
	}
}

int main() {
	
	MusicInstrument musicInstrument;
	MusicInstrument musicInstrument1;
	MusicInstrument musicInstrument2;
	
	cout << "Nhap thong tin san pham thu nhat: \n";
	musicInstrument1.inputData();
	cout << "Nhap thong tin san pham thu hai: \n";
	musicInstrument2.inputData();
	
	cout << "=================================\n";
	cout << "Thong tin san pham thu nhat: \n";
	musicInstrument1.showData();
	cout << "=================================\n";
	cout << "Thong tin san pham thu hai: \n";
	musicInstrument2.showData();
	
	float price1 = musicInstrument1.getPrice();
	float price2 = musicInstrument2.getPrice();
	
	cout << "=========================\n";
	cout << "So sanh hai san pham: \n";
	musicInstrument.comparePrice(price1, price2);
	
	
	
	
	return 0;
}
