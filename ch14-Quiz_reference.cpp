/*
	ch14-Quiz_reference.cpp
*/

#include <iostream>
#include <string>

using namespace std;

// 한 사람의 정보를 관리하는 Person class 를 정의 하세요
class Person {
public:
	string name;           // 이름
	int age;               // 나이
	string gender;         // 성별
	double height;         //  키( cm )
	double weight;         // 몸무게( kg )
	double bmi;            // 체질량 지수
	string body;           // 몸상태

	void inputName() {// 이름 입력 
		cout << "이름 입력 > "; cin >> name;
	}

	void inputAge() {// 나이 입력( 0 ~ 130 까지만 가능 )
		while (true) {
			cout << "나이 입력 > "; cin >> age;
			if (age >= 0 && age <= 130)
				break;
		}
	}

	void inputGender() {// 성별 입력( 남성, 여성만 가능 )
		while (true) {
			cout << "성별 입력 > "; cin >> gender;
			if (gender == "남성" || gender == "여성")
				break;
		}
	}

	void inputHeight() {// 키 입력
		while (true) {
			cout << "키 입력 > "; cin >> height;
			if (height >= 0) break;
		}
	}

	void inputWeight() {// 몸무게 입력
		while (true) {
			cout << "몸무게 입력 > "; cin >> weight;
			if (weight >= 0) break;
		}
	}

	void calcBmi() {// 체질량 계산
		double mHeight = height / 100;
		bmi = weight / (mHeight * mHeight); //meter 키 = mHeight
	}

	void setBody() {// 몸상태 설정
		if (bmi < 18.5) body = "저체중";
		else if (bmi < 25.0) body = "정상";
		else if (bmi < 30.0) body = "과체중";
		else body = "비만";
	}

	// 한방에 돌리기
	void setPerson() {
		inputName();
		inputAge();
		inputGender();
		inputHeight();
		inputWeight();
		calcBmi();
		setBody();
	}


	// 전체 정보 출력
	void info() {
		cout << "-----  회 원 정 보  -----" << endl;
		cout << "이름   : " << name << endl;
		cout << "나이   : " << age << " 세" << endl;
		cout << "성별   : " << gender << endl;
		cout << "키     : " << height << " cm" << endl;
		cout << "몸무게 : " << weight << " kg" << endl;
		cout << "BMI    : " << bmi << endl;
		cout << "몸상태 : " << body << endl;
	}

};

int main() {

	Person manA;
	manA.setPerson();
	manA.info();
	// class person의 객체 만들고, manA에 setperson과 info를 실행시켜서 입력받기

}
