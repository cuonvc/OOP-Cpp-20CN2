//Cach 1:
//cac ham filter hay ham inputData cua class cha và class con 
//se khong the mapping voi nhau vi khong tra ve cung object

//#include <iostream>
//using namespace std;
//
//class Car {
//	protected:
//		string brand;
//		int manufactureYear;
//		int speed;
//		
//		//constructors
//	public:
//		Car();
//		Car(string, int, int);
//	
//	//getters
//	public:
//		string getBrand() {
//			return brand;
//		}
//		
//		int getManufactureYear() {
//			return manufactureYear;
//		}
//		
//		int getSpeed() {
//			return speed;
//		}
//		
//	public:
//		Car inputData();
//		void showData();
//	
//};
//
//Car::Car() {
//	
//}
//
//Car Car::inputData() {
//	Car car;
//	
//	cout << "Nhap ten thuong hieu: ";
//	cin >> car.brand;
//	cout << "Nhap nam san xuat: ";
//	cin >> car.manufactureYear;
//	cout << "Nhap toc do: ";
//	cin >> car.speed;
//	
//	return car;
//}
//
//void Car::showData() {
//	cout << "Thuong hieu: " << brand << endl;
//	cout << "Nam san xuat: " << manufactureYear << endl;
//	cout << "Toc do: " << speed << endl;
//}
//
//class Bus : public Car {
//	friend Bus *filterByBrand(Bus[], int, string);\
//	friend void showList(Bus[], int);
//	friend Bus *filterByYear(Bus[], int, int);
//	friend Bus *filterBySeat(Bus[], int);
//	private:
//		string route;
//		int numOfSeat;
//		
//		//getters
//	public:
//		string getRoute() {
//			return route;
//		}
//		
//		int getNumOfSeat() {
//			return numOfSeat;
//		}
//		
//	public:
//		Bus inputData();
//		void showData();
//};
//
//Bus Bus::inputData() {
//	Bus bus;
//	cout << "Nhap thuong hieu: ";
//	cin >> bus.brand;
//	cout << "Nhap nam san xuat: ";
//	cin >> bus.manufactureYear;
//	cout << "Nhap toc do: ";
//	cin >> bus.speed;
//	cout << "Nhap tuyen duong: ";
//	cin >> bus.route;
//	cout << "Nhap so ghe ngoi: ";
//	cin >> bus.numOfSeat;
//	
//	return bus;
//}
//
//void Bus::showData() {
//	Car::showData();
//	cout << "Tuyen duong: " << route << endl;
//	cout << "So ghe ngoi toi da: " << numOfSeat << endl;
//}
//
//Bus *filterByBrand(Bus array[],  int len, string key) {
//	int count = 0;
//	static Bus newArray[100];
//	
//	for (int i = 0; i < len; i++) {
//		string brand = array[i].brand;
//		if (brand.compare(key) == 0) {
//			newArray[count] = array[i];
//			count++;
//		}
//	}
//	
//	return newArray;
//}
//
//Bus *filterByYear(Bus array[], int len, int key) {
//	int count = 0;
//	static Bus newArray[100];
//	
//	for (int i = 0; i < len; i++) {
//		if (array[i].manufactureYear == key) {
//			newArray[count] = array[i];
//			count++;
//		}
//	}
//	
//	return newArray;
//}
//
//Bus *filterBySeat(Bus array[], int len) {
//	int max = 0;
//	for (int i = 0; i < len; i++) {
//		if (array[i].numOfSeat >= max) {
//			max = array[i].numOfSeat;
//		}
//	}
//	
//	int count = 0;
//	static Bus newArray[100];
//	for (int i = 0; i < len; i++) {
//		if (array[i].numOfSeat == max) {
//			newArray[count] = array[i];
//			count++;
//		}
//	}
//	
//	return newArray;
//}
//
//void showList(Bus array[], int len) {
//	for (int i = 0; i < len; i++) {
//		if (array[i].speed != 0) {
//			cout << "THong tin xe thu " << (i + 1) << ":\n";
//			array[i].showData();
//		}
//	}
//}
//
//int main() {
//	
//	int length;
//	string brandKey;
//	int yearKey;
//	
//	do {
//		cout << "Nhap so luong xe: ";
//		cin >> length;
//	} while (length <= 0);
//	Bus busArray[length];
//	
//	for (int i = 0; i < length; i++) {
//		Bus bus;
//		cout << "Nhap thong tin xe thu " << (i + 1) << ":\n";
//		busArray[i] = bus.inputData();
//	}
//	
//	cout << "Nhap thuong hieu can tim kiem: ";
//	cin >> brandKey;
//	
//	Bus *resultBrand = filterByBrand(busArray, length, brandKey);
//	cout << "=========== Danh sach xe co thuong hieu \"" << brandKey << "\" ===========\n";
//	showList(resultBrand, length);
//	
//	cout << "Nhap nam san xuat can tim kiem: ";
//	cin >> yearKey;
//	
//	Bus *resultYear = filterByYear(busArray, length, yearKey);
//	cout << "=========== Danh sach xe co nam san xuat " << yearKey << " ===========\n";
//	showList(resultYear, length);
//	
//	Bus *resultSeatMax = filterBySeat(busArray, length);
//	cout << "============ Danh sach cac xe co cho ngoi nhieu nhat ===========\n";
//	showList(resultSeatMax, length);
//	
//	
//	return 0;
//}







//Cach 2:
//Viet ham input va ham filter kieu void thi se ap dung duoc tinh da hinh 
//(khong toi uu code neu bai toan phuc tap hon)

#include <iostream>
using namespace std;

class Car {
	protected:
		string brand;
		int manufactureYear;
		int speed;
		
		//constructors
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
		
	public:
		virtual void inputData();
		virtual void inputDataList(Car[], int);
		virtual void showData();
		virtual void showDataList(Car[], int);
		virtual void filterByBrand(Car[], int, string);
		virtual void filterByYear(Car[], int, int);
	
};

Car::Car() {
	
}

void Car::inputData() {
	
	cout << "Nhap ten thuong hieu: ";
	cin >> brand;
	cout << "Nhap nam san xuat: ";
	cin >> manufactureYear;
	cout << "Nhap toc do: ";
	cin >> speed;
}

void Car::inputDataList(Car array[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Nhap thong tin xe oto thu " << (i + 1) << ":\n";
		array[i].inputData();
	}
}

void Car::showData() {
	cout << "Thuong hieu: " << brand << endl;
	cout << "Nam san xuat: " << manufactureYear << endl;
	cout << "Toc do: " << speed << endl;
}

void Car::showDataList(Car array[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Thong tin xe oto thu " << (i + 1) << ":\n";
		array[i].showData();
	}
}

void Car::filterByBrand(Car array[], int len, string key) {
	for (int i = 0; i < len; i++) {
		string brand = array[i].brand;
		if (brand.compare(key) == 0) {
			cout << "Thong tin xe thu " << (i + 1) << ":\n";
			array[i].showData();
		}
	}
}

void Car::filterByYear(Car array[], int len, int key) {
	for (int i = 0; i < len; i++) {
		if (array[i].manufactureYear == key) {
			cout << "Thong tin xe thu " << (i + 1) << ":\n";
			array[i].showData();
		}
	}
}

class Bus : public Car {
	private:
		string route;
		int numOfSeat;
		
		//getters
	public:
		string getRoute() {
			return route;
		}
		
		int getNumOfSeat() {
			return numOfSeat;
		}
		
	public:
		void inputData();
		void inputDataList(Bus[], int);
		void showData();
		void showDataList(Bus[], int);
		void filterByBrand(Bus[], int, string);
		void filterByYear(Bus[], int, int);
		void filterBySeatMax(Bus[], int);
};

void Bus::inputData() {
	Car::inputData();
	cout << "Nhap tuyen duong: ";
	cin >> route;
	cout << "Nhap so ghe ngoi: ";
	cin >> numOfSeat;
}

void Bus::inputDataList(Bus array[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Nhap thong tin xe bus thu " << (i + 1) << ":\n";
		array[i].inputData();
	}
}

void Bus::showData() {
	Car::showData();
	cout << "Tuyen duong: " << route << endl;
	cout << "So ghe ngoi toi da: " << numOfSeat << endl;
}

void Bus::showDataList(Bus array[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Thong tin xe bus thu " << (i + 1) << ":\n";
		array[i].showData();
	}
}

void Bus::filterByBrand(Bus array[], int len, string key) {
	for (int i = 0; i < len; i++) {
		string brand = array[i].brand;
		if (brand.compare(key) == 0) {
			cout << "Thong tin xe bus thu " << (i + 1) << ":\n";
			array[i].showData();
		}
	}
}

void Bus::filterByYear(Bus array[], int len, int key) {
	for (int i = 0; i < len; i++) {
		if (array[i].manufactureYear == key) {
			cout << "Thong tin xe bus thu " << (i + 1) << ":\n";
			array[i].showData();
		}
	}
}

void Bus::filterBySeatMax(Bus array[], int len) {
	int max = 0;
	for (int i = 0; i < len; i++) {
		if (array[i].numOfSeat >= max) {
			max = array[i].numOfSeat;
		}
	}
	
	for (int i = 0; i < len; i++) {
		if (array[i].numOfSeat == max) {
			cout << "Xe thu bus " << (i + 1) << ":\n";
			array[i].showData();
		}
	}
}

int main() {
	
	int length;
	string brandKey;
	int yearKey;
	
	do {
		cout << "Nhap so luong xe: ";
		cin >> length;
	} while (length <= 0);
	Bus busArray[length];
	
	Bus bus;
	
	cout << "============ Nhap thong tin xe Bus ============\n";
	bus.inputDataList(busArray, length);
	cout << "============ Thong tin xe Bus ==============\n";
	bus.showDataList(busArray, length);
	
	
	cout << "Nhap thuong hieu can tim kiem: ";
	cin >> brandKey;
	
	cout << "=========== Danh sach xe co thuong hieu \"" << brandKey << "\" ===========\n";
	bus.filterByBrand(busArray, length, brandKey);

	cout << "Nhap nam san xuat can tim kiem: ";
	cin >> yearKey;

	cout << "=========== Danh sach xe co nam san xuat " << yearKey << " ===========\n";
	bus.filterByYear(busArray, length, yearKey);
	
	cout << "============ Danh sach cac xe co cho ngoi nhieu nhat ===========\n";
	bus.filterBySeatMax(busArray, length);
	
	
	return 0;
}











