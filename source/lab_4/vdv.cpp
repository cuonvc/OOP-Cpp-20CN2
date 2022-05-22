#include <iostream>
using namespace std;

//o bai nay, de bai khong yeu cau sap xep danh sach vdv theo tieu chi nao nen em cho theo weight

class VDV {
	
	friend void showList(VDV[], int);
	friend void sortAscendingByWeight(VDV[], int);
	friend VDV filterMaxHeight(VDV[], int);
		
	
	private:
		static int count;
		int id;
		string fullName;
		int age;
		string game;
		float height;
		float weight;
		
	public:
		VDV();
		VDV(int, string, int, string, float, float);
		
	public:
		int getId() {
			return id;
		}
		
		string getFullName() {
			return fullName;
		}
		
		int getAge() {
			return age;
		}
		
		string getGame() {
			return game;
		}
		
		float getHeight() {
			return height;
		}
		
		float getWeight() {
			return height;
		}
		
	public:
		static void idAscending() {
			count++;
		}
		
		VDV inputData();
		void showData();
		
		~VDV();
};

VDV::VDV() {
	
}

VDV::~VDV() {
	
}

int VDV::count = 100;

VDV VDV::inputData() {
	VDV vdv;
	
	vdv.id = count;
	idAscending();
	
	cout << "Nhap ho ten: ";
//	getline(cin, vdv.fullName);
	cin >> vdv.fullName;
//	cin.ignore();
	do {
		cout << "Nhap tuoi: ";
		cin >> vdv.age;
	} while (vdv.age < 18);
	
	cout << "Nhap mon thi dau: ";
//	getline(cin, vdv.game);
	cin >> vdv.game;
	do {
		cout << "Chieu cao: ";
		cin >> vdv.height;
	} while (vdv.height < 1.5);
	
	do {
		cout << "Nhap can nang: ";
		cin >> vdv.weight;
	} while (vdv.weight < 50);
	
	return vdv;
}

void VDV::showData() {
	cout << "ID: " << id << endl;
	cout << "Ho ten: " << fullName << endl;
	cout << "Tuoi: " << age << endl;
	cout << "Mon thi dau: " << game << endl;
	cout << "Chieu cao: " << height << "m\n";
	cout << "Can nang: " << weight << "kg\n";
}

void showList(VDV array[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Thong tin van dong vien thu " << (i + 1) << endl;
		array[i].showData();
	}	
}

void sortAscendingByWeight(VDV array[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			VDV vdv = array[i];
			if (array[i].weight > array[j].weight) {
				array[i] = array[j];
				array[j] = vdv;
			}
		}
	}
}

VDV filterMaxHeight(VDV array[], int len) {
	float max = 0;
	
	for (int i = 0; i < len; i++) {
		if (array[i].height > max) {
			max = array[i].height;
		}
	}
	
	for (int i = 0; i < len; i++) {
		if (array[i].height == max) {
			return array[i];
		}
	}
	
}

int main() {
	
	int length;
	
	cout << "Nhap so van dong vien: ";
	cin >> length;
	
	VDV arrayVDV[length];
	
	for (int i = 0; i < length; i++) {
		VDV vdv;
		cout << "Nhap thong tin van dong vien thu " << (i + 1) << endl;
		arrayVDV[i] = vdv.inputData();
	}
	
	cout << ">>>>>>>>>>>>> Danh sach van dong vien <<<<<<<<<<<<<<<\n";
	showList(arrayVDV, length);
	
	//sap xep mang theo chieu tang dan (sap xep theo weight)
	sortAscendingByWeight(arrayVDV, length);
	cout << ">>>>>>>>>>>>>> Danh sach van dong vien sau khi sap xep <<<<<<<<<<<<<\n";
	showList(arrayVDV, length);
	
	cout << ">>>>>>>>>>>>>> Van dong vien co chieu cao la cao nhat <<<<<<<<<<<<<\n";
	VDV resultMax = filterMaxHeight(arrayVDV, length);
	resultMax.showData();
	
	return 0;
}










