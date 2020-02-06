/*
	ch24.2_inheritance2.cpp
*/

#include <iostream>
#include <string>

using namespace std;

/*
상속 ( inheritance )
- 다른 class 의 내용을 그대로 가져와서 새로운 class를 정의하는 것을 말합니다
- 상속받은 하위(자식)클래스는 상위(부모)클래스의 내용을 그대로 물려받아서 사용 할 수 있습니다
- 상속에서의 생성자와 소멸자 실행 순서
  > 생성자 : 부모클래스 생성자 -> 자식클래스 생성자
	소멸자 : 자식클래스 생성자 -> 부모클래스 소멸자
- 상위 클래스의 private 영역에는 접근 할 수 없습니다
*/

//class Base {
//public:
//	Base() { cout << "- Base 생성자 -" << endl; }
//	Base(int a) { 
//		cout << "- Base 생성자 2 -" << endl;
//		this->a = a; 
//	}
//	~Base() { cout << "- Base 소멸자 -" << endl; }
//private:
//	int a;
//};
//
//class Derived : public Base {
//public:
//	Derived() { cout << "- Derived 생성자 -" << endl; }
//	Derived(double b) : Base(0) { 
//		cout << "- Derived 생성자 2 -" << endl;
//		this->b = b; 
//	}
//	~Derived() { cout << "- Derived 소멸자 -" << endl; }
//private:
//	double b;
//};
//
//int main() {
//
//	Derived test;
//	Derived objA(1.1);
//
//}


//child 객체의 시작 주소 타입은 child 타입이 아닌 parent 타입------------------------------------------------------------------------
// 상위 애들부터 먼저 초기화 시켜라
class Parent {
public:
	void showNum() {
		cout << "No. " << num << endl;
	}
	void setNum(const int& num) { this->num = num; }
	int getNum() { return num; }
	Parent(const int& num = 0) : num(num) {}

private:
	int num;
};

class Child : public Parent {
public:
	void showChild() {
		// cout << getNum() << endl;
		showNum(); // private 말고 public에 있는 애들은 다 사용가능.
		cout << text << endl;
	}
	Child(const int& num = 0, const string & text = "none")
		: Parent(num), text(text) {}

private:
	string text;
};

int main() {

	Child child(11, "dataA");
	child.showChild();
	cout << child.getNum() << endl;
	child.setNum(22);
	child.showNum();

}

//---------------------------------------
class Person {
public:
	void setAge(const int& age) { this->age = age; }
	int getAge() { return age; }
	void setName(const string& name) { this->name = name; }
	string getName() { return name; }
	Person(const string& name = "none", const int& age = 0)
		: name(name), age(age) { }

private:
	int age;
	string name;
};

class Police : public Person {
public:
	void info() {
		cout << "--- 경 찰 정 보 ---" << endl;
		cout << "이름   : " << getName() << endl;
		cout << "나이   : " << getAge() << endl;
		cout << "계급   : " << rank << endl;
	}
	Police(const string& name = "none", const int& age = 0, const string & rank = "순경")
		: Person(name, age), rank(rank) {}

private:
	string rank;
};

class Celebrity : public Person {
public:
	void info() {
		cout << "--- 연예인 정보 ---" << endl;
		cout << "이름   : " << getName() << endl;
		cout << "나이   : " << getAge() << " 세" << endl;
		cout << "소속사 : " << agency << endl;
	}
	Celebrity(const string& name = "none", const int& age = 0, const string & agency = "프리랜서")
		: Person(name, age), agency(agency) {}

private:
	string agency;
};

int main() {

	Police* podol = new Police("포돌이", 22, "경감");
	podol->info();
	delete podol;

	Celebrity* yu = new Celebrity("유재석", 50, "FNC");
	yu->info();
	delete yu;



}
