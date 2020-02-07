// ch28_polymorphism.cpp
/* 
다형성
= 여러개의 자식클래스 객체를 하나의 부모클래스의 포인터로 컨트롤

순수 가상 함수
- 메소드의 기능 정의하지 않은 가상 함수입니다
- 반드시 상속을 해야하는 클래스의 경우 기본클래스에서는 가상함수의 내용을 정의 할 필요가 없습니다
  이러한 경우에 순수 가상 함수를 사용합니다
- 순수 가상 함수를 포함하는 클래스는 객체 생성이 불가능 합니다
- 실체가 없기 때문에 추상클래스라고도 합니다
*/
#include <iostream>
#include <string>

using namespace std;

class Remote {
public:
	//virtual void powerOff() { cout << "전원 : " << off << endl; }
	//virtual void powerOn() { cout << "전원 : " << on << endl; }
	virtual void powerOff() = 0;
	virtual void powerOn() = 0;
	Remote() : on("ON"), off("OFF") {} // 순수 가상함수 --> 이걸 가지고는 객체 생성 불가능

//private:
protected: // 상속받은 하위클래스에서는 접근을 허용함.
	string off;
	string on;
};

class Tv : public Remote { //클래스 Tv를 만들고, remote를 상속받음
public:
	virtual void powerOff() { cout << "TV 전원 : " << off << endl; }
	virtual void powerOn() { cout << "TV 전원 : " << on << endl; }
};

class IPtv : public Remote {
public:
	virtual void powerOff() { cout << "IP TV 전원 : " << off << endl; }
	// virtual void powerOn() { cout << "IP TV 전원 : " << on << endl; }
};



class Device {
public:
	void deviceOnOff() {
		if (remote != NULL) {
			int power;
			cout << "1.ON  2.OFF > "; cin >> power;

			if (power == 1)
				remote->powerOn();
			else if (power == 2)
				remote->powerOff();
		}
		else {
			cout << "- 장치를 선택하세요 -" << endl;
		}
	}

	void devicePower() {
		bool run = true;
		while (run) {
			int select;
			cout << "1.TV  2.IPTV  3.on/off > "; cin >> select;

			switch (select) {
			case 1:
				remote = tv;
				break;
			case 2:
				remote = iptv; //2번 객체와 연결
				break;
			case 3:
				deviceOnOff();
				break; // 현재 연결된 객체의 온오프 설정
			case 0:
				run = false;
				break;
			}
		}
	}

	~Device() {
		delete tv;
		delete iptv;
	}

	Device() {
		remote = NULL;
		tv = new Tv;
		iptv = new IPtv;
		devicePower();
	}

private:
	IPtv* iptv;
	Tv* tv;
	Remote* remote;
};


int main() {

	Device* device = new Device;
	delete device;

	//Remote* test = new Remote; error. 순수 가상 함수를 가지고는 객체 생성 불가능.

	Remote* remote = NULL;
	Tv* tv = new Tv;
	IPtv* it = new IPtv;

	remote = tv;
	remote->powerOn();
	remote->powerOff();
	cout << endl;

	remote = it; // iptv객체를 연결하면
	remote->powerOn();
	remote->powerOff();
}

