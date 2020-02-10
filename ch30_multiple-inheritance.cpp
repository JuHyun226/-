// ch30_multiple-inheritance.cpp
// 한번에 여러개의 클래스를 상속받을 수 잇음

#include <iostream>
#include <string>

using namespace std;

class Add {
protected:
	int plus(const int& a, const int& b) { return a + b; }
};

class Sub {
protected:
	int minus(const int& a, const int& b) { return a - b; }
};

class Calc : public Add, public Sub {
public:
	int calc(const char& opt, const int& a, const int& b) {// opt: 기회에 따라 +메시지를 실행할지, -메시지를 실행할지 결정
		int result = 0;
		switch (opt) {
		case '+':
			result = plus(a, b); break;
		case '-':
			result = minus(a, b); break;
		}
		return result;
	}
};

int main() {

	Calc data;
	cout << "123 + 56 = " << data.calc('+', 123, 56) << endl;
	cout << "123 - 56 = " << data.calc('-', 123, 56) << endl;

}


//----------------------------------------------------------------

class DataOne {
public:
	void showData() {
		cout << "- DataOne -" << endl;
	}
};

class DataTwo {
public:
	void showData() {
		cout << "- DataTwo -" << endl;
	}
};

class All : public DataOne, public DataTwo {
public:
	void showAll() {
		DataOne::showData();
		DataTwo::showData();
	}
};

int main() {

	All all;
	all.showAll();

}

//--------------------------------------------------------------

class Top {
public:
	void showTop() { cout << "- showTop() -" << endl; }
	Top() { cout << "- Top 생성자 -" << endl; }
};

class MiddleA : virtual public Top {
public:
	void showMiddleA() { cout << "- showMiddleA() -" << endl; }
	MiddleA() { cout << "- MiddleA 생성자 -" << endl; }
};

class MiddleB : virtual public Top {
public:
	void showMiddleB() { cout << "- showMiddleB() -" << endl; }
	MiddleB() { cout << "- MiddleB 생성자 -" << endl; }
};

class Bot : public MiddleA, public MiddleB {
public:
	void showBot() { cout << "- showBot() -" << endl; }
	Bot() { cout << "- Bot 생성자 -" << endl; }
};

int main() {

	//MiddleA ma;
	//MiddleB mb;

	Bot bot;

}
