/*
	ch19_copy-constructor.cpp
	- 같은 객체를 넘겨받아 초기화시키는게 보이면 생성자가 있다는 뜻.
*/

#include <iostream>
#include <string>

using namespace std;

class Shall {
private:
	int value;

public:
	Shall(int value = 0) {
		this->value = value;
	}

	//Shall(Shall& arg) { //shall의 arg가 참조하는건 obj = 안쳐도 되는 코드인데 왜 치고 있느냐? 복사생성자를 재정의 해야 하는 경우가 발생하기 때문.
	//	cout << "- 복사 생성자 -" << endl;
	//	this->value = arg.value;
	//}

	void show() {
		cout << "value : " << value << endl;
	}
};

int main() {

	Shall objA(100);
	objA.show();

	Shall objB(objA); // 새 객체를 생성할 때 기존 객체 objA를 사용해서 만들 수 있음.
	objB.show();

}

// 결과 value : 100 value : 100

//-------------------------------------

class Deep {
private:
	int* no; //memberfield 동적할당
	string word; // 구분하기 위해 word field 추가

public:
	Deep(int no = 0, string word = "none") {
		this->no = new int;
		*this->no = no; //매개변수 no의 값 넘김
		this->word = word;
	}

	Deep(Deep& arg) {
		this->no = new int;//공간 만들어 줌
		*this->no = *arg.no; //왜 이렇게 되지?
		this->word = arg.word; //word에 word 값 넘기고
	} // 얘를 안쓰면 objA랑 B값이 같음. 여기서 default 복사생성자의 문제가 있음.
	// 이렇게 써서 재정의해줘야 자기 자신의 것만 바뀜. - 공간 새로 하나 만들어서 거기에다가 받는 것. 그러니 각각 따로따로 분리된 공간에 받는 것.

	//재정의 하기 전의 코드는 아래와  같음
	/*Deep(Deep& arg) {
		this->no = arg.no; => 멤버필드 no에 다른 객체의 no 값을 보내고 있는데 no는 포인터니까 주소를 가지고 있으니, 주소값을 보내는 것.
		객체가 다른데 data 공간(heap에 있는 4바이트 공간)을 공유해서 쓰고 있기 때문에 같은 걸 쓰고 있다는게 문제.
	
		this->word = arg.word;
	}*/

	void setNo(int no) {
		*this->no = no;
	}

	void show() {
		cout << *no << ", " << word << endl;
	}
};

int main() {

	Deep objA(10, "objA");
	Deep objB(objA); //objB는 objA로 초기화

	objA.show();
	objB.show();

	objB.setNo(111); // 값을 수정해서 data를 출력하면
	cout << endl;

	objA.show();
	objB.show();
}
