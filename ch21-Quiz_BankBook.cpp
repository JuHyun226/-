//ch21-Quiz_BankBook.cpp

#pragma once

#include <iostream>
#include "ch21-Quiz_BankBook.h"
//c+에서 제공하는 헤더파일 가져올 때는 <>
// 내가 만든거 가져올 때는 "" => 클래스 선언부가 들어옴. 그러니 메소드 정의부를 여기에 넣으면 됨.

double Bankbook::rate = 2.0;

void Bankbook::showRate() { // 어떤 클래스의 메소드인지 메소드명 앞에 알려줘야함.(외부정의)
	cout << "현재 이율 : " << rate << " %" << endl;
}
//static랑 디폴트 매개변수는 선언부에만 붙이고, 외부정의시에는 안 붙임
void Bankbook::changeRate(double _rate) {
	if (rate >= 0) {
		rate = _rate;
		cout << "변경 이율 : " << rate << " %" << endl;
	}
}

void Bankbook::info() {
	cout << "----- 계 좌 정 보 -----" << endl;
	cout << "계좌번호 : " << account << endl;
	cout << "고객명  : " << name << endl;
	cout << "잔액    : " << balance << " 원" << endl;
	cout << "이율    : " << rate << " %" << endl;
}

// 출금
bool Bankbook::withdraw(int money) {
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
bool Bankbook::deposit(int money) {
	if (money > 0) {
		this->balance += money;
		cout << money << " 원 입금" << endl;
		cout << "입금 후 잔액 : " << this->balance << " 원" << endl;
		return true;
	}
	cout << "입금액 오류~" << endl;
	return false;
}

Bankbook::~BankBook() {
	cout << account << " 계좌 삭제" << endl;
}

Bankbook::BankBook(const string& account, const string& name , int balance)//디폴트 매개변수는 선언부에만 붙혀야 하니 삭제
	: account(account), name(name), balance(balance) {}

