#include <iostream>
using namespace std;

class Course {
	
	friend Course compare(float, float, Course, Course);
	
	private:
		string id;
		string name;
		float totalTime;
		float price;
		
	public:
		Course();
		Course(string, string, float, float);
		
	public:
		string getId() {
			return id;
		}
		
		string getName() {
			return name;
		}
		
		float getTotalTime() {
			return totalTime;
		}
		
		float getPrice() {
			return price;
		}
		
	public:
		void inputData();
		void showData();
};

Course::Course() {
	
}

void Course::inputData() {
	cout << "Nhap ma khoa hoc: ";
	cin >> id;
	cout << "Nhap ten khoa hoc: ";
	cin >> name;
	cout << "Tong thoi gian khoa hoc: ";
	cin >> totalTime;
	cout << "Gia khoa hoc: ";
	cin >> price;
}

void Course::showData() {
	cout << "ID: " << id << endl;
	cout << "Ten khoa hoc: " << name << endl;
	cout << "Thoi gian hoc: " << totalTime << "h\n";
	cout << "Gia tien: " << price << endl;
}

Course compare(float p1, float p2, Course course1, Course course2) {
	if (p1 > p2) {
		return course1;
	} else {  //Cho nay dung ra con mot truong hop bang nhau nua :))))
		return course2;
	}
}

int main() {
	Course mainCourse;
	Course course1;
	Course course2;
	
	cout << "Nhap vao thong tin tung khoa hoc: \n";
	cout << "Nhap khoa hoc thu nhat: \n";
	course1.inputData();
	cout << "Nhap khoa hoc thu hai: \n";
	course2.inputData();
	
	cout << "\nThong tin hai khoa hoc: \n";
	cout << "Thong tin khoa hoc thu nhat: \n";
	course1.showData();
	cout << "Thong tin khoa hoc thu hai: \n";
	course2.showData();
	
	cout << "\nKHoa hoc co gia tien lon hon la: \n";
	Course result = compare(course1.getPrice(), course2.getPrice(), course1, course2);
	result.showData();
}
