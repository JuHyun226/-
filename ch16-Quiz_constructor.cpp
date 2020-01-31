/*
	ch16-Quiz_constructor.cpp
*/

#include <iostream>
#include <string>

using namespace std;
/*
Member class 를 정의하고 main() 에서 테스트하세요
- 이름, 주소, 나이, 성별 관리가 가능합니다
*/

class Total {
	//private:
public:
	string name;
	string addr;
	int age;
	string gender;

public:
			//set.field명으로 적기 // 처음은 소문자, 두번째부터는 대문자를 사용하라.(코딩규칙이 있음)
			//get.field명

	// - 생성자가 있어야 합니다
	Member(string _name = "none", string _addr = "none", int _age = 0, string _gender = "none") {
		setName(_name);
		setAddr(_addr);
		setAge(_age);
		setGender(_gender);
	}

	//	이름은 5자까지 설정 가능합니다
	void setName(string _name) { //값만 빼오는거니까 get쓰고 값만 빼는거니까 return name 그래야지 name을 사용할 수 있음. memA.name로.
		if (_name.length() < 11)//한글이니까 11이라고 함.
			name = _name;
		else
			name = "none";
	}
	string getName() { return name; }

	//  주소는 50자까지 설정 가능합니다
	void setAddr(string _addr) {
		if (_addr.length() < 101)
			addr = _addr;
		else
			addr = "none";
	}
	string getAddr() { return addr; }

	//  나이는 0 ~ 130 까지 설정 가능합니다
	void setAge(int _age) {
		if (_age >= 0 && _age <= 130)
			age = _age;
		else
			age = 0; // 잘못 되었을 때의 값.
	}
	int getAge() { return age; }

	//	성별은 남성, 여성으로 설정 가능합니다
	void setGender(string _gender) {
		if (_gender == "남성" || _gender == "여성")
			gender = _gender;
		else
			gender = "none";
	}
	string getGender() { return gender; }

	void info() {
		cout << "--- 회 원 정 보 ---" << endl;
		cout << "이름 : " << name << endl;
		cout << "주소 : " << addr << endl;
		cout << "나이 : " << age << " 세" << endl;
		cout << "성별 : " << gender << endl;
	}
};

int main() {

	Member memA;
	memA.setName("test");	// 이렇게 쓰면 더이상 저거 못사용하니까 GETTER SETTER 만들어서 쓰라는 것임.
	cout << "이름 : " << memA.getName() << endl;//getname메소드 를 통해 값을 빼내와라.
	cout << endl;

	Member* pmB = new Member("추신수", "미국 텍사스", 38, "남성");
	pmB->info();

	delete pmB;

	//memA.age=-19 이렇게 사용하지 못하게 메소드로 쓸지말지 필터링이 가능하게 해서 메소드를 통해서 쓰도록 하는 것임.
}
