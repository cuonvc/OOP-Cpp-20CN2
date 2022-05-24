#include <iostream>
using namespace std;

class People {
	
	private:
		string name;
		int age;
		string address;
		
	public:
		People();
		
	public:
		void setData();
		void getData();
		
		~People();
};

People::People() {
	
}

People::~People() {
	
}

void People::setData() {
	cout << "Nhap ten: ";
	cin >> name;
	cout << "Nhap tuoi: ";
	cin >> age;
	cout << "Nhap dia chi: ";
	cin >> address;
}

void People::getData() {
	cout << "Ten: " << name << endl;
	cout << "Tuoi: " << age << endl;
	cout << "Dia chi: " << address << endl;
}

class Student: public People {
	
	private:
		int id;
		float math;
		float physical;
		float chemistry;
		
	public:
		void setId(int id) {
			this->id;
		}
		
		int getId() {
			return id;
		}
		
		void setMath(float math) {
			this->math;
		}
		
		float getMath() {
			return math;
		}
		
		void setPhysical(float physical) {
			this->physical;
		}
		
		float getPhysical() {
			return physical;
		}
		
		void setChemistry(float chemistry) {
			this->chemistry;
		}
		
		float getChemistry() {
			return chemistry;
		}
		
		//methods
	public:
		void inputDetails();
		void showDetails();
		float GPA(float, float, float);
		
		
};

float Student::GPA(float math, float phys, float chemis) {
	float avg = (math + phys + chemis) / 3;
	
	return avg;
}

void Student::inputDetails() {
	People::setData();
	cout << "Nhap diem toan: ";
	cin >> math;
	cout << "Nhap diem ly: ";
	cin >> physical;
	cout << "Nhap diem hoa: ";
	cin >> chemistry;
}

void Student::showDetails() {
	People::getData();
	cout << "Diem trung binh: " << GPA(math, physical, chemistry) << endl;
}



int main() {
	
	Student student;
	
	cout << "Nhap thong tin sinh vien: \n";
	student.inputDetails();
	
	cout << "Thong tin sinh vien: \n";
	student.showDetails();
	
	return 0;
}














