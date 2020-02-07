// ch26_UpDownCasting.cpp

#include <iostream>
#include <string>

using namespace std;

class Super {
public:
	void useInfo() {
		cout << "Super info : " << a << endl;
	}
	int getA() { return a; }
	Super(const int& a = 0) : a(a) {}

private:
	int a;
};

class Sub : public Super {
public:
	void useInfo() {
		cout << "Sub info : " << getA() << ", " << b << endl;
	}
	Sub(const int& a = 0, const double& b = 0) : Super(a), b(b) {}

private:
	double b;
};

int main() {

	Super super(10);
	super.useInfo();
	cout << endl;

	Sub sub(20, 2.2);
	sub.useInfo();
	cout << endl;

	//super = sub;
	//super.useInfo();

	//sub = super; Error

	Super* pA = NULL;
	Sub* pB = new Sub(33, 3.3);

	pB->useInfo();

	pA = pB;	// Up casting: 하위 클래스의 것을 상위 클래스로 넘겨주는 것.
	pA->useInfo(); // subclass의 객체인데 상위class로 넘겨지니까 상위클래스(Super=부모)의 메소드가 실행됨. c+에서는 포인터 타입으로서 객체 판단.
	
	pB = (Sub*)pA; // Down casting: 본래 타입으로 되돌려짐(서브 포인터로 캐스팅): 어떤 타입으로 변환할지 정확히 명시 필요.
	pB->useInfo();

}


//----------------------------------------------------------------


class Base {
public:
	void attck() {
		cout << itemA << " 사용" << endl;
	}
	Base() : itemA("권총") {}

private:
	string itemA;
};

class Unit : public Base {
public:
	void attck() {
		int select;
		cout << "1.권총  2.폭탄 > "; cin >> select;
		if (select == 1)
			Base::attck();
		else if (select == 2)
			cout << itemB << " 사용" << endl;
	}
	Unit(const string& name = "none") : name(name), itemB("폭탄") {}

private:
	string itemB;
	string name;
};

int main() {

	Unit* unitA = new Unit("unitA");
	unitA->attck();

	Base* base = unitA;
	base->attck();

	unitA = (Unit*)base;
	unitA->attck();

}
