/*
	ch14_reference.cpp

reference 변수( 참조자 )
* 변수 선언 앞에 &연산자가 쓰이면 참조사 선언이 됨, 그냥 변수 앞에 붙으면 그 변수값의 주소 반환.
- 기존에 선언된 변수(객체) 공간에 이름을 추가하는 것
- 레퍼런스 변수 선언시에는 자료형 뒤에 '&'기호를 붙여서 선언
- 변수에 대해서만 선언 가능. 선언과 동시에 누군가를 참조해야만 함, 선언시 반드시 초기화 해야 하며 한번 초기화 한 후에는 다른 변수 참조 불가.
- 참조의 대상 변경 불가.
- null로 초기화 불가.
- 참조자가 가지고 있는 값 변경시 원래 변수의 값이 변경됨.

	*/

#include <iostream>
#include <string>

using namespace std;

int main() {

	int n = 10; //int 형 변수 만들어 10으로 초기화
	int& rn = n; // rn이라는 변수 만들어 n으로 초기화
	cout << "n : " << n << ", rn: " << rn << endl; // n과 rn의 값 출력
	cout << endl;

	rn = 7;
	cout << "n : " << n << ", rn: " << rn << endl;
	cout << endl;

	cout << "n 주소: " << &n >> ", rn 주소: " << &rn << endl;

	// 레퍼런스 참조자. 기존 데이터 공간에 이름 하나를 더 추가하는 것. 값을 수정할 수 있고 똑같은 공간 사용함
	// 포인터 변수는 새로운 공간에 추가하는 것.
	int* p = &n;


}


// 레퍼런스를 레퍼런스로서 초기화할 수 있음. 꼭 변수로서만 할 수 있는 게 아님.----------------------------------------------------

int main() {

	int a = 7;
	int& ra = a;
	int& sa = ra;
	cout << "a : " << a << ", ra :	" << ra << ", sa : " << sa << endl;
	cout << "" << endl;

	cout << "a 주소 : " << &a
		<< ", ra 주소 : " << &ra
		<< ", sa 주소 : " << &sa << endl;
}


int main() {

	// int& rA = 100; Error
	// - 상수는 참조의 대상이 될수 없다.

	int b = 100;
	int& rB = b;

	int c = 200;
	// rB = c; // 변수 B의 공간에 c의 값 넣으라는 것.
	// - 레퍼런스 변수는 중간에 참조 대상을 변경 할 수 없다


	// int& rd; Error
	// - 레퍼런스 변수는 선언과 동시에 참조의 대상이 있어야 한다
	
	// int& re = NULL; //

}

//-----------------------------------------


void ShowData(int a, int b) {
	cout << a << ", " << b << endl;
}

void SwapData(int* pA, int* pB) {
	int tmp = *pA;
	*pA = *pB;
	*pB = tmp;
}

void SwapData(int& rA, int& rB) {
	int tmp = rA;
	rA = rB;
	rB = tmp;
}

int main() {

	int vA = 10;
	int vB = 7;
	ShowData(vA, vB);

	SwapData(&vA, &vB);
	ShowData(vA, vB);

	SwapData(vA, vB);
	ShowData(vA, vB);

}

//data도 레퍼런스로 받으면 수정 가능--------------------------------------

class Test {
public:
	int a;
	double b;
};

void SetTest(Test& r) {
	r.a = 100; // 레퍼런스로 받으니까 수정이 가능한 것임.
	r.b = 2.2;
}

void ShowTest(const Test& r) {
	cout << r.a << ", " << r.b << endl;
}

int main() {

	Test ob;

	SetTest(ob);
	ShowTest(ob);
}


// 함수의 반환타입이 레퍼런스이면 받는 대상이 변수 or 레퍼런스가 될 수 있다. ----

int& IncreaseData(int& r) {
	++r;
	return r;
}

int main() {

	int data = 5;

	int& rd = IncreaseData(data);
	cout << "data : " << data << ", rd : " << rd << endl;
	cout << endl;

	++rd;
	cout << "data : " << data << ", rd : " << rd << endl;
	cout << endl;


	int tmp = IncreaseData(data);
	cout << "data : " << data << ", tmp : " << tmp << endl;
	cout << endl;

	++tmp;
	cout << "data : " << data << ", tmp : " << tmp << endl;
	cout << endl;


	int a = 1;
	int& ra = a;// 레퍼런스가 될 수도 있고, 값이 될 수도 있다.

	int b = ra;

}

// TMP에서는 TMP값을 올리면 TMP의 값만 올라가지 데이터 변수의 값은 안 올라감.
// - 함수의 반환타입이 레퍼런스면 레퍼런스를 반환할 수도 있고, 값을 반환할 수도 있음.

//----------------------------------

int IncreaseValue(int& r) {
	++r;
	return r;
}

int main() {

	int value = 10;

	int t = IncreaseValue(value);
	// int& r = IncreaseValue(value); error

}

//class 이용을 통한 프로그램 만들기 = 객체지향 -------------------------------------------------------------
// classone가지고 관리. 그안의 기능을 가진 메소드 사용. 함수랑 여러 변수 조합하지 말고.

 //class는 필드 값 뿐만 아니라 메소드도 가질 수 있다.
#include <iomanip>

class Student {
	public:
		string name;
		int cpp;
		int java;
		double avg;
	};

class StuMananger {
public:
	int stuSize;          // 학생수
	Student* arr;         // 학생 배열 위치
	char inputCheck;      // 입력 실행 확인(1.실행   0.미실행 )

	void begin() { //멤버필드 초기화
		stuSize = 0;
		arr = NULL;
		inputCheck = 0;
	}

	void setSize() {
		cout << "학생수 입력 > "; cin >> stuSize;
	}

	void makeArray() {
		arr = new Student[stuSize];
		inputCheck = 0;
	}

	void InputArray() {
		for (int i = 0; i < stuSize; i++) {
			cout << i + 1 << "번째 입력" << endl;
			cout << "이름 > "; cin >> arr[i].name; //(arr+i)->name;
			cout << "Cpp  > "; cin >> arr[i].cpp;
			cout << "Java > "; cin >> arr[i].java;
			arr[i].avg = (double(arr[i].cpp) + arr[i].java) / 2;
		}
		cout << endl;
		inputCheck = 1;
	}

	void OutputArray() {
		if (arr != NULL && inputCheck == 1) {
			cout << "--- 학   생    성   적 ---" << endl;
			cout << setw(4) << "번호"
				<< setw(8) << "이름"
				<< setw(8) << "Cpp"
				<< setw(8) << "Java"
				<< setw(8) << "평균" << endl;
			for (int i = 0; i < stuSize; i++) {
				cout << setw(4) << i + 1
					<< setw(8) << arr[i].name
					<< setw(8) << arr[i].cpp
					<< setw(8) << arr[i].java
					<< setw(8) << arr[i].avg << endl;
			}
			cout << endl;
		}
	}
};

int main() {

	StuMananger classOne;
	classOne.begin();
	classOne.setSize();
	classOne.makeArray();
	classOne.OutputArray();
	classOne.InputArray();
	classOne.OutputArray();

	delete[] classOne.arr;

}
