// ch03_cpp_etc.cpp

#include <iostream>
#include <iomanip> 

int main() {

	int v1 = 10;
	std::cout << "v1 : " << v1 << std::endl;

	int v2(100);
	std::cout << "v2 : " << v2 << std::endl;

	auto v3 = 1.2;
	std::cout << "v3 : " << v3 << std::endl;
//auto가 뭐지

	int v4 = 65;
	std::cout << "v4 : " << v4 << std::endl;
  std::cout << "(char)v4 : " << (char)v4 << std::endl; //0~127까지 숫자는 아스키코드 때문에 문자로도 숫자로도 사용가능
	std::cout << "char(v4) : " << char(v4) << std::endl; //c+에서는 반대로 자료형 써주고 변환할 애를 괄호로 묶을 수도 잇음

	int v5 = 123;
	printf("%5d\n", v5); //출력시 다섯칸의 공간을 확보하고 출력시켜라
	std::cout<< std::setw(5) << v5 //확보할 공간을 괄호 속에 입력. iomanip라는 헤더파일을 추가해야함.
                                //서식지정자 사용시 출력때 컨트롤이 가능
                                //c타입이 더 편함. 그래서 코드혼용해서 쓰기도 함.

  double v6 = 12.1234567;
	std::cout << "v6 : " << v6 << std::endl;
//c+에서는 실수데이터 출력시 전체 6자리만 기본출력이라서 잘림.
  std::cout << std::setprecision(9) << v6 << std::endl;
// 전체를 다 하고싶으면 출력할 자리수, 전체자리수 지정 필요.=>setprecision 함수 사용
// 근데 왜 9칸이지...?

}
















