/*
	ch23-Quiz_classArray.cpp
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// 회원 한면의 정보를 다루는 Member class 를 정의하세요
// - id(회원번호), 이름, 전화번호
class Member {
public:
	void info() {
		cout << setw(5) << id << " - "
			<< setw(8) << name << " - "
			<< phone << endl;
	}
	string getName() { return name; }
	Member(const string& id = "none", const string& name = "none", const string& phone = "none")
		: id(id), name(name), phone(phone) {}
private:
	string phone;
	string name;
	string id;
};

// Member class 관리하는 Manager class 를 정의하고 main() 에서 테스트 하세요
// - 배열을 사용해서 관리합니다
//   > 회원추가, 회원목록 보기, 회원삭제(마지막)가 가능합니다
class Manager {
public:
	// 회원 목록 출력
	void info() {
		cout << "--- 회 원 목 록 ---" << endl;
		for (int i = 0; i < idx; i++) {
			list[i].info();
		}
		cout << endl;
	}
	// 마지막 회원 삭제
	void remove() {
		if (idx > 0) {
			--idx; //delete와 같은 효과
			cout << list[idx].getName() << " 삭제" << endl;
		}
		else {
			cout << "- list is empty -" << endl;
		}
	}
	// 회원 추가
	void insert(const Member& arg) {
		if (idx < size) {
			list[idx] = arg;
			cout << list[idx].getName() << " 추가" << endl;
			++idx;
		}
		else {
			cout << "- list is full -" << endl;
		}
	}
	// 회원 관리
	void run() {
		bool run = true;
		while (run) {
			int select;
			cout << "1.회원추가  2.회원삭제  3.회원목록  > "; cin >> select;

			switch (select) {
			case 1:
			{
				if (idx < size) {
					string id;
					string name;
					string phone;
					cout << "ID 입력 > "; cin >> id;
					cout << "이름 입력 > "; cin >> name;
					cout << "전화번호 입력 > "; cin >> phone;
					insert(Member(id, name, phone));
				}
			}
			break;
			case 2:
				remove();
				break;
			case 3:
				info();
				break;
			case 0:
				cout << "- program end -" << endl;
				run = false;
			}

		}
	}

	~Manager() { delete[] list; }

	Manager(int size = 3) : size(size) {
		idx = 0;
		list = new Member[size];
	}

private:
	Member* list;
	int idx;
	int size;
};

int main() {

	Manager* manager = new Manager;
	manager->run();

	delete manager;

}
