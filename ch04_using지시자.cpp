/*using 지시자*/ //=> 앞으로는 걍 선언해서 쓰세요. 긴 코드 쓸일이 없으니. 그닥 좋지 않은 것만 알고 있으세요. 외국에서는 안 씀.

//예전에는 scope연산자(std) 명시하고 썼는데 이건 direct 가능

#include <iostream>

using namespace std;

int main() {

	int a;
	cout << "숫자 입력 > ";
	cin >> a;
	cout << "a : " << a << endl;

}

// but it ain't good method. just for 충돌방지용(중복방지)인 규칙을 강제로 깨뜨렸기 때문

/* about programming
파이썬-라이브러리가 많아서 디테일하게 코드 작성할 필요 없어서 코드작성이 편함. java랑 같이 속도 느림.
c++: 라이브러리 많고(17ver) 속도가 빠름
c는 잘 안 쓰고 더이상 변화 x. 그치만 iot에서 많이 씀. 편하고 간단해서. sys에 direct로 붙어서 저사양에도 빠르게 돌아감.
*/


// 부분적으로도 선언 가능
/*using선언을 main안에 했으면 오류뜨고, 오류 없애려면 전역(main)으로 들어와야 함.*/
using std::cout; //cout 자주 쓸거면 이게나음 = std의 cout 자주 사용하겠습니다
using std::cin;
using std::endl;

int main() {

	int a;
	cout << "숫자 입력 > ";
	cin >> a;
	cout << "a : " << a << endl;

  testFunc();
}

void testFunc() {
	cout << "- testFunc() -" << endl;
}


//or 전역선언(main 밖에 선언) 말고 함수안으로 끌어들여 쓰기도 가능

int main() {

	using std::cout;
	using std::cin;
	using std::endl;

	int a;
	cout << "숫자 입력 > ";
	cin >> a;
	cout << "a : " << a << endl;

  }
