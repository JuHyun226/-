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
   return arg*arg;
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













