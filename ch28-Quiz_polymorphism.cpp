// ch28-Quiz_polymorphism.cpp

#include <iostream>
#include <string>

using namespace std;

class Arms {
public:
	virtual void attack() = 0;
	Arms(const string& item) : item(item) {}
protected:
	string item; //  아이템 이름
};

// Arms class 상속받는 Gun(권총), Knife(나이프), Bomb(수류탄) class 를 정의하고,
class Gun : public Arms {
public:
	virtual void attack() { cout << gun << "으로 공격" << endl; }
		Gun(): attack("ATTACK"), {}

protected:
	string attack;

};

class Knife : public Arms {
public:
	virtual void attack() { cout << knife << "으로 공격" << endl; }
	Knife() : attack("ATTACK"), {}
};

class Bomb : public Arms {
public:
	virtual void attack() { cout << bomb << "으로 공격" << endl; }
	Bomb() : attack("ATTACK"), {}
};
// Arms class 로 다형성을 구현하세요

int main() {



}
