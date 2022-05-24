#include <iostream>
#include<algorithm>
using namespace std;

class Bike {
	protected:
		int id;
		string brand;
		int manufactureYear;  //nam san xuat
		
		//contructors
	public:
		Bike();
		Bike(int, string, int);
		
		//getters
	public:
		int getId() {
			return id;
		}
		
		string getBrand() {
			return brand;
		}
		
		int getManufactureYear() {
			return manufactureYear;
		}
		
		//methods
	public:
		void showData();
	
};

Bike::Bike() {
	
}

void Bike::showData() {
	cout << "Ma xe: " << id << endl;
	cout << "Ten thuong hieu: " << brand << endl;
	cout << "Nam san xuat: " << manufactureYear << endl;
}

class EBike: private Bike {
	
	friend void showDetailsList(EBike[], int);
	friend EBike *filterByBrand(EBike[], int, string);
	friend EBike *filterBySpeed(EBike[], int, int);
	friend EBike *filterByMax(EBike[], int);
	
	private:
		int speed;
		
		//contructors
	public:
		EBike();
		
		//getters
	public:
		int getSpeed() {
			return speed;
		}
		
		//methods
	public:
		EBike inputDetailsData();
		void showDetails();
		
};

EBike::EBike() {
	
}

EBike EBike::inputDetailsData() {
	EBike eBike;
	
	do {
		cout << "Nhap ma xe: ";
		cin >> eBike.id;
	} while (eBike.id <= 0);
	
	cout << "Nhap ten thuong hieu: ";
	cin >> eBike.brand;
	
	do {
		cout << "Nhap nam san xuat: ";
		cin >> eBike.manufactureYear;
	} while (eBike.manufactureYear <= 0);
	
	do {
		cout << "Nhap toc do: ";
		cin >> eBike.speed;
	} while (eBike.speed <= 0);
	
	return eBike;
} 

void EBike::showDetails() {
	Bike::showData();
	cout << "Toc do: " << speed << endl;
}

void showDetailsList(EBike array[], int num) {
	for (int i = 0; i < num; i++) {
		if (array[i].id != 0) {  //de phuc vu cho ham filter, neu khong co "if" thi ham filter se hien thi ra nhung xe co value == 0
			cout << "-- Xe thu " << (i + 1) << ":\n";
			array[i].showDetails();
		}
	}
}

//void filterByBrand(EBike array[], int num, string value) {
//	for (int i = 0; i < num; i++) {
//		
//		string val = array[i].brand;
//		
//		if (val.compare(value) == 0) {
//			array[i].showDetails();
//			cout << "===================\n";
//		}
//	}
//}

EBike *filterByBrand(EBike array[], int num, string value) {
	
	static EBike newArray[100];  //length có the nho hon hoac bang num
	int count = 0;
	
	for (int i = 0; i < num; i++) {
		
		string val = array[i].brand;
		
		if (val.compare(value) == 0) {
			newArray[count] = array[i];
			count++;
		}
	}
	
	return newArray;
}

EBike *filterBySpeed(EBike array[], int num, int value) {
	static EBike newArray[100];  
	int count = 0;
	
	for (int i = 0; i < num; i++) {
		
		if (array[i].speed == value) {
			newArray[count] = array[i];
			count++;
		}
	}
	
	return newArray;
}


EBike *filterByMax(EBike array[], int num) {
	//sap xep giam dan
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			if (array[i].speed < array[j].speed) {
				EBike bike = array[i];
				array[i] = array[j];
				array[j] = bike;
			}
		}
	}
	
	int maxSpeed = array[0].speed;
	static EBike newArray[100];

	int count = 0;
	for (int i = 0; i < num; i++) {
		
		if (array[i].speed == maxSpeed) {
			newArray[count] = array[i];
			count++;
		}
	}
	
	return newArray;
}



int main() {
	
	int number;
	string brandSearch;
	int speedSearch;
	
	do {
		cout << "Nhap vao so luong xe: ";
		cin >> number;
	} while (number <= 0);
	
	EBike arrayEBike[number];
	
	for (int i = 0; i < number; i++) {
		EBike eBike;
		cout << "Nhap thong tin xe thu " << (i + 1) << endl;
		arrayEBike[i] = eBike.inputDetailsData();
	}
	
	cout << "=================== Danh sach xe ===================\n";
	showDetailsList(arrayEBike, number);
	
	cout << "Nhap hang xe can tim: ";
	cin >> brandSearch;
	
	cout << "=================== Danh sach xe co thuong hieu \'" << brandSearch << "\' =================\n";
	EBike *listByBrand = filterByBrand(arrayEBike, number, brandSearch);
	showDetailsList(listByBrand, number);

	do {
		cout << "Nhap toc do can tim: ";
		cin >> speedSearch;
	} while (speedSearch <= 0);
	
	cout << "=================== Danh sach xe co toc do \'" << speedSearch << "\' =================\n";
	EBike *listBySpeed = filterBySpeed(arrayEBike, number, speedSearch);
	showDetailsList(listBySpeed, number);
	
	cout << "=================== Danh sach xe co toc do cao nhat ================\n";
	EBike *listMax = filterByMax(arrayEBike, number);
	showDetailsList(listMax, number);
	
	cout << "\nCoding by Cuong ne... :D\n";

	return 0;
	
}













