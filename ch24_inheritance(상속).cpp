/*
	ch24_inheritance(상속).cpp
	- 다른 클래스의 내용을 그대로 가져와서 새로운 클래스를 정의하는 것
	- 상속받은 하위(자식)클래스는 상위(부모)클래스읭 내용을 그대로 물려받아서 사용할 수 잇음
	- 상속에서의 생성자멸자 실행 순서
		> 생성자: 부모클래스 생성자 -> 자식클래스 생성자
		  소멸자: 자식클래스 생성자 -> 부모클래스 소멸자
	- 상위 클래스의 private 영역에는 접근 불가


	= 클래스를 만들 때 다른 클래스의 내용을 그대로 가져다 쓰는 것
	- 방법: class Derived : public 가져올클래스명 { };
	- 순서중요~!!: 상위 클래스인 가져올클래스(Base)가 먼저 실행되고 나서 derived(내꺼)가 실행되고 소멸은 derived 빠져나간후 Base가 나감.
		> test -> Base(상위 클래스) 먼저 실행->끝난 후 자기 자신의 것(Derived) 실행.
	- 시작 주소 타입: Base 타입.
	*/

#include <iostream>
#include <string>

using namespace std;

class Base {
public:
	Base() { cout << "-Base 생성자-" << endl; }// 생성자, 얘가 없으면 derived 생성자에서 error가 남. b/c 디폴트 생성자가 없어서.
	Base(int a) {
		cout << "-Base 생성자-" << endl;
		this->a = a;
	}// 생성자는 아니고 값을 넘겨받음. 매개변수 a는 a로 초기화
	~Base() {cout << "-Base 소멸자-" << endl;} //소멸자
private:
	int a;
};


class Derived : public Base {
public:
	Derived() { cout << "- Derived 생성자 -" << endl; } // : Base() = 베이스의 생성자를 실행하시오가 자동으로 들어가 잇었음.
	Derived(double b) : Base(0) { 
		cout << "-Derived 생성자 2-" << endl;
		this->b = b;
	} //0을 넘기면서 error 사라짐. 값을 넘겨받으면서 base를 실행시키기 때문에.
	~Derived() { cout << "-Derived 소멸자-" << endl; }
private:
	double b;
};

int main() {

	Derived test;
	Derived objA(1.1);	// 객체 하나 더 만들어서 실수 값 넘겨줌.
}
