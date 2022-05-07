#include <iostream>
using namespace std;

class AirCondition {
	
	private:
		string idProduct;
		string brand;
		float power;
		long price;
		
	public:
		AirCondition();
		AirCondition(string, string, float, long);
		
	public:
		string getId() {
			return idProduct;
		}
		
		string getBrand() {
			return brand;
		}
		
		float getPower() {
			return power;
		}
		
		long getPrice() {
			return price;
		}
		
	public:
		void inputData();
		AirCondition powerCompare(AirCondition, AirCondition);
		void showDataProductSelect(int);
		long totalPrice(int, long);
};

AirCondition::AirCondition() {
	
}

AirCondition::AirCondition(string ma, string thuongHieu, float congSuat, long gia) {
	idProduct = ma;
	brand = thuongHieu;
	power = congSuat;
	price = gia;
}

void AirCondition::inputData() {
	cout << "Nhap ma san pham: ";
	cin >> idProduct;
	cout << "Thuong hieu: ";
	cin >> brand;
	do {
		cout << "Cong suat: ";
		cin >> power;
	} while (power <= 0);
	
	do {
		cout << "Gia san pham: ";
		cin >> price;
	} while (price < 0);
}

//chon ra san pham co cong suat lon hon
AirCondition AirCondition::powerCompare(AirCondition airCondition1, AirCondition airCondition2) {
	float pw1 = airCondition1.power;
	float pw2 = airCondition2.power;
	
	if (pw1 > pw2) {
		return airCondition1;
	} else {
		return airCondition2;
	}
}

//hien thi san pham duoc chon
void AirCondition::showDataProductSelect(int numOfPr) {
	cout << "Ma san pham: " << idProduct << endl;
	cout << "Thuong hieu: " << brand << endl;
	cout << "Cong suat: " << power << endl;
	cout << "Gia 1 san pham: " << price << endl;
	cout << "Gia " << numOfPr << " san pham: " << (price * numOfPr) << " VND" << endl;
	cout << "Tong gia tien sau VAT: " << totalPrice(numOfPr, price) << " VND" << endl;
}

long AirCondition::totalPrice(int numberOfProduct, long price) {
	return (price * numberOfProduct) + (price * numberOfProduct * 0.1);
}


int main() {
	
	AirCondition airCondition;
	AirCondition airCondition1;
	AirCondition airCondition2;
	int numberOfProduct;
	
	cout << "Nhap thong tin san pham thu nhat: \n";
	airCondition1.inputData();
	cout << "Nhap thong tin san pham thu hai: \n";
	airCondition2.inputData();
	
	//tra ve mot san pham co cong suat lon hon
	AirCondition productSelect = airCondition.powerCompare(airCondition1, airCondition2);
	cout << "San pham duoc chon co ID = " << productSelect.getId() << endl;
	
	do {
		cout << "Chon so luong san pham: ";
		cin >> numberOfProduct;
	} while (numberOfProduct <= 0);
	
	productSelect.showDataProductSelect(numberOfProduct);
	
	
	return 0;
}
