//ch10-Quiz_function-overloading.cpp


#include <iostream>	
#include <string>

using namespace std;

void Input(string message, int* arg) {
	cout << message;
	cin >> *arg;
}
void Input(string message, double* arg) {
	cout << message;
	cin >> *arg;
}
void Input(string message, char* arg) {
	cout << message;
	cin >> *arg;
}

void ShowData(int a, int b) {
	cout << a << ", " << b << endl;
}

void ShowData(double a, double b) {
	cout << a << ", " << b << endl;
}

void ShowData(char a, char b) {
	cout << a << ", " << b << endl;
}

void SwapData(int* pA, int* pB) {
	int tmp = *pA;
	*pA = *pB;
	*pB = tmp;
}

void SwapData(double* pA, double* pB) {
	double tmp = *pA;
	*pA = *pB;
	*pB = tmp;
}

void SwapData(char* pA, char* pB) {
	char tmp = *pA;
	*pA = *pB;
	*pB = tmp;
}

int main() {

	// 함수 오버로딩을 사용해서 아래의 문제를 해결하세요

	// 정수, 실수, 문자 하나를 입력처리 하는 함수를 각각 구현하세요: 값을 사용도 쓰기도 하고싶으면 주소를 보내고 int iA; Input(&iA);
																	// 싫으면 반환써서 쓰게 만들어 줘야지!
	// 같은 타입의 데이터 두개의 값을 교환하는 함수를 구현하세요
	// - 정수, 실수, 문자
	
	int iA, iB;
	Input("첫번째 정수 입력 > ", &iA);
	Input("두번째 정수 입력 > ", &iB);
	ShowData(iA, iB);
	SwapData(&iA, &iB); // change 주소의 값.
	ShowData(iA, iB);
	cout << endl;

	double dA, dB;
	Input("첫번째 실수 입력 > ", &dA);
	Input("두번째 실수 입력 > ", &dB);
	ShowData(dA, dB);
	SwapData(&dA, &dB);
	ShowData(dA, dB);
	cout << endl;

	char cA, cB;
	Input("첫번째 문자 입력 > ", &cA);
	Input("두번째 문자 입력 > ", &cB);
	ShowData(cA, cB);
	SwapData(&cA, &cB);
	ShowData(cA, cB);
	cout << endl;
}
