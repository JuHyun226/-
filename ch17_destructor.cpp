/*
	ch17_destructor.cpp
	- 객체의 memberfield를 동적할당시 소멸자 꼭 사용하기.

소멸자 ( destructor )
- class 명과 동일한 이름으로 '~'기호를 사용해서 정의
- 객체가 메모리에서 삭제 될 때 자동 실행됨.
- 매개변수, 반환타입 둘다 사용불가


		  생성자                     소멸자
사용용도   객체 생성(멤버필드 초기화)   객체 삭제
형식      class명( 매개변수 )         ~class명()
호출시점   객체 생성시                 객체 소멸시
매개변수   사용/없음                   없음
오버로딩   가능                        불가

*/

#include <iostream>
#include <string>

using namespace std;

class Dest {
private:
	int* value; //member field로 pointer 변수가 들어갈 수 있음.

public:
	Dest(int _value = 0) {
		value = new int;
		*value = _value;
	}

//	~Dest(int _a 같이 소멸자는 매개변수 안받기에 오버로딩이 생성자와 달리 불가) 
// 소멸자: clear 대신 사용가능. main 함수 종료시 객체가 memory에서 빠져나가면서 자동으로 실행됨.
	~Dest() {
		cout << *value << "소멸자" << endl;
		delete value;
	}	

	void clear() { // 해당 data 공간을 delete해주는 method. 
		delete value;
	}

	void showValue() { //데이터 출력 함수
		cout << "값 : " << *value << endl; //*value가 가리키는 값 출력.
	}



};

int main() {

	Dest objA(100);
	objA.showValue();

	Dest objB(222);
	objB.showValue(); // 생성자는 객체가 만들어지는 순서대로 호출, 소멸자는 역순으로 호출하여 삭제시키지만 동적할당에서는 내가 지우라는 순서대로 지워짐. stack
	cout << endl;

	Dest* pdA = new Dest(5);
	Dest* pdB = new Dest(7);

	delete pdA;
	delete pdB; //delete 안하면 소멸자 7이 안나옴.


//	objA.clear(); // 사용 안할 때 clear 호출해서 삭제 필요.
//	delete objA : error

}

//----------------------------------------------------------------

class Word {
private:
	char* stn;

public:

	//Word(const char* _stn) {
	//	stn = new char[strlen(_stn) + 1]; // r공간 만들어줌
	//	strcpy_s(stn, strlen(_stn) + 1, _stn); // 값을 넘겨줌
	//}

	Word(string _stn) {
		stn = new char[_stn.length() + 1];
		strcpy_s(stn, _stn.length() + 1, _stn.c_str()); // _stn.c_str()를 쓸려면 객체값이 아닌 주소를 써야함.
	}

	~Word() {
		cout << stn << " 삭제" << endl;
		delete[] stn;
	}


	void showString() { //cnffur
		cout << stn << endl;

};

int main() {

	Word textA("good");
	textA.showString();

}
