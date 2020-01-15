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

endl; 라인변경 (Abbrebiation of END Line)

*/
int main() {

	std::cout << "출력할 내용 작성"<< std::endl;
	std::cout << "또 쓸말잇으면 이렇게 작성^^" << std::endl;
	// std::cout << std::endl; /*끝에는 항상 이렇게 해줘야 함 - Not Necessary*/

	int a = 10;
	std::cout << "a : " << a << std::endl;
	std::cout << std::endl;

	/* int(정수) 하고 데이터값 넣음
	c에서는 printf를 하지만 c++에서는 변수명만 사용함*/

	double b = 2.2;
	std::cout << "b : " << b << std::endl;
	std::cout << std::endl;

	std::cout << "a : " << a << ",b:" << b << std::endl;
	/*파일이 바뀔 때 마다 >>로 출력해주기~~ */
}

// Fix Log: Hyecheol (Jerry) Jang
// 1. In order to end the line, use endl, not end1
// 2. No need to write "cout << endl;" at the end. If you want to make a line indent, use \n.
//    See this article for more information about Escape Sequence: https://en.wikipedia.org/wiki/Escape_sequences_in_C
// 3. Fix Indentation: Proper indentation is important for code readability
