// ch09_macro_inline.cpp
//매크로는 자주 바뀌는 상수나 간단한 공식, 타인의 코드를 갖다 쓸 때, 코드 수정시 편리하고 빠르기에 많이 사용.
// 근데 매크로 잘못하면 에러를 못 잡음
// debug에는 변수들은 나오지만 매크로 값이 나오지 않음,.,, ㅠ	
#include <iostream>

using namespace std;

#define PI 3.141592
//정의한 PI를 죄다 찾아서 그 뒤에 정의한 값으로 바꿔버림.

#define SQUARE(n) n * n
//함수형태로도 사용가능

#define ARRAY_SIZE 3

int main() {

	int ar[ARRAY_SIZE];

		//배열안에 크기값([ ])으로 상수만 써야 함. 변수는 못 씀. 근데 macro 값은 사용가능.

	cout << "원주율 : " << PI << endl;
	cout << "4의 제곱 : " << SQUARE(4) << endl;
	// 주의: cout << "4의 제곱 : " << SQUARE(2+2) << endl; 는 제대로 된 값이 안나옴.
	// B/C 매크로는 우리가 정의한 그대로만 바뀌기에 2+2*2+2가 되기에 연산자 우선순위에 따라 곱하기가 먼저.
	// 이거까지도 정상화 처리할려면 #define SQUARE(n) (n) * (n) n을 괄호로 묶어라

}

//inline-------------------------------------------------

#include <string>

void DefaultFunc(string message) {
	cout << message << endl;
}

inline void InlineFunc(string message) {
	cout << message << endl;
}

inline int DataSquare(int n) {
	return n * n;
}

int main() {

	DefaultFunc("일반 함수");

	InlineFunc("inline 함수"); //Inline 함수: 함수 정의시 inline 키워드 붙히고 함수정의 가능 => inline void

	cout << DataSquare(2 + 2) << endl; // => 얘는 두개를 더한 값을 넘겨받으니 알아서 잘 나옴.

}
// 기본 일반 함수의 실행 과정: 함수메모리의 stack에서 실행됨. main함수를 호출, 거기에서 DefaultFunc 함수 호출 => stack에 defaultfunc함수 들어옴
// -> 거기에서 또 새 함수 호출하면 그 함수가 또 스택에 들어옴.
// -> cout해서 일반함수라고 message출력하면서 stack에서 빠져나가 처음으로 돌아옴.(대부분의 sys운영은 스택에서 => 자료구조 배워랏)
// main -> test -> func로 실행되면 종료는 "역순"으로 종료됨. 데이터가 들어왔다 나오는 입출구가 한군데 밖에 없기 때문.

// InlineFunc는 호출에 대한 실행과정이 없이 바로 코드를 가지고 stack(=쌓는다)안으로 끌여들여서 더 속도가 빠름.
//-> c+에서 코드가 짧은 애들을 인라인쓰기를 권장. visual studio에서는 상황에 따라 코드가 짧은 애들을 자동 인라인 처리함.

// stack는 동적할당에서 더 설명할 예정.
