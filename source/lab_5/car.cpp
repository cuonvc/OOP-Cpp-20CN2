#include <iostream>
using namespace std;

class Car {
	protected:
		string brand;
		int manufactureYear;  //nam san xuat
		int speed;
		
		//contructors
	public:
		Car();
		Car(string, int, int);
	
		//getters
	public:
		string getBrand() {
			return brand;
		}
		
		int getManufactureYear() {
			return manufactureYear;
		}
		
		int getSpeed() {
			return speed;
		}
		
		//methods
	public:
		void showData();
};

class Bus: private Car {
	
	friend void showDetailsList(Bus[], int);
	friend Bus *filterByBrand(Bus[], int, string);
	friend Bus *filterByYear(Bus[], int, int);
	friend Bus *filterMaxSeat(Bus[], int);
	
	private:
		string route; //tuyen duong
		int seat; //ghe ngoi toi da
		
	public:
		Bus();
		
	public:
		string getRoute() {
			return route;
		}
		
		int getSeat() {
			return seat;
		}
		
	public:
		Bus inputData();
		void showDataDetails();
};

Car::Car() {
	
}

Bus::Bus() {
	
}

Bus Bus::inputData() {
	Bus bus;
	
	cout << "Nhap thuong hieu: ";
	cin >> bus.brand;
	
	do {
		cout << "Nhap nam san xuat: ";
		cin >> bus.manufactureYear;
	} while (bus.manufactureYear <= 0);
	
	do {
		cout << "Nhap toc do: ";
		cin >> bus.speed;
	} while (bus.speed <= 0);
	
	cout << "Nhap tuyen xe: ";
	cin >> bus.route;
	
	do {
		cout << "NHap cho ngoi toi da: ";
		cin >> bus.seat;
	} while (bus.seat <= 0);
	
	return bus;
}

void Car::showData() {
	cout << "Thuong hieu: " << brand << endl;
	cout << "Nam san xuat: " << manufactureYear << endl;
	cout << "Toc do: " << speed << endl;
}

void Bus::showDataDetails() {
	Car::showData();
	cout << "Tuyen duong: " << route << endl;
	cout << "So cho ngoi toi da: " << seat << endl;
}

void showDetailsList(Bus array[], int len) {
	for (int i = 0; i < len; i++) {
		if (array[i].speed != 0) {
			cout << "-- Thong tin xe thu " << (i + 1) << ":\n";
			array[i].showDataDetails();
		}
	}
}

Bus *filterByBrand(Bus array[], int len, string value) {
	static Bus newArr[100];
	
	int count = 0;
	for (int i = 0; i < len; i++) {
		string val = array[i].brand;
		if (val.compare(value) == 0) {
			newArr[count] = array[i];
			count++;
		}
	} 
	
	return newArr;
}

Bus *filterByYear(Bus array[], int len, int value) {
	static Bus newArr[100];
	
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (array[i].manufactureYear == value) {
			newArr[count] = array[i];
			count++;
		}
	}
	
	return newArr;
}

Bus *filterMaxSeat(Bus array[], int len) {
	//sap xep giam dan
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (array[i].seat < array[j].seat) {
				Bus bus = array[i];
				array[i] = array[j];
				array[j] = bus;
			}
		}
	}
	
	int maxSeat = array[0].seat;
	static Bus newArray[100];

	int count = 0;
	for (int i = 0; i < len; i++) {
		
		if (array[i].seat == maxSeat) {
			newArray[count] = array[i];
			count++;
		}
	}
	
	return newArray;
}


int main() {
	
	int length;
	string brandSearch;
	int manuYear;
	
	do {
		cout << "Nhap vao so luong xe: ";
		cin >> length;
	} while (length <= 0);
	
	Bus arrayBus[length];
	
	for (int i = 0; i < length; i++) {
		Bus bus;
		cout << "Nhap thong tin xe thu " << (i + 1) << ":\n";
		arrayBus[i] = bus.inputData();
	}
	
	cout << "==================== Danh sach xe ====================\n";
	showDetailsList(arrayBus, length);
	
	cout << "Nhap thuong hieu can tim: ";
	cin >> brandSearch;
	
	cout << "================ Danh sach nhung xe co thuong hieu \'" << brandSearch << "\':\n";
	Bus *listByBrand = filterByBrand(arrayBus, length, brandSearch);
	showDetailsList(listByBrand, length);
	
	cout << "Nhap nam san xuat can tim: ";
	cin >> manuYear;
	
	cout << "================ Danh sach nhung xe co nam san xuat " << manuYear << ":\n";
	Bus *listByYear = filterByYear(arrayBus, length, manuYear);
	showDetailsList(listByYear, length);
	
	cout << "================ Danh sach nhung xe co so cho ngoi lon nhat ================\n" << ":\n";
	Bus *listMaxSeat = filterMaxSeat(arrayBus, length);
	showDetailsList(listMaxSeat, length);
	
	cout << "\nCoding by Cuong ne :D\n";
	return 0;
}









