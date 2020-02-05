/*
	ch23_classArray.cpp
	- 어떤 객체들을 컨트롤 하는 것이 따로 존재. 클래스 안에 다 넣으니 코드가 훨씬 간결.
*/

#include <iostream>
#include <string>

using namespace std;

class Value {
public:
	void info() {
		cout << no << " - " << word << endl;
	}
	void setWord(const string& word) { this->word = word; }
	void setNo(const int& no) { this->no = no; }
	Value(const int& no = 0, const string & word = "none") : no(no), word(word) {}

private:
	string word;
	int no;
};


class ValueManager {
public:
	void showValue() {
		for (int i = 0; i < idx; i++) {
			list[i].info(); //list배열의 i번째 info 메소드 실행
		}
		cout << endl;
	}
	void setValue(const Value& arg) {//value 객체를 넘겨받음
		if (idx < size) {
			list[idx] = arg;
			++idx;
		}
	}
	~ValueManager() { delete[] list; }
	ValueManager(int size = 3) : size(size) { //크기값 3개
		idx = 0;
		list = new Value[size]; // list pointer에는 value class를 배열로써 동적할당. => list 는 heap에 value class 3개 알고 있는 것임.
	}

private:
	Value* list;
	int idx;
	int size;
};

int main() {

	ValueManager* vm = new ValueManager;
	vm->setValue(Value(1, "testA"));	//데이터 추가시 -> 0번 인덱스에 하나가 들어감.
	vm->setValue(Value(2, "testB"));
	vm->setValue(Value(3, "testC"));
	vm->setValue(Value(1, "testA"));

	vm->showValue(); // 지금까지 들어간 값들 출력.

	delete vm;
}
