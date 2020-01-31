/*
	ch18_this-pointer.cpp

	This pointer
	- class 안의 자기 자신의 멤버필드를 가리키는 용도로 사용되는 포인터 입니다
	> class 안에서만 사용이 가능합니다

	- class 안에는 자기자신이라는 멤버필드를 가리키는 this 포인터가 들어가 있음 => 같은 매개변수를 써도 문제 되지 않음.

*/

#include <iostream>
#include <string>

using namespace std;

class This {
private:
	int value;
	double b;

public:
	This(int value, double b) {
		this->value = value;
		this->b = b;
	}

	void show() {
		cout << value << ", " << b << endl;
	}
};

int main() {

	This ob(11, 2.2);
	ob.show();

}
