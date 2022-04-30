#include <iostream>
using namespace std;

class Car {
	
	private:
		string idCar;
		string brand;
		int manufactureYear;
		int maxSpeed;
		long price;
		
	public:
		Car();
		Car(string, string, int, int, long);
		
	public:
		string getId() {
			return idCar;
		}
		
		string getBrand() {
			return brand;
		}
		
		int getManufactureYear() {
			return manufactureYear;
		}
		
		int getMaxSpeed() {
			return maxSpeed;
		}
		
		long getPrice() {
			return price;
		}
		
	public:
		void inputData();
		void showData();
		long totalPrice(long);
};

Car::Car() {
	
}

Car::Car(string maXe, string thuongHieu, int namSX, int Vmax, long giaXe) {
	idCar = maXe;
	brand = thuongHieu;
	manufactureYear = namSX;
	maxSpeed = Vmax;
	price = giaXe;
}

void Car::inputData() {
	cout << "Ma xe: ";
	cin >> idCar;
	cout << "Thuong hieu: ";
	cin >> brand;
	do {
		cout << "Nam san xuat: ";
		cin >> manufactureYear;
	} while (manufactureYear <= 1800);
	
	do {
		cout << "Van toc toi da: ";
		cin >> maxSpeed;
	} while (maxSpeed <= 0);
	
	cout << "Gia xe: ";
	cin >> price;
}

void Car::showData() {
	cout << "Ma xe: " << idCar << endl;
	cout << "Thuong hieu: " << brand << endl;
	cout << "Nam san xuat: " << manufactureYear << endl;
	cout << "Van toc toi da: " << maxSpeed << endl;
	cout << "Gia xe: " << price << endl;
	cout << "Gia xe sau VAT: " << totalPrice(price) << endl;
}

long Car::totalPrice(long pr) {
	return pr + (pr * 0.1);
}

int main() {
	
	Car car;
	
	cout << "Nhap thong tin xe...\n";
	car.inputData();
	cout << "==========================\n";
	cout << "Thong tin cua xe: \n";
	car.showData();
	
	return 0;
}
