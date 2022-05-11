#include <iostream>
using namespace std;

//De bai yeu cau khoi tao hai doi tuong cu the...

class Film {
	
	friend void priceCompare(Film, Film);
	
	private:
		string id;
		string name;
		float totalTime;
		float price;
		
		//contructors
	public:
		Film();
		Film(string, string, float, float);
		
		//getters (khong su dung)
	public:
		string getId() {
			return id;
		}
		
		string getName() {
			return name;
		}
		
		float getTotalTime() {
			return totalTime;
		}
		
		float getPrice() {
			return price;
		}
		
		//method
	public:
		void inputData();
		void showData();
		
};

Film::Film() {
	
}

void Film::inputData() {
	cout << "Nhap ma bo phim: ";
	getline(cin, id);
	cout << "Nhap ten phim: ";
	getline(cin, name);
	do {
		cout << "Nhap thoi luong phim: ";
		cin >> totalTime;
	} while (totalTime <= 0);
	
	do {
		cout << "Nhap gia ve: ";
		cin >> price;
	} while (price < 0);  // ==0 khi free :D
	
	cin.ignore();
}

void Film::showData() {
	cout << "ID: " << id << endl;
	cout << "Ten phim: " << name << endl;
	cout << "Thoi luong: " << totalTime << endl;
	cout << "Gia ve: " << price << endl;
}

void priceCompare(Film f1, Film f2) {
	if (f1.price < f2.price) {
		cout << "Gia ve thu nhat co gia thap hon " << (f2.price - f1.price) << " VND\n";
		f1.showData();
	} else if (f1.price > f2.price) {
		cout << "Gia ve thu hai co gia thap hon " << (f1.price - f2.price) << " VND\n";	
		f2.showData();
	} else {
		cout << "Hai bo phim co gia ve bang nhau...\n";
	}
}

int main() {
	
	Film film1;
	Film film2;
	
	cout << ">>>>>>>>>>>>>>>Nhap thong tin bo phim thu nhat <<<<<<<<<<<<< \n";
	film1.inputData();
	cout << ">>>>>>>>>>>>>>>Nhap thong tin bo phim thu hai <<<<<<<<<<<<< \n";
	film2.inputData();
	
	priceCompare(film1, film2);
	
	return 0;
}









