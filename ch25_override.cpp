// ch25_override.cpp

/*
함수 오버라이드( function override )
- 상위 클래스에 있는 메소드를 하위클래에서 같은 이름의 메소드로 재정의 해서 사용하는 것을 말합니다
- 오버라이드 하고자 하는 메소드가 상위클래스에 있어야 합니다
*/

// 상위클래스에서 메소드를 상속받은 하위클래스에서 다시 재정의해서 쓰는 것. != overloading(여러개 사용)
// 지정해주면 또 오버라이드(재정의) 전의 메소드도 사용가능.

#include <iostream>
#include <string>

using namespace std;

class Product {
public:
	void info() {
		cout << "S/N    : " << serial << endl;
		cout << "모델명 : " << model << endl;
	}
	string getModel() { return model; }
	string getSerial() { return serial; }
	Product(const string& serial = "none", const string& model = "none")
		: serial(serial), model(model) {}

private:
	string model;
	string serial;
};

class Monitor : public Product {
public:

	void info() {
		cout << "--- 모니터 정보 ---" << endl;
		//info(); //이건 재귀호출이라서 안 됌. 계속 호출됨. 뺑뺑 돌아요..
		Product::info();	//스코프 연산자로 상위클래스를 인포를 쓰겠다고 지정해주면 가능
		cout << "화면크기 : " << inch << " inch" << endl;
	}
	void info() {
		cout << "--- 모니터 정보 ---" << endl;
		cout << "S/N      : " << getSerial() << endl;
		cout << "모델명   : " << getModel() << endl;
		cout << "화면크기 : " << inch << " inch" << endl;
	}
	Monitor(const string& serial = "none", const string& model = "none", const string& inch = "14")
		: Product(serial, model), inch(inch) {}

private:
	string inch;
};

int main() {

	Monitor* proA = new Monitor("LM001", "LG 울트론", "24");
	proA->showMonitor
	proA->info();
	cout << endl;

	proA->Product::info();

	delete proA;

}
