/*
	ch06-Quiz_function.cpp
*/

#include <iostream>	

using namespace std;

class Person {
public:
	char name[20];  // 이름
	int age;        // 나이
	double height;  // 키(cm)
	double weight;  // 몸무게(kg)
	double bmi;     // 체지량 지수
	char body[10];  // 몸상태
};


int RangeInput(int start, int end) {
	int value;
	while (1) {
		cout << start << " ~ " << end << " 사이의 수 입력 > ";
		cin >> value;
		if (value >= start && value <= end)
			break;
	}
	return value;
}
int FindMax(int a, int b) {
	if (a > b) return a;
	else if (b > a) return b;
	else return 0;
}


void ShowMax(int a, int b, int max) {
	if (max) {
		cout << a << ", " << b << " 중 큰수 : " << max << endl;
	}
	else {
		cout << a << ", " << b << " 같은수" << endl;
	}
}

//----------------------------------------------
void SetBmi(Person* p) {
	double mHeight = p->height / 100;
	p->bmi = p->weight / (mHeight * mHeight);
}

void BodyState(char* body, int size, const char* value) {
	strcpy_s(body, size, value);
}

void SetBody(Person* p) {
	//     0    ~ 18.5 미만  저체중
	//     18.5 ~ 25.0 미만  정상
	//     25.0 ~ 30.0 미만  과체중
	//     30.0 이상         비만
	if (p->bmi < 18.5) BodyState(p->body, sizeof(p->body), "저체중");
	else if (p->bmi < 25.0) BodyState(p->body, sizeof(p->body), "정상");
	else if (p->bmi < 30.0) BodyState(p->body, sizeof(p->body), "과체중");
	else BodyState(p->body, sizeof(p->body), "비만");
}

void InputPerson(Person* p) {
	cout << "이름   입력 > "; cin >> p->name;
	cout << "나이   입력 > "; cin >> p->age;
	cout << "키     입력 > "; cin >> p->height;
	cout << "몸무게 입력 > "; cin >> p->weight;
}

void OutputPerson(Person man) {
	cout << "--- 회 원 정 보 ---" << endl;
	cout << "이름   : " << man.name << endl;
	cout << "나이   : " << man.age << " 세" << endl;
	cout << "키     : " << man.height << " cm" << endl;
	cout << "몸무게 : " << man.weight << " kg" << endl;
	cout << "BMI    : " << man.bmi << endl;
	cout << "몸상태 : " << man.body << endl;
}


//-------------------------------------------------------
int main() {

	// 허용범위 값(시작, 끝)을 넘겨받고(1~5면 1~5사이 것만 받고), 범위 안의 값을 입력처리해서 반환하는 함수를 구현하세요
	// 위에 함수를 사용해서 변수 2개를 각각 초기화 합니다
	// 두수를 넘겨받아서 큰값을 반환하는 함수를 구현하세요
	// - 같은 값이면 0을 반환합니다 
	int vA = RangeInput(1, 5); // 이 사이의 값만 입력받을 수 있게 할려면 반환시켜야 한다는 것.
	int vB = RangeInput(1, 5);
	int max = FindMan(vA, vB); // 큰 값을 찾아라.
	ShowMax(vA, vB, max);
	
//---------------------------------------------------
	// Persom 클래스의 변수(객체)를 하나 생성합니다
	// - 위 객체에 값을 입/출력하는 함수를 각각 구현하세요
	//   > bmi, 몸상태는 입력하지 않습니다
	// - 위 객체의 값을 가지고 BMI(체질량지수) 값을 구하는 함수를 구현하세요
	//   > BMI = 몸무게(kg) / ( 키(m) * 키(m) )
	// - 위 객체의 BMI 값을 가지고 몸상태를 저장하는 함수를 구현하세요
	//   > bmi              몸상태
	//     0    ~ 18.5 미만  저체중
	//     18.5 ~ 25.0 미만  정상
	//     25.0 ~ 30.0 미만  과체중
	//     30.0 이상         비만
	Person man = { "none" };
	InputPerson(&man);
	OutputPerson(man);

}

