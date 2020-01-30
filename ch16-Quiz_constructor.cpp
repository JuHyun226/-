/*
	ch16-Quiz_constructor.cpp
*/

#include <iostream>
#include <string>

using namespace std;
/*
Member class 를 정의하고 main() 에서 테스트하세요
- 이름, 주소, 나이, 성별 관리가 가능합니다
- 생성자가 있어야 합니다
  이름은 5자까지 설정 가능합니다
  주소는 50자까지 설정 가능합니다
  나이는 0 ~ 130 까지 설정 가능합니다
  성별은 남성, 여성으로 설정 가능합니다
*/

class Total {
private:
	string name;
	string adress;
	int age;
	string gender;

public:

	string getname() { return name; }
	void name(string _name) {
		if (_name.length() =< 5) {
			name = _name;
		}
	}

	string getadress() { return adress; }
	void adress(string _adress) {
		if (_adress.length() =< 50) {
			adress = _adress;
		}
	}

	int getage() { return age; }
	void age(int _age) {
		if (0 <= _age.length() =< 130) {
			age = _age;
		}
	}

	string getgender() { return gender; }
	void gender(string _gender) {
		gender = _gender;
	}

	void info() {
		cout << "이름    : " << name << endl;
		cout << "주소    : " << adress << endl;
		cout << "나이    : " << age << endl;
		cout << "성별    : " << gender << endl;
	}

int main() {

	Total ob1;
	ob1.info();

}

//=----------------------------
class Member {
private:
	string name;
	string addr;
	int age;
	string gender;

public:
	//set.field명으로 적기 // 처음은 소문자, 두번째부터는 대문자를 사용하라.(코딩규칙이 있음)
	//get.field명

	void setName(string _name) {
		if (_name.length() < 11) { //한글이니까 11이라고 함.
			name = _name;
		}
	}
	string getName() { return name; }
	//값만 빼오는거니까 get쓰고 값만 빼는거니까 return name 그래야지 name을 사용할 수 있음. memA.name로.

	void setAddr(string _addr) {
		if (_addr.length() =< 50) { 
			addr = _addr;
		}
	}
	string getAddr() { return addr; }

	void setage(int _age) {
		if (0 =< _age.length() =<130) {
			age = _age;
		}
	}
	int getAge() { return age; }
	
	string getgender() { return gender; }
	void gender(string _gender) {
		gender = _gender;
	}
};

int main() {

	Member memA;
	memA.setName("test"); // 이렇게 쓰면 더이상 저거 못사용하니까 GETTER SETTER 만들어서 쓰라는 것임.
	cout << "이름 : " << memA.getName() << endl; //getname메소드 를 통해 값을 빼내와라.
	//memA.age=-19 이렇게 사용하지 못하게 메소드로 쓸지말지 필터링이 가능하게 해서 메소드를 통해서 쓰도록 하는 것임.
	memA.setAddr("no");
	cout << "주소 : " << memA.getAddr() << endl;

}
