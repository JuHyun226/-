//ch11_default-parameter.cpp
// 디폴트 매개변수(default parameter) = 매개변수에 기본값을 부여하는 것.
// - 함수 호출 시 전달되는 값이 있으면 해당 인자값으로 실행하고, 
// 전달되는 인자값이 없으면 매개변수가 가진 기본값으로 실행함.
// -디폴트 매개변수의 값은 "오른쪽"에서부터 설정한다.
// - 디폴트 매개변수와 함수 오버로딩을 동시에 구현할 때에는 명확히 구분할 수 있게 해야 함.
// - 함수를 선언과 정의로 나누어서 구현 할 때에는 디폴트 매개변수 값의 설정은 선언부에만 작성해야 함.

#include <iostream>
#include <string>

using namespace std;

void ShowData(int arg) {
	cout << arg << endl;
}

int InputData(string message = "정수입력 < ") { //c+은 매개변수에게도 값을 부여할 수 있음.
	int data;
	cout << message;
	cin >> data;
	return data;
}


int main() {

	int value = InputData("숫자입력 > ");
	ShowData(value);

	int data = InputData(); // 쟤한테 기본값이 있기에 보내지 않아도 실행된다. => 하나로 여러개의 함수 만든 효과
	ShowData(data);
}



//-------------------------------------------------------

int main() {

	int resA = MultiData(); // 이 멀티데이터는 바로 위나 저 위에서 둘다 가져올 수 있으니까 헷갈리게 됨. 하나만 사용하라
	cout << resA << endl;

	int resB = MultiData(3); //3의 제곱이 나옴.
	cout << resB << endl;


}


int MultiData(int n = 2, int e = 2) { // 디폴트 변수를 왼쪽에는 주고 오른쪽에는 안주면 error가 남. 
////int MultiData(int n = 2, int e) { Error		
									  // 오른쪽을 비워둬선 안됌. int e) no! 오른쪽부터 넘겨받기에.
	int res = n;						// but 왼쪽 껄 지우면 이건 not error but 맨 첫번째만 
	for (int i = 1; i < e; i++) {
		res *= n;
	}
	return res;
}

//왜 class가 좋냐-------------------------------

class Calc {//calc라는 클래스 공간
public:
	int n;
	int e;
	int res; //class에는 data도 들어올 수 잇고

	int multiData(int _n = 2, int _e = 2) {
		n = _n;
		e = _e;
		res = n;
		for (int i = 1; i < 3; i++) {
			res *= n; // res 곱하기 는 n
		}
		return res;
	}

	void multiRes() {
		cout << n << " 의 " << e << "승: " << res << endl;
	}
};


int main() {

	Calc data; //Calc class에 객체 하나 만듬
	data.multiData(); // multidata함수 실행시키면
	data.multiRes();

	data.multiData(4); 
	data.multiRes();

	int n;
	int e;
	int select;
	Calc value;
	cout << "1. n제곱 2. n의 지수승 > ";
	cin >> select;
	

	switch (select) {
	case 1:
		cout << "숫자입력 > "; cin >> n; // n한테 입력받음
		value.multiData(n);
		break;
	case 2:
		cout << "숫자입력> "; cin >> n;
		cout << "지수승 입력> "; cin >> e;
		value.multiData(n, e);
		break;
	}
	value.multiRes();

}


