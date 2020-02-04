// ch21 - Quiz_BankBook.h
// 클래스명.h = 해당 클래스의 선언부
// 헤더파일을 직접 만들 수 있다.
// class 안의 메소드 정의코드를 밖으로 빼서, c++는 그냥 클래스의 틀만 들어감.
// only 선언부

#pragma once

#include <string>

using namespace std;

class BankBook {
public:
	static void showRate() //method 정의부 전부 삭제, 선언부만 들어오게 함.

	static void changeRate(double _rate);

	void info();

	// 출금
	bool withdraw(int money);
		
	// 입금
	bool deposit(int money);
		
	~BankBook();

	BankBook(const string& account, const string& name = "none", int balance = 0);

private:
	static double rate;
	const string account;
	string name;
	int balance;
};
