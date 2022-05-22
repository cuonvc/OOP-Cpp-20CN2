#include <iostream>
using namespace std;

class Card {
	
	friend void showList(Card[], int);
	friend void checkNgayTra(Card[], int, string);
	
	private:
		static int count;
		int idCard;
		string ngayMuon; 
		string ngayTra; 
		int idBook;
		
	public:
		Card();
		
	public:
		void static idAscending() {
			count++;
		}
		Card inputData();
		void showData();
};

Card::Card() {
	
}

int Card::count = 1;

Card Card::inputData() {
	
	Card card;
	card.idCard = count;
	idAscending();
	
	cout << "Nhap ngay muon: ";
	cin >> card.ngayMuon;
	cout << "Ngay tra: ";
	cin >> card.ngayTra;
	cout << "Ma sach: ";
	cin >> card.idBook;
	
	return card;
}

void Card::showData() {
	cout << "Ma the: " << idCard << endl;
	cout << "Ngay muon: " << ngayMuon << endl;
	cout << "Ngay tra: " << ngayTra << endl;
	cout << "Ma sach: " << idBook << endl;
}

void showList(Card array[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Thong tin the thu " << (i + 1) << ":\n";
		array[i].showData();
	}
}

void checkNgayTra(Card array[], int len, string dayInput) {
	for (int i = 0; i < len; i++) {
		if (array[i].ngayTra.compare(dayInput) == 0) {
			cout << "========================\n";
			array[i].showData();
		}
	}
}

int main() {
	
	int length;
	string dayInput = "";
	
	do {
		cout << "Nhap so the: ";
		cin >> length;
	} while (length < 1);
	
	Card arrayCard[length];
	
	for (int i = 0; i < length; i++) {
		Card card;
		cout << "Nhap thong tin the thu " << (i + 1) << ":\n";
		arrayCard[i] = card.inputData();
	}
	
	cout << ">>>>>>>>>>> Danh sach the <<<<<<<<<<<\n";
	showList(arrayCard, length);
	
	cout << "Nhap ngay den han tra: ";
	cin >> dayInput;
	
	cout << ">>>>>>>>> Danh sach nhung the den ngay " << dayInput << " can tra la:\n";
	checkNgayTra(arrayCard, length, dayInput);
	
	
	return 0;
}





