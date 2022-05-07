#include <iostream>
using namespace std;

class Account {
	
	private:
		string name;
		long balance;
		
	public:
		string getName() {
			return name;
		}
		
		long getBalance() {
			return balance;
		}
		
	public:
		void deposit(int);
		void withdraw();
		int checkBalance();
		
//		Account();
		Account(string, int);
};

Account::Account(string accName, int accBalance) {
	name = accName;
	balance = accBalance;
}

void Account::deposit(int money) {
	cout << "So tien trong tai khoan: \n";
	cin >> money;
}

void Account::withdraw() {
	cout << "Ham withdraw phai la ham tra ve mot gia tri & phai co data input\n";
}

int Account::checkBalance() {
	cout << "Ham checkBalance phai co data input\n";
	return 0;
}

int main() {
	
	Account ducBinh("Duc Binh", 2000000);
	cout << "Account name: " << ducBinh.getName() << endl;
	cout << "Balance: " << ducBinh.getBalance() << " VND.\n";
	
	
	cout << "===================================\n";
	Account thuLan("Thu Lan", 1000000);
	cout << "Account name: " << thuLan.getName() << endl;
	cout << "Balance: " << thuLan.getBalance() << " VND.\n";
	
	
	return 0;
}









