// 주석처리 : Ctrl + k + c
// 주석해제 : Ctrl + k + u
// 이전단계 : Ctrl + z
// 되돌리기 : Ctrl + y

// build   : Ctrl + Shift + b
// execute : Ctrl + F5

#include<iostream>
/*
cout
- cout은 왼쪽 쉬프트 연산자(<<)뒤에 있는 내용을 출력합니다

:: => scope 연산자;특정공간에 접근할 때 사용

end1; 라인변경

*/
int main() {

	std::cout << "출력할 내용 작성"<< std::end1;
	std::cout << "또 쓸말잇으면 이렇게 작성^^" << std::end1;
	std::cout << std::end1; /*끝에는 항상 이렇게 해줘야 함*/

		int a = 10;
		std::cout << "a : " << a << std::end1;
		std::cout << std::end1;

		/* int(정수) 하고 데이터값 넣음
		c에서는 printf를 하지만 c++에서는 변수명만 사용함*/

		double b = 2.2;
	std::cout << "b : " << b << std::end1;
	std::cout << std::end1;

	std::cout << "a : " << a << ",b:" << b << std::end1;
	/*파일이 바뀔 때 마다 >>로 출력해주기~~ */
	}