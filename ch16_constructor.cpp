/*
	ch16_constructor.cpp
*/

#include <iostream>
#include <string>

using namespace std;
// 클래스도 선언과 정의를 함수처럼 따로 할 수 있음.
// 메소드 정의한걸 외부로 뺄 수 있음.
/*
생성자 ( constructor )
- class 명과 동일한 이름으로 선언하며 객체를 초기화하는 용도
- 객체가 생성될 때 자동 실행됨
- 생성자를 정의하지 않으면 아무것도 실행하지 않는 default 생성자가 자동으로 만들어져 실행됨
  생성자를 하나라도 정의하면 default 생성자는 자동으로 만들어지지 않습니다
- 매개변수를 사용 할 수 있기 때문에 오버로딩 가능
- 메소드의 형태이긴 하지만 반환값 정의불가
- 별도로 호출해서 사용불가
*/

//class Base {
//private:
//	int value;
//
//public:
//
//	Base() {
//		cout << "--- Base 생성자 ---" << endl;
//		value = 0;
//	}
//	
//	Base(int _value) {
//		cout << "--- Base 생성자 2 ---" << endl;
//		value = _value;
//	}
//
//	int getValue() { return value; };
//	void setValue(int _value) {
//		value = _value;
//	}
//
//	void showValue() {
//		cout << "value : " << value << endl;
//	}
//
//};
//
//int main() {
//
//	Base ob1;
//	//ob1.setValue(10);
//	ob1.showValue();
//
//	Base ob2(111);
//	ob2.showValue();
//
//	Base* pob = new Base;
//
//	delete pob;
//
//}

//--------------------------------------------------------------------
class Total {
private:
	int dataA;
	int dataB;
	int tot;

public:

	Total() {
		dataA = 1;
		dataB = 10;
		lastTotal();
	}

	Total(int last) {
		dataA = 1;
		dataB = last;
		lastTotal();
	}

	Total(int argA = 10, int argB = 1) {
		dataA = argA;	// data A 필드에게는 첫번째 변수 매개변수 값을 넘기고,...
		dataB = argB; // 디폴트 매개변수 중요.
		if (argA > argB) {
			dataA = argB;
			datgB = argA;
		}
		lastTotal();
	}


	void lastTotal() {
		tot = 0;
		for (int i = dataA; i <= dataB; i++) {
			tot += i;
		}
	}

	void showTotal() {
		cout << dataA << " ~ " << dataB << " 까지의 합 : " << tot << endl;
	}

};

int main() {

	Total ob1;
	ob1.showTotal();

	Total ob2(5);
	ob2.showTotal();

	Total ob3(5, 2);
	ob3.showTotal();

}
// DEFAULT 매개변수 쓸 때 OVERLOADING 조심! 하나로 여러 효과를 발생시켜 중복처리 될 수 있기에.

// 위에서 메소드를 다 빼내는 방법(클래스 내부를 간결히 만들 수 있다) ---------------------------------------------
// SCOPE 연산자를 통해서 누구 클래스의 메소드인지 지정! => 메소드 명을 앞에
// 디폴트 매개변수 값은 선언부에만 작성하라

class Total {
private:
	int dataA;
	int dataB;
	int tot;

public:

	Total(int argA = 10, int argB = 1);
	void lastTotal();
	void showTotal();

};

int main() {

	Total ob1;
	ob1.showTotal();

	Total ob2(5);
	ob2.showTotal();

	Total ob3(5, 2);
	ob3.showTotal();

}


Total::Total(int argA, int argB) {
	dataA = argA;
	dataB = argB;
	if (argA > argB) {
		dataA = argB;
		dataB = argA;
	}
	lastTotal();
}

void Total::lastTotal() {
	tot = 0;
	for (int i = dataA; i <= dataB; i++) {
		tot += i;
	}
}

void Total::showTotal() {
	cout << dataA << " ~ " << dataB << " 까지의 합 : " << tot << endl;
}
