#include <iostream>
using namespace std;

class Shape {
	protected:
		float length;
		float width;
		
	public:
		Shape();
		Shape(float, float);
		
	public:
		float getLength() {
			return length;
		}
		
		float getWidth() {
			return width;
		}
		
	public:
		void inputData();
		virtual float calculator(float, float);
};

Shape::Shape() {
	
}

void Shape::inputData() {
	cout << "Nhap chieu dai: ";
	cin >> length;
	cout << "Nhap chieu rong: ";
	cin >> width;
}

float Shape::calculator(float l, float w) {
	return 0;
}

class HCN : public Shape {
	public:
		float calculator(float, float);
};

//Override tu Shape class
float HCN::calculator(float l, float w) {
	return (float) l * w;
}

class Triangle : public Shape {
	public:
		float calculator(float, float);
};

//Override tu Shape class
float Triangle::calculator(float l, float w) {
	return (float) (l * w) / 2;
}



int main() {
	
	Shape *shape1;
	Shape *shape2;
	
	HCN hcn;
	shape1 = &hcn;
	
	Triangle triangle;
	shape2 = &triangle;
	
	cout << "Nhap thong tin hinh chu nhat: \n";
	shape1->inputData();
	cout << "Nhap thong tin hinh tam giac: \n";
	shape2->inputData();
	
	float S1 = shape1->calculator(hcn.getLength(), hcn.getWidth());
	float S2 = shape2->calculator(triangle.getLength(), triangle.getWidth());
	
	cout << "Dien tich hinh chu nhat: " << S1 << endl;
	cout << "Dien tich hinh tam giac: " << S2;
	
	return 0;
}












