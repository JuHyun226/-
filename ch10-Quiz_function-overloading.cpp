//ch10-Quiz_function-overloading.cpp

//??
#include <iostream>	

using namespace std;

void Input(int* arg) {
	cout << "숫자 입력 > ";
	cin >> *arg;
}

int main() {

	// 함수 오버로딩을 사용해서 아래의 문제를 해결하세요

	// 정수, 실수, 문자 하나를 입력처리 하는 함수를 각각 구현하세요: 값을 사용도 쓰기도 하고싶으면 주소를 보내고 int iA; Input(&iA);
																	// 싫으면 반환써서 쓰게 만들어 줘야지!
	// 같은 타입의 데이터 두개의 값을 교환하는 함수를 구현하세요
	// - 정수, 실수, 문자
	
	int iA;
	Input(&iA);

	int InputData() {
		int value;
		cout << "숫자 입력 > ";
		cin >> value;

		double v1() {

		}

	char text[20];
	cout << "문자 입력 > ";
	cin >> text ;

	
}
