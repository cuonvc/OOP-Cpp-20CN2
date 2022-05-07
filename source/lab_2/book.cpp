#include <iostream>
using namespace std;

class Book {
	
	private:
		string idBook;
		string publishCompany;
		int numberOfPage;
		float price;
		
	public:
		Book();
		Book(string, string, int, float);
		
	public:
		string getId() {
			return idBook;
		}
		
		string getPublish() {
			return publishCompany;
		}
		
		int getPage() {
			return numberOfPage;
		}
		
		float getPrice() {
			return price;
		}
		
	public:
		void inputData();
		void outputData();
		float totalPrice(float);
};

Book::Book() {
	
}

Book::Book(string maSach, string nhaXB, int soTrang, float giaTien) {
	idBook = maSach;
	publishCompany = nhaXB;
	numberOfPage = soTrang;
	price = giaTien;
}

void Book::inputData() {
	cout << "Nhap ma sach: ";
	cin >> idBook;
	cout << "Nha xuat ban: ";
	cin >> publishCompany;
	do {
		cout << "So trang: ";
		cin >> numberOfPage;
	} while (numberOfPage <= 10);
	
	do {
		cout << "Gia tien: ";
		cin >> price;
	} while (price < 0);
}

void Book::outputData() {
	cout << "Ma sach: " << idBook << endl;
	cout << "Nha xuat ban: " << publishCompany << endl;
	cout << "So trang: " << numberOfPage << endl;
	cout << "Gia tien: " << price << " VND" << endl;
	cout << "Gia tien sau thue VAT: " << totalPrice(price) << " VND";
}

float Book::totalPrice(float p) {
	return p + (p * 0.1);
}

int main () {
	
	Book book;
	
	cout << "Nhap thong tin sach: \n";
	book.inputData();
	cout << "========================\n";
	cout << "Thong tin sach: \n";
	book.outputData();
	
	return 0;
}
