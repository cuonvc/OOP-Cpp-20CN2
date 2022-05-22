#include <iostream>
using namespace std;

class Book {
	private:
		string id;
		string name;
		int numOfPage;
		string publishCompany;
	
	public:
		Book();
		Book(string);
		Book(string, string, int, string);
		~Book();
		
	public:
		string getId() {
			return id;
		}
		
		void setId(string newId) {
			id = newId;
		}
	
	public:
		Book dataInput();
		void showData();
		void filterBook(string, Book[], int);
};

Book::Book() {
	
}

Book::~Book() {
	
}

Book Book::dataInput() {
	Book book;
	
	cout << "Ma sach: ";
	cin >> book.id;
	cout << "Ten sach: ";
	cin >> book.name;
	do {
		cout << "So trang: ";
		cin >> book.numOfPage;
	} while (book.numOfPage < 10);
	cout << "Nha xuat ban: ";
	cin >> book.publishCompany;
	
//	Book book;
//	book.setId(id);
//	return Book(id, name, numOfPage, publishCompany);
	return book;
}

void Book::showData() {
	cout << "Ma sach: " << id << endl;
	cout << "Ten sach: " << name << endl;
	cout << "So trang: " << numOfPage << endl;
	cout << "Nha xuat ban: " << publishCompany << endl;
}

void Book::filterBook(string currentId, Book book[], int len) {
	int countNotMatch = 0;
	for (int i = 0; i < len; i++) {
//		if (book[i].id == currentId) {
//			cout << "->>>>> Thong tin cuon sach co ma \"" << currentId << "\" la: \n";
//			book[i].showData();
//		} else {
//			count++;
//		}
		if (book[i].id != currentId) {
			countNotMatch++;
		} else {
			cout << "->>>>> Thong tin cuon sach co ma \"" << currentId << "\" la: \n";
			book[i].showData();
		}
	}
	
	if (countNotMatch == len) {
		cout << "->>>>> Khong tim thay thong tin cuon sach co ma \"" << currentId << "\" :(((((";
	}
}

int main() {
	
	int length;
	string currentId;
	Book mainBook;
	
	do {
		cout << "Nhap so cuon sach: ";
		cin >> length;
	} while (length <= 0);
	
	Book arrayBooks[length];  //mang cac doi tuong co kieu du lieu la mot Oj
	
	cout << ">>>>>>>>>>>>>>>>> Nhap vao thong tin nhung cuon sach <<<<<<<<<<<<<<<<<<<\n";
	for (int i = 0; i < length; i++) {
		Book book;
		cout << "Nhap thong tin cuon sach thu " << i + 1 << ":\n";
		book.dataInput();
	}
	
	cout << ">>>>>>>>>>>>>>>>> Thong tin nhung cuon sach vua nhap <<<<<<<<<<<<<<<<<<<\n";
	for (int i = 0; i < length; i++) {
		arrayBooks[i] = arrayBooks[i].showData();
		cout << "----------------\n";
	}
	
	cout << "Nhap ma sach can tim: ";
	cin >> currentId;
	
	cout << "... ... ... ... ...\n";
//	cout << "->>>>> Thong tin cuon sach co ma \"" << currentId << "\" la: \n";
	mainBook.filterBook(currentId, arrayBooks, length);
	
	return 0;
}
