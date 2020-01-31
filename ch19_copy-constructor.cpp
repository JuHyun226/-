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
