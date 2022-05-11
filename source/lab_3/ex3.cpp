#include <iostream>
using namespace std;

//De bai yeu cau nhap thong tin cuar hai doi tuong cu the

class Book {
	
	friend void pageCompare(Book, Book);
	
	private:
		string id;
		string publishCompany;
		int numOfPage;
		float price;
		
		//contructors
	public:
		Book();
		Book(string, string, int, float);
		
		//getters
	public:
		string getId() {
			return id;
		}
		
		string getpublishCompany() {
			return publishCompany;
		}
		
		int getNumOfPage() {
			return numOfPage;
		}
		
		float getPrice() {
			return price;
		}
		
		//methods
	public:
		void inputData();
		void showData();
};

Book::Book() {
	
}

void Book::inputData() {
	cout << "Nhap ma sach: ";
	getline(cin, id);
	cout << "Nhap nha xuat ban: ";
	getline(cin, publishCompany);
	do {
		cout << "Nhap so trang: ";
		cin >> numOfPage;
	} while (numOfPage <= 0);
	
	do {
		cout << "Gia tien: ";
		cin >> price;
	} while (price < 0);  // == 0 khi free
	
	cin.ignore();
}

void Book::showData() {
	cout << "ID: " << id << endl;
	cout << "Nha xuat ban: " << publishCompany << endl;
	cout << "So trang: " << numOfPage << endl;
	cout << "Gia tien: " << price << endl;
}

void pageCompare(Book b1, Book b2) {
	if (b1.numOfPage > b2.numOfPage) {
		cout << "Cuon sach thu nhat co so trang nhieu hon.\n";
		b1.showData();
	} else if (b1.numOfPage < b2.numOfPage) {
		cout << "Cuon sach thu hai co so trang nhieu hon.\n";
		b2.showData();
	} else {
		cout << "hai cuon sach co so trang bang nhau\n";
	}
}

int main() {
	
	Book book1;
	Book book2;
	
	cout << "Nhap thong tin cuon sach thu nhat: \n";
	book1.inputData();
	cout << "Nhap thong tin cuon sach thu hai: \n";
	book2.inputData();
	
	pageCompare(book1, book2);
	
	return 0;
}















