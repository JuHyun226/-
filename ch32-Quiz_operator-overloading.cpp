// ch32-Quiz_operator-overloading.cpp

#include <iostream>
#include <string>

using namespace std;

/*
Member class 를 정의하고 main() 에서 테스트 하세요
- 회원번호, 회원이름, 전화번호를 관리 할 수 있습니다
- << , >> 연산자를 오버로딩해서 객체이름을 사용한 입출력이 가능하게 합니다
*/

class Member {
public:
	friend ostream& operator<<(ostream& os, const Member& arg) {
		os << arg.id << " - " << arg.name << " - " << arg.phone << endl;
		return os;
	}
	friend istream& operator>>(istream& is, Member& arg) {
		cout << "ID      입력 > "; is >> arg.id;
		cout << "이름    입력 > "; is >> arg.name;
		cout << "전화번호 입력 > "; is >> arg.phone;
		return is;
	}
	Member(const string& id = "none", const string& name = "none", const string& phone = "none")
		: id(id), name(name), phone(phone) {}

private:
	string phone;
	string name;
	string id;
};

int main() {

	Member manA;
	Member manB;

	cin >> manA >> manB;
	cout << manA << manB;

}
