/*
	ch07_bool.cpp
*/

#include <iostream>	

using namespace std;

/*
bool 자료형
-c++에서는 참/거짓의 값만을 가지는 위 자료형이 추가됨.
*/

int main() {

	cout << "true : " << true << endl;
	cout << "false: " << false << endl;
	cout << "bool 자료형 크기 : " << sizeof(bool) << endl;
	cout << endl;

	bool value = true;
	cout << "value : " << value << endl;
	// 자료형이기에 변수를 만들 수 있음.
}

//---------------------------------------------

int InputData() {
	int value;
	while (true) {
		cout << "숫자 입력 > "; cin >> value;
		if (value >= 0) // +데이터면 정상으로 처리
			break;
	}
	return value;
}

bool OddCheck(int data) {
	if (data % 2 == 1)
		return true;
	return false;
}

int main() {

	int data = InputData();

	if (OddCheck(data))
		cout << "홀수" << endl;
	else
		cout << "짝수" << endl;


}
