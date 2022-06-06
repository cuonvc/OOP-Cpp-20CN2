#include <iostream>
using namespace std;

class Box {
	private:
		float length;
		float width;
		float height;
		
	public:
		Box();
		
	public:
		//getters
		float getLength() {
			return length;
		}
		
		float getWidth() {
			return width;
		}
		
		float getHeight() {
			return height;
		}
		
		//setters
		void setLength(float length) {
			this->length = length;
		}
		
		void setWidth(float width) {
			this->width = width;
		}
		
		void setHeight(float height) {
			this->height = height;
		}
		
	public:
		float theTich(float, float, float);
		void inputData();
		
	friend float operator +(Box, Box);
};

float operator +(Box a, Box b) {
	float box1 = a.theTich(a.getHeight(), a.getLength() ,a.getWidth());
	float box2 = b.theTich(b.getHeight(), b.getLength(), b.getWidth());
	
	return box1 + box2;
}

Box::Box() {
	
}

float Box::theTich(float l, float w, float h) {
	return l * w * h;
}

void Box::inputData() {
	cout << "Nhap chieu dai: ";
	cin >> length;
	cout << "Nhap chieu rong: ";
	cin >> width;
	cout << "Nhap chieu cao: ";
	cin >> height;
}

int main() {
	
	Box box1;
	Box box2;
	
	cout << "Nhap kich thuoc box 1:\n";
	box1.inputData();
	cout << "Nhap kich thuoc box 2:\n";
	box2.inputData();
	
	//ham nay lam theo yeu cau, khong su dung den
	float result1 = box1.theTich(box1.getLength(), box1.getWidth(), box1.getHeight());
	float result2 = box2.theTich(box2.getLength(), box2.getWidth(), box2.getHeight());
	
	float box3 = box1 + box2;
	
	cout << "Ket qua cong: " << box3 << endl;
	
	return 0;
}












