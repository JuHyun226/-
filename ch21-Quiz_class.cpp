/*
	ch21-Quiz_class.cpp
*/

#include <iostream>
#include <string>

using namespace std;

/*
하나의 은행 상품을 관리하는 BankBook class 를 정의하고 테스트 하세요
- 이율 설정(변경), 확인 가능
  통장 정보 확인 가능
  계좌 입/출금 가능

- 상품이율( 공통으로 적용 가능 => static ), 계좌번호( 한번 설정 후 변경 불가 => instance),
  고객명, 잔액의 관리가 가능합니다

*/

class BankBook {
public:

	//이율 확인
	static void showRate() {
		cout << "현재 이율 : " << rate << " %" << endl;
	}

	//이율 변경
	static void changeRate(double _rate) {
		if (rate >= 0) {
			rate = _rate;
			cout << "변경 이율 : " << rate << " %" << endl;
		}
	}

	//통장 정보 확인
	void info() {
		cout << "----- 계 좌 정 보 -----" << endl;
		cout << "계좌번호 : " << account << endl;
		cout << "고객명  : " << name << endl;
		cout << "잔액    : " << balance << " 원" << endl;
		cout << "이율    : " << rate << " %" << endl;
	}

	// 출금
	bool withdraw(int money) {
		if (money > 0 && money <= this->balance) {
			this->balance -= money;
			cout << money << " 원 출금" << endl;
			cout << "출금 후 잔액 : " << this->balance << " 원" << endl;
			return true;
		}
		cout << "출금액 오류~" << endl;
		return false;
	}

	// 입금
	bool deposit(int money) {
		if (money > 0) {
			this->balance += money;
			cout << money << " 원 입금" << endl;
			cout << "입금 후 잔액 : " << this->balance << " 원" << endl;
			return true;
		}
		cout << "입금액 오류~" << endl;
		return false;
	}
	
	//
	~BankBook() {
		cout << account << " 계좌 삭제" << endl;
	}

	BankBook(const string& account, const string& name = "none", int balance = 0)
		: account(account), name(name), balance(balance) {}//account의 값은 account로 초기화

private:
	static double rate;
	const string account;
	string name;
	int balance;
};


double BankBook::rate = 2.0;

int main() {

	BankBook* memA = new BankBook("000123-01-0001", "고객A");
	memA->info();
	cout << endl;

	BankBook* memB = new BankBook("000123-01-0001", "고객B", 10000);
	memB->info();

	memB->deposit(-1000);
	memB->deposit(100000);
	memB->withdraw(-50000);
	memB->withdraw(109999);
	cout << endl;

	BankBook::changeRate(-2.5);
	BankBook::showRate();
	BankBook::changeRate(3.5);
	memA->info();
	memB->info();

}
