#include <iostream>
using namespace std;

class Candidate {
	protected:
		string fullName; //ho va ten
		string orderNumber;  //so bao danh
		float scoreTotal;  //tong diem
		
	public:
		Candidate();
		
	public:
		Candidate inputData();
		void showData();
};

Candidate::Candidate() {
	
}

Candidate Candidate::inputData() {
	Candidate candidate;
	
	cout << "Nhap ho va ten: ";
	cin >> candidate.fullName;
	cout << "Nhap so bao danh: ";
	cin >> candidate.orderNumber;
	do {
		cout << "Nhap tong diem: ";
		cin >> candidate.scoreTotal;
	} while (candidate.scoreTotal < 0 || candidate.scoreTotal > 30);
}

void Candidate::showData() {
	cout << "Ho va ten: " << fullName << endl;
	cout << "So bao danh: " << orderNumber << endl;
	cout << "Tong diem: " << scoreTotal << endl;
}

class SubCandidate : public Candidate {
	friend SubCandidate *filterScore(SubCandidate[], int);
	friend void showDataList(SubCandidate[], int);
	private:
		string address;  //dia chi
		string hometown;  //que quan
		
	public:
		SubCandidate inputDataDetails();
		void showData();
};

SubCandidate SubCandidate::inputDataDetails() {
	//cho nay van chua thuc so toi uu. Dang nhe nen goi lai ham input tu ham cha
	//nhung input la ham tra ve Oject nen khong the mapping voi gia tri tra ve giua ham cha va ham con
	
	SubCandidate oj;
	cout << "Nhap ho va ten: ";
	cin >> oj.fullName;
	cout << "Nhap so bao danh: ";
	cin >> oj.orderNumber;
	do {
		cout << "Nhap tong diem: ";
		cin >> oj.scoreTotal;
	} while (oj.scoreTotal < 0 || oj.scoreTotal > 30);
	
	cout << "Nhap dia chi: ";
	cin >> oj.address;
	cout << "Nhap que quan: ";
	cin >> oj.hometown;
	
	return oj;
}

void SubCandidate::showData() {
	Candidate::showData();
	cout << "Dia chi: " << address << endl;
	cout << "Quen quan: " << hometown << endl;
}

SubCandidate *filterScore(SubCandidate array[], int length) {
	int count = 0;
	static SubCandidate newArray[100];
	for (int i = 0; i < length; i++) {
		if (array[i].scoreTotal > 15) {
			newArray[count] = array[i];
			count++;
		}
	}
	
	return newArray;
}

void showDataList(SubCandidate array[], int length) {
	for (int i = 0; i < length; i++) {
		if (array[i].scoreTotal != 0) {  //apply cho ham filter
			cout << "Thong tin sinh vine thu " << (i + 1) << ":\n";
			array[i].showData();
		}
	}
}


int main() {
	
	int n;
	
	do {
		cout << "Nhap so luong thi sinh: ";
		cin >> n;
	} while (n < 1);
	SubCandidate array[n];
	
	for (int i = 0; i < n; i++) {
		SubCandidate obj;
		cout << "Nhap thong tin sinh vien thu " << (i + 1) << endl;
		array[i] = obj.inputDataDetails();
	}
	
	SubCandidate *arrayFilter = filterScore(array, n);
	cout << "============ Danh sach sinh vien co tong diem > 15 ===========\n";
	showDataList(arrayFilter, n);
	
	
	
	return 0;
}















