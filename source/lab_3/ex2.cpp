#include <iostream>
using namespace std;

//De bai yeu cau khoi tao hai doi tuong cu the

class Car {
	
	friend void speedCompare(Car, Car);
	
	private:
		string brand;
		int manufactureYear;
		float speed;
		int numOfSeat;  //so cho ngoi
		
		//contructors
	public:
		Car();
		Car(string, int, float, int);
		
		//getters (khong su dung)
	public:
		string getBrand() {
			return brand;
		}
		
		int getManufactureYear() {
			return manufactureYear;
		}
		
		float getSpeed() {
			return speed;
		}
		
		int getSeat() {
			return numOfSeat;
		}
		
		//methods
	public:
		void inputData();
		void showData();
};

Car::Car() {
	
}

void Car::inputData() {
	cout << "Nhap ten thuong hieu: ";
	getline(cin, brand);
	do {
		cout << "Nhap nam san xuat: ";
		cin >> manufactureYear;
	} while (manufactureYear < 1900);
	
	do {
		cout << "Toc do dat duoc: ";
		cin >> speed;
	} while (speed <= 0);
	
	do {
		cout << "So ghe ngoi: ";
		cin >> numOfSeat;
	} while (numOfSeat < 2);
	
	cin.ignore();
}

void Car::showData() {
	cout << "Thuong hieu: " << brand << endl;
	cout << "Nam san xuat: " << manufactureYear << endl;
	cout << "Toc do: " << speed << endl;
	cout << "So ghe ngoi: " << numOfSeat << endl;
}

void speedCompare(Car c1, Car c2) {
	if (c1.speed < c2.speed) {
		cout << "Xe thu nhat cho toc do nho hon " << (c2.speed - c1.speed) << "Km/h\n";
		c1.showData();
	} else if (c1.speed > c2.speed) {
		cout << "Xe thu hai cho toc do nho hon " << (c1.speed - c2.speed) << "Km/h\n";
		c2.showData();
	} else {
		cout << "Hai xe co toc do bang nhau va bang: " << c1.speed << "Km/h\n";
	}
}


int main() {
	
	Car car1;
	Car car2;
	
	cout << ">>>>>>>>>> Nhap thong tin cho xe thu nhat <<<<<<<<<<<\n";
	car1.inputData();
	cout << ">>>>>>>>>> Nhap thong tin cho xe thu hai <<<<<<<<<<<\n";
	car2.inputData();
	
	speedCompare(car1, car2);
	
	return 0;
}
