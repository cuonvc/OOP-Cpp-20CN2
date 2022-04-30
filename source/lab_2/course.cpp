#include <iostream>
#include <math.h>
using namespace std;

class Course {
	
	//properties
	private:
		string id;
		string name;
		float totalTime;
		long price;
		
	//contructors
	public:
		Course();
		Course(string, string, float, long);
		
	//getters
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
		
		long getPrice() {
			return price;
		}
		
	//methods
	public:
		void inputData();
		void showData();
		long total(long);
		void priceCompare(long, long);
};

Course::Course() {
	
}

Course::Course(string ma, string ten, float thoiGian, long gia) {
	id = ma;
	name = ten;
	totalTime = thoiGian;
	price = gia;
}

void Course::inputData() {
	cout << "Nhap thong tin khoa hoc: \n";
	cout << "Ma khoa hoc: \n";
	cin >> id;
	cout << "Ten khoa hoc: \n";
	cin >> name;
	do {
		cout << "Thoi luong hoc: \n";
		cin >> totalTime;
	} while (totalTime <= 0);
	
	do {
		cout << "Gia khoa hoc: \n";
		cin >> price;
	} while (price <= 0);
}

long Course::total(long price) {
	return price + (price * 0.1);
}

void Course::priceCompare(long price1, long price2) {
	if (price1 > price2) {
		cout << "Khoa hoc 1 gia cao hon khoa hoc 2 la: " << (price1 - price2) << " VND.";
	} else if (price1 == price2) {
		cout << "Gia hai khoa hoc deu bang: " << price1 << " VND.";
	} else {
		cout << "Khoa hoc 1 gia thap hon khoa hoc 2 la: " << (price2 - price1) << " VND.";
	}
}

void Course::showData() {
	cout << "==========================\n";
	cout << "Ma khoa hoc: " << id << endl;
	cout << "Ten khoa hoc: " << name << endl;
	cout << "Thoi luong: " << totalTime << endl;
	cout << "Gia khoa hoc: " << price << endl;
	cout << "Gia khoa hoc sau thue: " << total(price) << endl;
}



int main() {
	
	Course course1;
	Course course2;
	Course course;
	
	cout << "Khoa hoc thu nhat: \n";
	course1.inputData();
	cout << "Khoa hoc thu hai: \n";
	course2.inputData();
	
	cout << "--------------------------------------\n";
	cout << ">>>>>> Thong tin khoa hoc thu nhat: \n";
	course1.showData();
	cout << ">>>>>> Thong tin khoa hoc thu hai: \n";
	course2.showData();
	
	long coursePrice1 = course1.getPrice();
	long coursePrice2 = course2.getPrice();
	
	cout << "\nKet luan: \n";
	course.priceCompare(coursePrice1, coursePrice2);
	
	
	
	
	
	return 0;
}
