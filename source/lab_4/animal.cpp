#include <iostream>
using namespace std;

class Animal {
	
	friend void showList(Animal[], int);
	friend void filterAnimal(Animal[], int);
	
	private:
		static int count;
		int id;
		string name;
		int age;
		string origin;
		int protectPhase; //cap do bao ve
		
	public:
		Animal();
		
	public:
		static int idAscending() {
			count++;
		}
		Animal inputData();
		void showData();
};

Animal::Animal() {
	
}

int Animal::count = 1;

Animal Animal::inputData() {
	
	Animal animal;
	
	animal.id = count;
	idAscending();
	
	cout << "Nhap ten con vat: ";
	cin >> animal.name;
	do {
		cout << "So tuoi: ";
		cin >> animal.age;
	} while (animal.age < 1);
	cout << "Nguon goc: ";
	cin >> animal.origin;
	
	do {
		cout << "Cap do bao ve: ";
		cin >> animal.protectPhase;
	} while (animal.protectPhase < 1 || animal.protectPhase > 3);
	
	return animal;
	
}

void Animal::showData() {
	cout << "ID: " << id << endl;
	cout << "Ten con vat: " << name << endl;
	cout << "So tuoi: " << age << endl;
	cout << "Nguon goc: " << origin << endl;
	
	cout << "Cap do bao ve: ";
	if (protectPhase == 1) {
		cout << "Binh thuong." << endl;
	} else if (protectPhase == 2) {
		cout << "Can duoc bao ve." << endl;
	} else {  //vi protectPhase chi co the la 1, 2 hoac 3
		cout << "Nguy co tuyet chung." << endl;
	}
}

void showList(Animal array[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Thong tin con vat thu " << (i + 1) << ":\n";
		array[i].showData();
	}
}

void filterAnimal(Animal array[], int len) {
	for (int i = 0; i < len; i++) {
		if (array[i].protectPhase == 3) {
			cout << "Thong tin con vat:\n";
			array[i].showData();
		}
	}
}

int main() {
	
	int length;
	
	cout << "Nhap so luong con vat: ";
	cin >> length;
	
	Animal arrayAnimal[length];
	
	for (int i = 0; i < length; i++) {
		Animal animal;
		cout << "Nhap thong tin con vat thu " << (i + 1) << endl;
		arrayAnimal[i] = animal.inputData();
	}
	
	cout << ">>>>>>>>>>>>>>> Danh sach thong tin nhung con vat <<<<<<<<<<<<<<<\n";
	showList(arrayAnimal, length);
	
	cout << ">>>>>>>>>>>>>>> Danh sach nhung con vat co nguy co tuyet chung <<<<<<<<<<<<<<<<\n";
	filterAnimal(arrayAnimal, length);
	
	return 0;
}






