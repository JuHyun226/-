/*
	ch20_member-initializer.cpp
	const를 사용한 memberfield를 중괄호 사용 대신 :을 사용하여 초기화 하는것

멤버 이니셜라이저 :::::::
- 생성자의 몸체('{}')보다 먼저 실행되기 때문에,
  대입연산자를 이용한 초기화보다 더 빠른 초기화가 가능
- const 선언된 멤버필드는 생성자에서 멤버 이니셜라이저를 사용해서 초기화 합니다

const instance
- const 선언된 객체를 생성 가능.
- const 선언된 메소드만 사용 가능.

const method
- const 선언된 메소드를 정의 할 수 있음.
  > 멤버필드를 사용만 할 수 있고, 수정 할 수 없음.
*/

#include <iostream>
#include <string>

using namespace std;


int main() {

	//const값이 어디에 붙느냐에 따라 그 값을 수정할 수 있는지 없는지에 대한 여부가 결정됨.
	
	const double PI = 3.141592;
	// PI = 3.14;

	// const int MAX; error. => const 선언한 건 수정이 불가능하기에, 만들자마자 값이 부여되야함.

	int a = 10;
	const int* pta = &a;
	// 포인터 변수의 값 변경 가능, 포인터 가리키는 공간의 값은 변경 불가
	// *pta = 20; error
	int n = 1;
	pta = &n;

	int b = 10;
	int* const ptb = &b;
	// const위치 때문에 포인터 변수의 값(ptb)을 못바꿈, 포인터가 가리키는 공간의 값은 변경 가능.
	*ptb = 20;
	// ptb = &n; error => ptb 자체의 값을 바꾸는 건 안됨

	int c = 10;
	const int* const ptc = &c;
		// 포인터 변수의 값, 포인터가 가리키는 공간의 값 둘다 변경 불가
		// *ptc = 20; Error
		// ptc = &n; Error

	// 포인터 자료명 전에, 변수명 전에 둘다 붙일 수 있음.

//--------------------------------------------------------------------

	class Data {
	private:
		const int value;
		string text;

	public:
		Data(int value = 0, string text = "none") : value(value){
			// this->value = value; // memberfield 생성 뒤에 대입하는 거라 error => : value field를 매개변수 (value)값을 대입시켜 초기화시켜서 먼저 작동하도록
			this->text = text;
		}

		string getText() { return text; }
		string getText() const { return text; }

		void setText(string text) {
			this->text = text;
		}

		//void setText(string text) const {
		//	// this->text = text; Error
		//}


		void info() {
			cout << value << ", " << text << endl;
		}

		void info() const {
			cout << "- info() const -" << endl;
			cout << value << ", " << text << endl;
		}
	};

	int main() {

		Data dataA(111, "dataA");
		dataA.info();
		cout << dataA.getText() << endl;
		cout << endl;

		const Data dataB(222, "dataB"); // const선언 되었으니 객체 자체가 상수화됨. 고로 memberfield값 수정불가
		dataB.info(); //dataB객체가 값을 꺼내와서 쓰려면 const된 데이터가 있어야 한단 소리!
		cout << dataB.getText() << endl;
		
		// const선언된 인포메소드 사용 없이 선언시, dataB.info(); error.
		// b/c 상수화된 객체는 일반 메소드를 사용할 수 없음. const선언된 메소드만 사용가능
		// => 메소드도 const 처리! 걔만이 사용할 수 있는 메소드를 따로 만들어야 함.
		// -  const선언하려면 메소드에다가 const 붙혀야함
	}

