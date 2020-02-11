// ch32_operator-overloading.cpp

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/* 연산자 오버로딩
C++ 고유 스트림
- 출력 스트림에서는 삽입연산자(<< , insertion operator) 를 사용해서 값을 보내고,
  입력 스트림에서는 추출연산자(>>, 오른쪽 쉬프트 연산자 , extraction operator ) 사용해서 값을 가져옵니다

  - 두개의 객체와 연관되면 friend 선언.
*/

class Point {
public:
	void setInput() {
		cout << "X 좌표 입력 > "; cin >> px;
		cout << "Y 좌표 입력 > "; cin >> py;
	}
	friend istream& operator>>(istream& is, Point& arg) { //쓸 객체, 저장할 객체
		cout << "- operator>> -" << endl;
		cout << "X 좌표 입력 > ";
		is >> arg.px; 
		cout << "Y 좌표 입력 > ";
		is >> arg.py;
		return is; //reference인 is를 반환해라.
	}
	void showPoint() {
		cout << "X : " << setw(5) << px << " - Y : " << setw(5) << py << endl;
	}
	friend ostream& operator<<(ostream& os, const Point& arg) {//다시 써야 해서 반환시키는 것임.
		cout << "-operator를 오버로딩 했음<< -" << endl;
		os << "arg의 X좌표 값 네칸: " << setw(4) << arg.px << "-Y: " << setw(4) << arg.py << endl;
		return os; // 연속으로 쓰기 위해 os 객체를 반환하라
	}
	Point(const int& px = 0, const int& py = 0) : px(px), py(py) {}

private:
	int py;
	int px;
};

int main() {

	Point pA;
	Point pB;
	pA.showPoint();
	pA.setInput();
	pA.showPoint();
	cout << endl;

	//cin >> pA//cin객체를 istream& is에 넘김. -> >>는 operator를 넘김(pA) , pa는 point&arg에 넘겨짐
	//cout << pA; //pA객체명으로 출력이 가능해짐
	cin >> pA >> pB; // 연속 입력이 가능해짐
	cout << pA << pB;
}
