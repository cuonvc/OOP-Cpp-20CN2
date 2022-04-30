#include <iostream>
using namespace std;

class Time {
	
	public:
		int hour;
		int minute;
		int second;
		
	public:
		int changeHour(int);
		int changeMinute(int);
		int changeSecond(int);
		
		void showTime(int, int, int);
//		void convert(int);
};

int Time::changeHour(int newHour) {
	do {
		cout << "Nhap so gio can thay doi: ";
		cin >> newHour;
	} while (newHour < 0 || newHour >= 24);
	
	return newHour;
}

int Time::changeMinute(int newMinute) {
	do {
		cout << "Nhap so phut can thay doi: ";
		cin >> newMinute;
	} while (newMinute < 0 || newMinute >= 60);
	
	return newMinute;
}

int Time::changeSecond(int newSecond) {
	do {
		cout << "Nhap so giay can thay doi: ";
		cin >> newSecond;
	} while (newSecond < 0 || newSecond >= 24);
	
	return newSecond;
}

void Time::showTime(int gio, int phut, int giay) {
	if (gio < 10) {
		char s1[5] = {"0"};
		std::string s2 = std::to_string(gio);
		cout << s1 << s2 <<":";
	} else if (gio > 12) {
		cout << (gio - 12) << ":";
	} else {
		cout << gio << ":";
	}
	
	if (phut < 10) {
		char s1[5] = {"0"};
		std::string s2 = std::to_string(phut);
		cout << s1 << s2 <<":";
	} else {
		cout << phut << ":";
	}
	
	if (giay < 10) {
		char s1[5] = {"0"};
		std::string s2 = std::to_string(giay);
		cout << s1 << s2;
	} else {
		cout << giay;
	}
	
	if (gio <= 12) {
		cout << " AM";
	} else {
		cout << " PM";
	}
	
//	convert(gio);
//	convert(phut);
//	convert(giay);
	
}

//void Time::convert(int time) {
//	if (time < 10) {
//		char str1[10] = {"0"};
//		std::string str2 = std::to_string(time);
//		cout << str1 << str2 <<":";
//	} else {
//		cout << time << ":";
//	}
//}




int main() {
	
	int gio;
	int phut;
	int giay;
	
	Time newTime;
	
	int newH = newTime.changeHour(gio);
	int newMinu = newTime.changeMinute(phut);
	int newSec = newTime.changeSecond(giay);

	cout << "Thoi gian moi la: \n";
	newTime.showTime(newH, newMinu, newSec);
	
	return 0;
}
