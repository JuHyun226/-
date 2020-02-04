// ch21-Quiz_main.cpp

//헤더파일을 이용해서 끌여들였기에 구현부도 같이 들어옴.

#pragma once
// 같은 프로젝트 안에서 헤더파일 여러번 사용하면 문제가 터지기에 한번에 하도록 하는게 프레그마 원스

#include <iostream>
#include <string>
#include "ch21-Quiz_BankBook.h"

using namespace std;

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
