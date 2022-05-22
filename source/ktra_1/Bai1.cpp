#include <iostream>
using namespace std;

class BankAccount {
	
	friend void showListAccount(BankAccount[], long);
	friend void sortAscendingBalance(BankAccount[], long);
	friend BankAccount filterAcc(BankAccount[], long, string);
	
	private:
		static long count;
		long accountNumber;
		string accountName;
		double balance;
		
		//contructors
	public:
		BankAccount();
		BankAccount(long, string, double);
		
		//getters and setters
	public:
		long getAccountNumber() {
			return accountNumber;
		}
		
		void setAccountNumber(long num) {
			accountNumber = num;
		}
		
		string getAccountName() {
			return accountName;
		}
		
		void setAccountName(string name) {
			accountName = name;
		}
		
		double getBalance() {
			return balance;
		}
		
		void setBalance(double balan) {
			balance = balan;
		}
		
		//methods
		public:
			static isAscending() {
				count++;
			}
			
			BankAccount inputData();
			void showData();
			
			void inputMoney(double);
			void withdrawMoney(double);		
};

BankAccount::BankAccount() {
	
}

long BankAccount::count = 100000;

BankAccount BankAccount::inputData() {
	
	BankAccount account;
	account.accountNumber = count;
	isAscending();
	
	cout << "Nhap ten tai khoan: ";
	cin >> account.accountName;
	cout << "So du: ";
	cin >> account.balance;
	
	return account;
}

void BankAccount::showData() {
	cout << "So tai khoan: " << accountNumber << endl;
	cout << "Ten tai khoan: " << accountName << endl;
	cout << "So du: " << balance << endl;
}

void showListAccount(BankAccount array[], long len) {
	for (long i = 0; i < len; i++) {
		cout << "Thong tin tai khoan thu " << (i + 1) << ":\n";
		array[i].showData();
	}
}

void sortAscendingBalance(BankAccount array[], long len) {
	for (long i = 0; i < len - 1; i++) {
		for (long j = i + 1; j < len; j++) {
			if (array[i].balance > array[j].balance) {
				BankAccount account = array[i];
				array[i] = array[j];
				array[j] = account;
			}
		}
	}
}

BankAccount filterAcc(BankAccount array[], long len, string nameAcc) {
	for (long i = 0; i < len; i++) {
		string nameInArray = array[i].accountName;
		if (nameInArray.compare(nameAcc) == 0) {
			return array[i];
		}
	}
}

void BankAccount::inputMoney(double money) {
	balance = balance + money;
	cout << "So du hien tai: " << balance << endl;
}

void BankAccount::withdrawMoney(double money) {
	balance = balance - money;
	cout << "So du hien tai: " << balance << endl;
}

int main() {
	
	long length;
	string name;
	double moneyInput;
	double moneyOutput;
	
	
	cout << "Nhap so luong tai khoan: ";
	cin >> length;
	while (length <= 0 || length > (999999 - 100000));  //vi so tai khoan gioi han co 6 chu so va bat dau bang 100000
	
	BankAccount arrayAccount[length];
	
	for (long i = 0; i < length; i++) {
		cout << "Nhap thong tin tai khoan thu " << (i + 1) << ":\n";
		BankAccount account;
		arrayAccount[i] = account.inputData();
	}
	
	cout << ">>>>>>>>>>>> Danh sach tai khoan <<<<<<<<<<<<\n";
	showListAccount(arrayAccount, length);
	
	sortAscendingBalance(arrayAccount, length);
	cout << ">>>>>>>>>>>> Danh sach tai khoan sau khi sap xep <<<<<<<<\n";
	showListAccount(arrayAccount, length);
	
	cout << "Nhap ten tai khoan can nap tien: \n";
	cin >> name;
	BankAccount accountInputMoney = filterAcc(arrayAccount, length, name);
	cout << "Nhap so tien can nap: ";
	cin >> moneyInput;
	accountInputMoney.inputMoney(moneyInput);
	
	cout << "Nhap ten tai khoan can rut tien: \n";
	cin >> name;
	BankAccount accountWithdrawMoney = filterAcc(arrayAccount, length, name);
	cout << "Nhap so tien can rut: ";
	cin >> moneyOutput;
	accountWithdrawMoney.withdrawMoney(moneyOutput);
	
	
	return 0;
}
