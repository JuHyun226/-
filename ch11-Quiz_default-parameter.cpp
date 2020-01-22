//ch11-Quiz_default-parameter.cpp

#include <iostream>
#include <string>

using namespace std;

int InputInteger(string message) {
	int value;
	cout << message; cin >> value;
	return value;
}

void Gugudan(int dan = 9) {
	cout << dan << " 단" << endl;
	for (int i = 1; i < 10; i++)
		cout << dan << " X " << i << " = " << dan * i << endl;
}

void LastSum(int last = 10) {
	int sum = 0;
	//for (int i = 1; i <= last; i++) {
	//	sum += i;
	//}
	sum = ((last + 1) * last) / 2;
	cout << "1 ~ " << last << " 까지의 합 : " << sum << endl;
	//for문은 데이터가 많아질수록 계산횟수가 증가하지만 얘는 똑같기에 얘가 나음.
}

int main() {

	//// 구구단 값을 넘겨받으면 해당 구구단값 모두 출력하는 함수를 구현하세요
	//// 2 ~ 9단 사이의 값이 아니면 무조건 9단이 출력됩니다
	//int dan = InputInteger("단 입력 > ");
	//if (dan > 1 && dan < 10) {
	//	Gugudan(dan);
	//}
	//else {
	//	Gugudan();
	//}



	// 1 ~ n(넘겨받은 수)까지의 합을 구하는 함수를 구현하세요
	// 넘겨받는 값이 없으면 무조건 1 ~ 10 까지의 합을 계산합니다
	int last = InputInteger("마지막 수 입력 > ");
	if (last > 0) {
		LastSum(last);
	}
	else {
		LastSum(); //넘겨받는 값이 없을 때.
		// enter는 문자로 처리해야함. int에게는 enter가 안 들어가기에.
	}

	// 급여를 계산하는 함수를 구현하세요
	// - 기본시간 : 40 시간, 시간당 급여 : 8590 원
	// - 기본급여, 일한 시간에 대한 급여를 계산 할 수 있어야 합니다

	int select = InputInteger("1.기본급여  2.시간당 급여 > ");
	switch (select) {
	case 1:
		WageCalc();
		break;

	case 2: {
		int time = InputInteger("일한 시간 입력 > ");
		WageCalc(time);
	}
			break;

	default:
		cout << "선택 오류~" << endl;
	}

}

