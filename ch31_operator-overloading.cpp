// ch31_operator-overloading.cpp

/*
연산자 오버로딩 ( operator overloading )
- cpp 의 기본연산자를 재정의 하는 것을 말합니다
- cpp 에서는 연산자도 함수를 취급하기 때문에 함수를 정의하는 것과 같은 방식으로 연산자 사용이 가능합니다
- 함수 이름 대신에 'operaotr'키워드를 사용합니다
- 객체끼리의 연산이 가능해집니다
- 오버로딩이 불가능한 연산자
  > sizeof() , .(dot) , ::(scope) , ?:(삼합연산자)
*/

#include <iostream>
#include <string>

using namespace std;

class Point {
public:
	void showPoint() {
		cout << "X : " << px << " - Y : " << py << endl;
	}
	void add(const Point& arg) {
		this->px += arg.px;
		this->py += arg.py;
		//px 에게 arg.px값을 넘김.
	}
	void operator+=(const Point& arg) {
		cout << "- operator+= -" << endl;
		this->px += arg.px;
		this->py += arg.py;
	}
	Point(const int& px = 0, const int& py = 0) : px(px), py(py) {}

private:
	int py;
	int px;
};

int main() {

	Point pA(30, 30);
	Point pB(100, 100);
	pA.showPoint();
	pB.showPoint();
	cout << endl;

	//pA.add(pB);
	pA += pB; //c+의 장점.
	pA.showPoint();

}
// pa에게 pb좌표를 더해서 이동하려면 메소드를 추가함! : pA에다가 pB객체를 넘김
