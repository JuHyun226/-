// ch28-Quiz_polymorphism.cpp

#include <iostream>
#include <string>

using namespace std;

class Arms {
public:
	virtual void attack() = 0;  // 아이템 사용
	Arms(const string& item) : item(item) {}
protected:
	string item; //  아이템 이름
};

// Arms class 상속받는 Gun(권총), Knife(나이프), Bomb(수류탄) class 를 정의하고,
// Arms class 로 다형성을 구현하세요

class Gun : public Arms {
public:
	void attack() {
		cout << item << " 사용" << endl;
	}
	Gun(const string& item = "권총") : Arms(item){}
};

class Knife : public Arms {
public:
	void attack() {
		cout << item << " 사용" << endl;
	}
	Knife(const string& item = "나이프") : Arms(item){}
};

class Bomb : public Arms {
public:
	void attack() {
		cout << item << " 사용" << endl;
	}
	Bomb(const string& item="수류탄") : Arms(item) { }
};

class Item {
public:
	void itemUse() {
		bool itemRun = true;
		while (itemRun) {
			int use;
			cout << "1.아이템 선택  2.아이템 사용 > "; cin >> use;
			switch (use) {
			case 1:
				selectItem(); break;
			case 2:
				attack(); break;
			case 0:
				itemRun = false;
			}
		}
	}
	void attack() {
		arms->attack();
	}
	void selectItem() {
		int select;
		cout << "1.총  2.나이프  3.수류탄 > "; cin >> select;

		switch (select) {
		case 1:
			arms = gun; break;
		case 2:
			arms = knife; break;
		case 3:
			arms = bomb; break;
		}
	}
	~Item() {
		delete gun;
		delete knife;
		delete bomb;
	}
	Item() {
		arms = NULL;
		gun = new Gun;
		knife = new Knife;
		bomb = new Bomb;
	}

private:
	Bomb* bomb;
	Knife* knife;
	Gun* gun;
	Arms* arms;
};

int main() {

	Item item;
	item.itemUse();


}
