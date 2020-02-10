// ch29_virtual-destructor.cpp

/*
가상 소멸자 ( virtual-destructor )
- 부모의 포인터로 자식클래스의 객체를 사용하면 객체 자체는 자식클래스 객체이지만
  부모의 포인터로 객체를 사용하기 때문에 컴파일러는 부모의 객체로 인식합니다
  그렇기 때문에 부모클래스의 소멸자만 실행하게 됩니다
  이때 자식클래스의 소멸자를 실행하기 위해서 부모클래스의 소멸자를 가상으로 선언합니다
*/

// 깔끔하게 하고 싶으면 상위클래스의 상속자에도 virtual이라는 걸 붙여야 함.

#include <iostream>
#include <string>

using namespace std;

class Date {
public:
	virtual void show() {
		cout << "날짜 : " << date << endl;
	}
	char* getDate() { return date; }
	virtual ~Date() {
		cout << date << " 삭제" << endl;
		delete[] date;
	}
	Date(const char* date = "none") {
		this->date = new char[strlen(date) + 1];
		if (this->date != NULL)
			strcpy_s(this->date, strlen(date) + 1, date);
	}

private:
	char* date;
};

class Product : public Date {
public:
	void show() {
		cout << "제조일자 : " << getDate() << endl;
		cout << "제품명   : " << name << endl;
	}
	~Product() {
		cout << name << " 삭제" << endl;
		delete[] name;
	}
	Product(const char* date = "none", const char* name = "none") : Date(date) {
		this->name = new char[strlen(name) + 1];
		if (this->name != NULL)
			strcpy_s(this->name, strlen(name) + 1, name);
	}

private:
	char* name;
};

int main() {

	Product* pro = new Product("2020-02-10", "제품");
	pro->show();
	delete pro;

	cout << endl;

	Date* date = new Product("2020-02-11", "신제품");
	date->show();
	delete date;

}
