// ch12-Quiz_class.cpp
// 멤버필드와 매개변수 이름은 동일하면 안됌.
#include <iostream>
#include <string>

using namespace std;

//Toy class를 정의하고 테스트하세요

class Toy {
public:
	// 멤버필드: 이름, qnvna1, qnvna2
	string name;
	string partsA;
	string partsB;

	// 기능 2개 이상 구현, 정보(멤버필드) 출력
	void setToy(string _name = "none", string _partsA = "팔", string _partsB = "다리") {
		name = _name;
		partsA = _partsA;
		partsB = _partsB; // 이건 왜 언더바 넣음? =? 매개변수와 필드값이랑 같으면 안됨. 이름중복임. 구분이 가능해야 함.
		// 그래서 매개변수에 언더바를 붙여놓은 것임. 새로운 이름 만들기에는 귀찮으니까.
		// 함수 호출 시 사용을 할 수 있는 값들을 넘겨라.
	}

	void movePartrsA() {
		cout << partsA << "을(를) 사용합니다" << endl;
	}

	void movePartsB() {
		cout << partsB << "을(를) 사용합니다" << endl;
	}

	void info() {
		cout << "이름   : " << name << endl;
		cout << "부품 A : " << partsA << endl;
		cout << "부품 B : " << partsB << endl;
	}
};

int main() {

	Toy toyA;
	toyA.setToy("레이싱카", "바퀴", "모터");	//toyA의 setToy
	toyA.info();
	toyA.movePartsA();
	toyA.movePartsB();
	toyA.partsB = "고속 모터";	//toyA의 partB의 값을 고속모터로 바꿈
	toyA.info();

}

//----------------------------------------------
/*
Data class 를 정의하고 테스트 하세요
- 인자값: 어떤 함수를 호출시 전달되는 --값(Argument)
- 매개형식변수: 전달된 인자를 받아들이는 --변수(Parameter)

인자는 Func() 함수를 호출할때 전달돼는 int MyAge에서 MyAge 이고
Func() 함수 구현 부의 헤더 부( 함수이름, 반환값, 매개 변수 )의 (int A)가 매개 형식 변수이다.
*/

class Data {
public:

	// 하나의 자료형 값을 입력하고 반환하는 각각의 메소드를 구현하세요
	// - int, double, char, string 
	int InputInteger(string message = "숫자 입력 > ") {
		int value;
		cout << message; cin >> value;
		return value;
	}

	double InputDouble(string message = "실수 입력 > ") {
		double value;
		cout << message; cin >> value;
		return value;
	}

	char inputCharacter(string message = "문자 입력 > ") {
		char value;
		cout << message; cin >> value;
		return value;
	}

	string inputString(string message = "단어 입력 > ") {
		string value;
		cout << message; getline(cin, value);
		return value;
	}

	// 하나의 인자값을 넘겨받아서 출력하는 각각의 메소드를 구현하세요
	// - int, double, char, string
	void showData(int arg = 0) {
		cout << arg << endl;
	}

	void showData(double arg = 0) {
		cout << arg << endl;
	}

	void showData(char arg = ' ') {
		cout << arg << endl;
	}

	void showData(string arg = "none") {
		cout << arg << endl;
	}
};

int main() {

	Data data;

	int vA = data.inputInteger();
	data.showData(vA);
	cout << endl;

	double vD = data.inputDouble();
	data.showData(vD);
	cout << endl;

	char vC = data.inputCharacter();
	data.showData(vC);
	cout << endl;

	cin.ignore(10, '\n');
	string stn = data.inputString();
	data.showData(stn);

}
