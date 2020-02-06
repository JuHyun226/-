// ch24-Quiz_inheritance.cpp

//pointer로 하면 동적할당해야 되기에 이니셜라이저 쓰면 안됨. 포인터 자체가 실제 데이터 공간을 가지고 있는게 아니기 때문.

// string으로 배열 만들면 안됌. string이 가변이고 배열은 고정(fix)이기 때문.

#include <iostream>
#include <string>

using namespace std;

// Product class 를 정의하세요
// - 필드 : 제품명(char*), 가격(int)
class Product {
public:

	void showProduct() {
		cout << "제품명  : " << model << endl;
		cout << "가격    : " << price << " 원" << endl;
	}
	void setPrice(const int& price) {
		if (price >= 0)
			this->price = price;
	}
	~Product() {
		cout << model << " 삭제" << endl;
		delete[] model;
	}
	Product(const char* model = "none", const int& price = 0) { // 이니셜라이저 쓰면 주소값만 넣는 거니까 안 됌. : model(model) {
		this->model = new char[strlen(model) + 1];
		if (this->model != NULL)
			strcpy_s(this->model, strlen(model) + 1, model);
		//this->price = price;
		setPrice(price);
	}
private:
	int price;
	char* model;
};

// Product class 를 상속받아서 Phone class 를 정의하고 main() 에서 테스트 하세요
// - 필드 : 통신사(char*) 
class Phone : public Product {
public:

	void showPhone() {
		cout << "--- 휴대폰 정보 ---" << endl;
		showProduct();
		cout << "통신사 : " << telecom << endl;
	}
	~Phone() {
		cout << telecom << " 삭제" << endl;
		delete[] telecom;
	}
	Phone(const char* model = "none", const int& price = 0, const char* telecom = "none")
		: Product(model, price) {
		this->telecom = new char[strlen(telecom) + 1];
		if (this->telecom != NULL)
			strcpy_s(this->telecom, strlen(telecom) + 1, telecom);
	}

private:
	char* telecom;
};

int main() {


	Phone* proA = new Phone("갤럭시 노트10", 1140000, "KT");
	proA->showPhone();

	delete proA;

}
