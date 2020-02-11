// ch31-Quiz_operator-overloading.cpp

#include <iostream>
#include <string>

using namespace std;

/*
Time class 를 정의하세요
- 필드 : 시간, 분
  기능 : 두개의 시간값을 더하는게 가능합니다
*/

class Time {
public:
	friend Time operator+(const Time& rA, const Time& rB) {
		Time newTime;
		newTime.hour = rA.hour + rB.hour;
		newTime.min = rA.min + rB.min;
		if (newTime.min >= 60) {
			++newTime.hour;
			newTime.min -= 60;
		}
		return newTime;
	}
	void showTime() {
		cout << hour << "시 " << min << "분" << endl;
	}
	Time(const int& hour = 0, const int& min = 0) : hour(hour), min(min) { }

private:
	int min;
	int hour;
};

int main() {

	// Time class 객체 두개를 생성하고,
	// 두 객체의 시간 값을 더해서 새로운 객체를 생성하세요
	Time timeA(3, 45);
	Time timeB(2, 30);
	Time tot = timeA + timeB;
	tot.showTime();

}
