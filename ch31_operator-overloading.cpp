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

//-----------------------------------------------------------------------
/*
friend
- 클래스안의 메소드안에 friend 키워드를 붙이면 일반함수와 동일하게 사용이 됩니다
- friend 키워드를 사용한 메소드는 접근제한자의 영향을 받지않고 어디서든 사용이 가능합니다
- 함수 외부 정의시에는 friend 키워드는 선언부에만 작성합니다

멤버함수와 friend 함수의 선택
- 함수가 수행하는 작업이 하나의 객체와 과련되면 멤버함수
  함수가 수행하는 작업이 두개 이상의 객체와 관련되면 friend 함수를 사용합니다
*/

// friend 키워드가 붙으면 객체랑 상관없이 호출이 된다. 접근제한자의 영향을 받지 않는다. private에 들어가도 상관이 없어진다.
// 연산자 오버로딩시에만 friend를 사용할 것. 그 이유는 이걸 붙이면 일반 클래스 규칙과 멀어지기 때문.



class Point {
public:
	void showPoint() {
		cout << "X : " << px << " - Y : " << py << endl;
	}
	Point Plus(const Point& rA, const Point& rB) {
		Point tmp;
		tmp.px = rA.px + rB.px;
		tmp.py = rA.py + rB.py;
		return tmp;
	}

	Point(const int& px = 0, const int& py = 0) : px(px), py(py) {}

private:
	friend Point operator+(const Point& rA, const Point& rB);
	friend Point operator+(const Point& rA, const int& rB);
	friend Point operator-(const Point& rA, const Point& rB);
	int py;
	int px;
};

Point operator+(const Point& rA, const Point& rB) {
	cout << "- operator+ -" << endl;
	Point tmp;
	tmp.px = rA.px + rB.px;
	tmp.py = rA.py + rB.py;
	return tmp;
}
Point operator+(const Point& rA, const int& rB) { //이거랑 위에꺼는 다른 함수~
	return Point(rA.px + rB, rA.py + rB);
}

Point operator-(const Point& rA, const Point& rB) {
	cout << "- operator- -" << endl;
	return Point(rA.px - rB.px, rA.py - rB.py);
}

int main() {

	Point pA(10, 10);
	Point pB(20, 20);
	pA.showPoint();
	pB.showPoint();
	cout << endl;

	//Point newP = pA.Plus(pA, pB);
	Point newP = pA + pB;
	newP.showPoint();

	newP = pA - pB;
	newP.showPoint();

	newP = pA + 100;
	newP.showPoint();
}

//----------------------------------------------
//-----------------------------------------------------------------


class Point {
public:
	void showPoint() {
		cout << "X : " << px << " - Y : " << py << endl;
	}
	Point& operator++() {  // 전위 ++ 
		cout << "- 전위 연산 -" << endl;
		this->px++;
		this->py++;
		return *this;
	}
	Point(const int& px = 0, const int& py = 0) : px(px), py(py) {}

private:
	int py;
	int px;
};

int main() {

	Point pA(10, 10);
	Point pB;
	pA.showPoint();
	pB.showPoint();
	cout << endl;

	pB = ++pA;
	pA.showPoint();
	pB.showPoint();
}
