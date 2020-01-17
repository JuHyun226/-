// ch05_function(함수).cpp

/*
함수 ( function )
- 하나의 기능을 가진 작은 프로그램
*/

// 함수 선언
// = 사용자가 정의한 함수가 있음을 알려주는 것
// - 매개변수까지 복사해서 main앞에까지 가져다 붙힌 후 세미콜론 붙이는 게 함수선언

// 함수 정의
// = 함수 호출(실행)시에 실행하는 코드를 정의한 곳

/* 표기
	반환타입 함수이름 ( 매개변수 O or X ) {
	실행코드 작성
	return 값; ( O or X )	} */

	// 반환타입 : 함수 종료시에 호출부로 돌아갈때 가져가는 값의 자료형
		// --> 반환값이 없으면 'void' 사용
	// 함수이름 : 함수 호출(실행)시에 사용하는 이름
	// 매개변수 : 호출부에서 넘어오는 값을 보관하는 변수
	// return : 함수 실행후에 나온 결과물을 호출부로 보낼 때 사용하거나,
			 // 함수 실행을 종료 시킬 때 사용
			 // 반환 할 수 있는 값은 딱 하나

// 함수 호출
	// - 표기: 함수이름(인자값데이터 o,x);
	// - 함수 정의부에 있는 매개변수와 타입, 갯수, 순서가 일치해야 함!

#include <iostream>
#include <iomanip>

using namespace std;

void Hi();//2번 hi 다시 1번으로 감.
void DataSend(int arg);

int main() {

	Hi();

	DataSend(10); //10은 밑의 arg로 보내짐. 다끝나면 호출
	int arg = 7; //숫자 직접 써도 되고 변수 써도 됨.
	DataSend(arg); //변수의 값이 넘어가는거지 변수가 넘어가는 것은 아님. copy해서 넘기는 거고, 직접 가는게 아님.

	// int a = 5;
	// int b = a; 여기서도 a가 직접 날라간게 아니라, a의 값이 간거니까.

	// Pi(); 이건 아무 소용이 없음 => 변수에 담던지 출력을 시켜라
	cout << Pi() << endl;

	int res = Square(2);
	cout << "2의 제곱 : " << res << endl;

}

int Square(int arg) {
	return arg * arg;
}


// 실수면 double, 함수면 pi로 return을 사용하여 값을 반환하라.
double Pi() {
	// return 3.141592;
	double pi = 3.141592;
	return pi;
}

void DataSend(int arg) {
	arg += 2; // 를 해도 데이터에 있는 arg 변수값만 바뀌는 것임
	cout << "받은 데이터 : " << arg << endl;
}

void Hi() {//2번 hi 다시 1번으로 감.
	cout << "안녕하슈~ ^^" << endl;
}


//---숫자를 입력해서 반환할 때-------------------------------

int InputData(); // 해당 함수 있다고 알려줘야 함

int main() {

	int a = InputData();
	cout << "a : " << a << endl;

	int b = InputData();
	cout << "b : " << b << endl;
	// 함수를 만들어 놓고 사용하는 이유, 필요시 그냥 호출해서 그때그때 쓸 수 있기에


}

int InputData() {
	int value;
	cout << "숫자 입력 > ";
	cin >> value;
	// 이상태면 호출은 못쓰게 되는데
	return value;
	// 이 값을 호출지역으로 보내서 사용하게 함.
}

//-배열에서 ----------------------------------------

void InputArray(int* arr, int size);
void OutputArray(int* arr, int size);

int main() {

	int data[3];
	int dataSize = sizeof(data) / sizeof(int); // 크기가 바뀌어도 자동으로 처리하게 해주는 코드
	// 크기값도 구해놓고,


	InputArray(data, dataSize);
	OutputArray(data, dataSize);
	// 함수명을 inputArray라고 잡고, 위치와 크기를 같이 넘김. 
}

//--이 밑에 코드가 잘못된 예시인가?------------
// void InputArray(int* arr, int size) {
//	sizeof(arr) // 얘는 4바이트. 배열을 포인터에셔 다룰려면 위치와 크기 2개를 모두 알아야 함.
//	for (int i = 0; i < ) // i는 " "보다 작을 때까지 돌린다!!

//--------------------------------------

void OutputArray(int* arr, int size) {
		for (int i = 0; i < size; i++) {
			cout << setw(3) << arr[i];
		}
		cout << endl;
	}

void InputArray(int* arr, int size) {
		for (int i = 0; i < size; i++) {
			arr[i] = i + 1;
		}


}
//주소만 넘어오니까 매개변수는 당연히 포인터가 됌.
// FOR문 돌려서 값 입력



