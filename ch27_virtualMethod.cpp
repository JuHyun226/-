// ch27_virtualMethod.cpp

/*
가상함수 ( virtual method )
- 'virtual' 키워드를 사용해서 만들 메소드입니다
- 자식클래스의 객체를 부모클래스의 포인터로 호출하면 재정의 전의 부모클래스의 메소드를 실행합니다
  이때, 재정의한 자식클래스 객체의 메소드를 사용하고 싶으면
  부모클래스의 메소드 앞에 'virtual'을 선언합니다
*/


#include <iostream>
#include <string>

using namespace std;

class Super {
public:
	virtual void showData() { // 부모 메소드에 virtual 키워드 붙혀서 실행시 본래의 메소드가 실행됨.
		cout << "data : " << dataA << endl;
	}
	int getDataA() { return dataA; }
	Super(const int& dataA = 0) : dataA(dataA) {}

private:
	int dataA;
};

class Sub : public Super {
public:
	void showData() {
		cout << "data : " << getDataA() << ", " << dataB << endl;
	}
	Sub(const int& dataA = 0, const double& dataB = 0) : Super(dataA), dataB(dataB) {}

private:
	double dataB;
};

int main() {

	Sub* sub = new Sub(11, 2.2);
	sub->showData();
	cout << endl;

	Super* super = sub;
	super->showData();
	super->Super::showData(); //virtual에 선언된 showdata는 이렇게 사용가능
	

}
//동적 바인딩: 메소드가 프로그램 실행 중간에 선택됨.-----------------------------------------------------

/*
바인딩
- 함수 호출과 실제 함수를 연결하는 방법을 말합니다

정적 바인딩
- 컴파일 때 호출함수가 결정됩니다

동적바인딩
- 런타임(프로그램 실행 중)에 호출 함수가 결정됩니다

*/

class Driver {
public:
	virtual void driving() { cout << "- 자동차를 운전합니다 -" << endl; }
};

class Taxi : public Driver {
public:
	void driving() { cout << "- 택시를 운전합니다 -" << endl; }
};

class Bus : public Driver {
public:
	void driving() { cout << "- 버스를 운전합니다 -" << endl; }
};

class Car {
public:
	void drive() {
		int select;
		cout << "1.택시  2.버스 > "; cin >> select;
		if (select == 1)
			user = taxi;
		else if (select == 2)
			user = bus;
		else
			user = NULL;
		if (user)
			user->driving();
	}
	~Car() {
		delete taxi;
		delete bus;
	}
	Car() {
		user = NULL;
		taxi = new Taxi;
		bus = new Bus;
	}

private:
	Bus* bus;
	Taxi* taxi;
	Driver* user;
};

int main() {

	Car* car = new Car;
	car->drive();

	delete car;

}


//downcasting때마다 변환타입을 확인할 수 있는데 이때 쓰는게 dynamic cast.---------------------
/*
dynamic_cast
- 다운캐스팅시 타입 변환이 안전한지 확인합니다
  변환이 안되면 NULL 값을 반환합니다

  Ex> dynamic_cast<변환타입>(변수)
*/

class Parent {
public:
	virtual void useInfo() {
		cout << "- Parent -" << endl;
	}
};

class TypeA : public Parent {
public:
	void useInfo() {
		cout << "- Type A -" << endl;
	}
};

class TypeB : public Parent {
public:
	void useInfo() {
		cout << "- Type B -" << endl;
	}
};

int main() {

	Parent* parent = NULL;
	TypeA* ta = new TypeA;
	TypeB* tb = new TypeB;

	parent = ta;
	//ta = (TypeA*)parent;
	ta = dynamic_cast<TypeA*>(parent); // 이 주소가 참조하는 객체타입을 넘기거나 없으면 null값.
	if (ta) {
		ta->useInfo();
	}//맞으면 useInfo 메소드를 실행시켜라.

	//tb = (TypeB*)parent;
	tb = dynamic_cast<TypeB*>(parent);
	if (tb) {
		ta->useInfo();
	}
	else {
		cout << "변환 불가~" << endl;
	}
	//tb->useInfo();

}
