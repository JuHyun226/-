/*
	ch15_class-access.cpp

// memberfield는 앞으로 무조건 왠만하면 private로 막아주고 method로 오픈시켜라. 그래서 함수 잘 다뤄야 함. 무조건 class.

접근 제한자
- class 외부에서 class 안의 멤버에 접근을 허용 할 지를 결정합니다
- 종류
  > public    : class 내부, 외부 어디에서나 접근이 가능합니다
	private   : class 안에서만 멤버에게 접근이 가능합니다( class defalut 값 )
	protected : 기본 성격은 private과 동일하게 내부에서만 접근이 가능합니다
				class 상속시에는 하위(자식)class 에서의 접근을 허용합니다

은닉화
- 접근제한자를 사용해서 외부에서의 의도치 않은 접근으로 인한 데이터 손상을 방지함. 
 > getter: 멤버필드의 값을 확인(사용)하는 용도의 메소드 / getter하고 필드명 쓰면 됌
 > setter : 멤버필드의 값을 설정(수정)하는 용도의 메소드 

캡슐화
- 객체의 데이터와 메소드를 하나로 묶으면서 실제 구현내용은 외부에 오픈하지 않는 것을 말합니다

*/

// class에선 private로 멤버필드를 다이렉트로 사용하는 걸 막아버려서 외부에서 잘못된 값이 들어오는걸 원천 차단

#include <iostream>	
#include <string>

using namespace std;

class Person {
	//public:  // 접근 제한자
private:
	string name;
	int age;
	
public:
// 다른 건 모두 막아버리고 메소드로써 모든 접근을 할 수 있도록 함.

	void setName(string _name) { // 설정할 이름값
		if (_name.length() < 11)
			name = _name;
		else
			cout << "10 글자 이하만 가능합니다.." << endl;
	}
	string getName() { return name; } // 이름 필드값 반환하게 하는것.

	void setAge(int _age) {
		//method는 필터링이 가능하니 확인한 후 대입시켜라
		if (_age >= 0 && _age <= 130)
			age = _age; // 사용할 수 있으니 memberfield에 적용시켜라
		else // 안되는 이유를 알려줌.
			cout << "나이는 0~130 사이만 가능합니다.." << endll;
	}
	int getAge() { return age; }

	void info() {
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
};

int main() {

	Person manA;
	// manA.name = "none"; // 다이렉트로 쓸려고 하는 member field만 error
	// manA.age = 0;
	//manA.info();
	//cout << endl;
	// manA.age = -20;

	manA.setName("akl;sdjfkl;ajsdf"); // 비정상
	manA.setName("test"); //정상 
	manA.setAge(131); // 비정상
	manA.setAge(20); // 정상
	manA.info(); // 잘되었는지 확인하기 위한 것.

	//이름 쓰고 싶으면 이렇게. getname이 name값을 빼내올 것임
	cout << "이름 : " << manA.getName() << endl;

	cout << "나이 : " << manA.getAge() << " 세" << endl;
	cout << endl;
	
	// 객체도 당연히 동적할당 가능

	Person* pm = new person; // 객체를 힙에다가 만든 것임. 이름값 설정하려면 pm있는 곳에 가야 객체가 잇음. memberfield direct로 못 접근하니 메소드로서 접근!
	pm->setName("추신수");
	pm->setAge(38);
	pm->info();

	delete pm;				 // 동적할당했으면 항상 지워라


}
