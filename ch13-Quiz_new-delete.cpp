/*
	ch13-Quiz_new-delete.cpp
*/

#include <iostream>
#include <string>

using namespace std;

/*
Student class 를 사용해서 학생 성적을 관리하는 코드를 작성하세요
*/
class Student {
public:
	char name[20];  // 이름
	int cpp;        // 과목 점수
	int java;
	double avg;     // 평균
};

int InputInteger(string message) {
	int value;
	cout << message; cin >> value;
	return value;
}

Student* MakeArray(int size) {
	return new Student[size];
}

void InputArray(Student* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << i + 1 << "번째 입력" << endl;
		cout << "CPP 점수 > "; cin >> (arr + i)->name;
	}
}

void CalcAvg(Student* stu) {
	stu->avg = (double)(stu->cpp + stu->java) / 2;
}

void InputArray(Student* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << i + 1 << "번째 입력" << endl;
		cout << "이름 > "; cin >> arr[i].name; //(arr+i)->name;
		cout << "Cpp  > "; cin >> arr[i].cpp;
		cout << "Java > "; cin >> arr[i].java;
		CalAvg(&arr[i]); // 현재 인덱스의 주소를 넘김
	}
	cout << endl;
}
void OutputArray(Student* arr, int size) {
	cout << "--- 학   생    성   적 ---" << endl;
	cout << setw(4) << "번호"
		<< setw(8) << "이름"
		<< setw(8) << "Cpp"
		<< setw(8) << "Java"
		<< setw(8) << "평균" << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(4) << i + 1
			<< setw(8) << arr[i].name
			<< setw(8) << arr[i].cpp
			<< setw(8) << arr[i].java
			<< setw(8) << arr[i].avg << endl;
	}
	cout << endl;
}
int main() {


	int stuSize = 0;      // 학생 수
	Student* arr = NULL;  // 학생 배열 위치


	// 학생 수를 설정하는 함수를 구현하세요		
	stuSize = InputInteger("학생수 입력 > ");

	// 학생 수 만큼의 배열을 동적할당하는 함수를 구현하세요
	arr = MakeArray(stuSize);

	// 학생 성적을 입/출력하는 함수를 구현하세요
	InputArray(arr, stuSize);

	delete[] arr;

}

/*
student arr[3]; 
arr[0] == (arr+0) --> name == *(arr+0) : 첫번째 주소의 필드값.
[] 쓰면 * 제껴야지.
*/
