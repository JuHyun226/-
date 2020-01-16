// ch04_namespace.cpp

//std안에 cout,cin,endl이 있는 것처럼, 우리도 스스로 저런 걸 만들수 있는데 그게 네임스페이스!
//왜 만들었냐하면 하나의 변수를 다른데에 못 씀. 근데 공간(이등구간)이 새로 생기면(중괄호로) 가능.

#include <iostream>

namespace one {
	int a = 0;
  
  void showData(int arg) {
		std::cout << arg << std::endl;
	}
  //아는 함수 말고도 죄다 집어넣을 수 있음. 
}

namespace two {
	int a = 10000;
  
  void showData(char arg) {
		std::cout << arg << std::endl;
	}
  //여기에도 showdata써도 상관없음.//근데 저 arg가 뭐지.??
  
  namespace inner {
		int a = 10;
	}
  //해당 공간 안에서 새롭게 만드는 것도 가능
}

int main() {

	int a = 10;
  std::cout << "one::a : " << one::a << std::endl;  
  //해당 공간(one)을 쓰고 거기에 접근하겠다는 걸 말하기위해 scope연산자 사용! ==> 
  std::cout << "two::a : " << two::a << std::endl;
  
 
  one::showData(two::a); //one의 showdata함수를 사용하면서 two지역에 있는 변수 a를 보내도 됨.(해당 지역의 이름 쓰고 그 안에꺼 쓰기)
  two::showData('A'); //two지역의 showdata함수 쓰면 문자 하나 보내줘야겟죠.-왜 대문자 하나를 쓴 거지??

  two::a =12; //two의 a를 12로 바꾸고
  one::showData(two::a); //변경되어 있음.
  
  one::showData(two::inner::a); //inner구역의 a는 바로 못쓰고 two를 통해 나열-접근해야 한다.

	namespace twoin = two::inner; 
	one::showData(twoin::a); //왜 위치가 이렇게 되는건지 모르겟다??
  //how to use inner more convinient: namespace=> two::inner
  
  
  //int cin;
  //라이브러리 안에서 자주쓰는애들을 집어넣은거임. 
}
