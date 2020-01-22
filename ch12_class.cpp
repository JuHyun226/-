//ch12_class.cpp

#include <iostream>	
#include <string>

using namespace std;

/*
객체 지향 프로그램( OOP: Object Oriented Program )
-여러개의 객체들간의 상호관계를 이용해서 프로그램을 만드는 것.

class
- 어떠한 사물의 특징을 소프트웨어적으로 정의한 것.
 > class는 객체가 아닌, 객체를 만들기 위한 설계도.

 객체(instance = 실체)
 - class를 이용하여 생성된 것.

 Ex> class 클래스명{
	접근제한자:
		멤버필드(멤버변수); //데이터 저장소
		> class 안에 만들어진 변수: 사물의 속성, 상태값

		메소드(멤버함수); // class안에 함수를 만들 수 있음.
		> class 안에 만들어진 함수: 사물의 행위, 동작 표현 --> 기능구현
	 };
*/

class data {
public:
	int value; //정수값 저장 필드 만듦.

	void input(string message = "숫자 입력 > ") { //메소드(함수)를 만듦
		cout << message;
		cin >> value; // 같은 공간안에 있기에 class안의 멤버필드를 직접 사용할 수도 있음
	} 

	void output(){ //출력하는 기능의 함수 만들기
		cout << value << endl; //value의 값 출력
};



int main() {

	Data dataA; //data class의 객체를 만듦
	dataA.value = 100; //A에게 값을 100을 넣음
	dataA.output(); // 값을 출력해주는 output 메소드가 cout 대신하여 있음.
	dataA.input(); // 값을 입력하고 싶으면 input을 사용하라.
	dataA.output(); // 입력한거 확인하려면 일케 하면 됨. 한번 만들면 그때부터 가져다 쓰면 되고 다시 칠 필요가 없다는 것.
	cout << endl;

	Data dataB;//필요한 만큼 또 만들면 됌.

}

