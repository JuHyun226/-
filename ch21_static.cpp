/*
	ch21_static.cpp
	- 다 같이 쓰고, 한번의 변경으로 일괄 변경 적용하고 싶을 때 사용.
*/

#include <iostream>
#include <string>

using namespace std;

//1. ------------------------------------------------------
int g;

void StaticFunc(); //해당 함수 내에서만 전역처럼 쓰임.

int main() {

	cout << "전역 g: " << g << ", 주소: " << &g << endl;

	int a = 10;
	cout << "main a: " << a << ",주소: " << &a << endl;

	StaticFunc();
	StaticFunc();

	// cout<<s<<endl; error. => static변수: 해당 지역 밖에서 사용불가.
}

void StaticFunc() {
	int a = 20;
	cout << "func a: " << a << ", 주소:" << &a << endl;


	static int s = 1; //static 변수 = 전역변수와의 시작 주소가 동일. => 만들어지는 곳 = 전역변수와 같은 메모리.
	cout << "static s: " << s << ", 주소: " << &s << endl;

	cout << "전역 g : " << g << ", 주소 : " << &g << endl;

	a += 100; //지역변수: 새로 호출시 새 값을 받아 실행하기 때문에 종료시 마지막 데이터 유지불가.
	++s; // static변수: 함수 종료시에도 데이터를 유지(전역변수와 비슷: 프로그램 생성 동시에 생성, 종료시 동시에 소멸.)
}

//2. static field는 따로 빠져있음.---------------------------------------------------------------------
class Unit {
public:
	static void showCnt() {
		cout << "멤버 수 : " << cnt << endl;// static 선언되면 객체와 상관없이 해당 메소드를 static으로 만들어 class로 바로 접근 가능
		//cout << hp << endl; Error. static 아닌 거는 객체 없이 instance number 사용 불가
	}


	static void setCnt(int _cnt) {
		cnt = _cnt;
	}

	static void setTeam(const string& _team) {
		team = _team;
	}//static field: 객체 고유의 값이 아니기에 this pointer 사용 불가능 = > 매개변수 명 같은 걸 사용하면 안됨.
	
	void info() {
		cout << "- " << team << " 팀 -" << endl;
		cout << name << " - " << hp << endl;
	}

	void setName(const string& name) {
		this->name = name;//instance field: this pointer 사용가능, 매개변수 같은 이름 사용 가능.
	}

	Unit(const string& name = "none", int hp = 0) : name(name), hp(hp) {
		++cnt;
		this->hp += 100; // 일반 멤버필드: 계속 올라가지 않음, 객체 고유의 값(instance numb). 첫째도 100, 둘째도 100
							// static : 공용/공통의 멤버
		cout << "- " << cnt << " 번째 객체 생성 -" << endl;
		cout << "체력 : " << hp << endl;
		
		/*cout << &this->hp << ", " << &cnt << endl; */ 
		// hp는 instance라서 다른 공간에 만들어짐, static은 같은 공간에 만들어져서 한개가 바뀌면 다른 것도 바뀜.
	}

private: // memberfield에도 static 사용가능
	static string team;
	static int cnt;
	string name;
	int hp;
};


// static 변수는 생성자가 아닌 "클래스 밖에서 초기화" 시켜야함.
string Unit::team = "none";
int Unit::cnt = 0;

int main() {

	Unit::showCnt();//static: 객체 없이 사용 가능.
	Unit::setTeam("알파");//class명으로 접근

	Unit unitA("unitA");//Unit 클래스에 unit객체생성 
	Unit unitB("unitB");

	unitA.setCnt(0);//클래스 명 말고도 객체로도 접근 가능. 0으로 바뀜.
	unitB.showCnt();

	unitA.info();// unit A, B 다 알파로 설정됨
	unitB.info();

}
