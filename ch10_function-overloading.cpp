//ch10_function-overloading.cpp
// 함수 오버로딩(function overloading) = 같은 이름의 함수를 여러개 정의하는 것
// - 매개변수 갯수, 타입(자료형) 순서만 다르면 이름이 같아도 다른 함수로 인식함.

// c에서는 함수이름으로 함수 구분하는데, c+는 함수이름과 매개변수까지 구별해서 구분하기에 매개변수만 달라도 다른걸로 인식함
// 그래서 매개변수 갯수나 자료형만 바꿔주면 같은 함수이름으로 여러개 만들 수 있는데 이것이 바로 함수 overloading.

#include <iostream>

using namespace std;

void ShowData(int arg) {
	cout << "정수: " << arg << endl;
} // 해당 데이터 출력하는 함수

void ShowData2(double arg) {
	cout << "실수: " << arg << endl;
}

void ShowData(int a, double b) { //갯수가 바뀜
	cout << "정수: " << a << ", 실수: " << b << endl; 
}

void ShowData(double a, int b) {
	cout << "실수 : " << a << ", 정수 : " << b << endl; //// a랑 b를 double이 a로, int를 b로 바꿔도 구분함. ==> ShowData(vB, vA); => 실수: 2.2, 정수: 10
}

void ShowData(int a, int b) {
	cout << "정수 : " << a << ", 정수 : " << b << endl;
}

int main() {

	int vA = 10;
	ShowData(vA);

	double vB = 2.2;
	ShowData(vB); //c+은 함수 호출시에도 casting이 발생해서 받을 수 있는 걸 받기에 no error. 제대로 하려면 더블을 넘겨받는 함수 만들어야 겠으니 만듬.
	ShowData(vA, vB);
	ShowData(5, vA); //5를 a에도 넣을 수 있는 상태가 되어서 error 발생. 
}
