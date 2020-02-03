/*
	ch19-Quiz_copy-constructor.cpp
	- char포인터에서 배열처리하고, 주소+1해서 strcpy_s 함수 써서 넘겨주는 게 편함

	char textA[] = "test";
	cout << *textA << endl;

	char* ps = new char; // char*: 1바이트 공간 만듦
	*ps = 'A';	// 이 주소가 가리키는 곳에 1바이트 공간을 사용. "asdf" 이렇게 문자는 못넣음.



	char* pt = new char[strlen(*textA) + 1]// char 포인터 에서 배열처리해야 문자를 넣을 수 있음. 주소+1 넣으면 null문자 포함시켜서 써야함.
		int i;
	for (i = 0; i < strlen(textA); i++) {
		pt[i] = textA[i];
	}
	pt[i] = '\0';
	// strcpy_s(pt, strlen(textA) + 1, textA); //pt의 위치에서, 주소 길이+1까지를 허용시키기고, textA의 값을 넘겨라 => null값 알아서 넣어줌.
										   // * pt = *textA; 이건 문자 하나 넘겨준것이라서 안됌.
	cout << pt << endl;

}// 문자열의 모든 함수에는 주소를 써야함


*/

#include <iostream>
#include <string>

using namespace std;

/*
Car class 를 정의하고 main() 에서 테스트하세요
- 모델명, 차량 색상, 가격의 관리가 가능합니다
  > char* : 모델명, 차량 색상
- 생성자, 복사생성자, setter.....

- 생성자에서 공간을 잘 만들었으면 주소값이 들어가고 아니면 null값이 처리된다.
*/


class Car {
private:
	char* model;
	char* color;
	int price;

public:
	// 받고
	Car(const char* molel = "node", const char* color = "none", int price = 0) {
		//this->model = new char[strlen(model) + 1];
		//if (this->model != NULL) // 동적할당이 제대로 진행되었을 때만 문자열을 넘겨라
		//	strcpy_s(this->model, strlen(model) + 1, model);

		//this->color = new char[strlen(color) + 1];
		//if (this->color != NULL)
		//	strcpy_s(this->color, strlen(color) + 1, color);

		this->model = this->color = NULL; // null로 초기화
		setModel(model);
		setColor(color);
		setPrice(price);
	}

	// 공간설정
	Car(const Car& arg) { // 레퍼런스로 받을려면 수정할 수 있는데, 그러면 안되니 수정하지 못하게 const를 붙여줘야 함
		
		//this->model = new char[strlen(arg.model) + 1]; // 공간 생성
		//if (this->model != NULL)
		//	strcpy_s(this->model, strlen(arg.model) + 1, arg.model);

		//this->color = new char[strlen(arg.color) + 1];
		//if (this->color != NULL)
		//	strcpy_s(this->color, strlen(arg.color) + 1, arg.color);


		this->model = this->color = NULL; // 초기화 시켜줘야 함.
		setModel(arg.model);
		setPrice(arg.price);
		setPrice(arg.price);
	}

	// 지우고
	~Car() {
		cout << this->model << " 삭제" << endl; // 굳이 안해도 되는데 이러면 잘 지워졌는지 알 수 있음.
		//if (this->model != NULL) // memberfield model에게 값이 있으면
		//	delete[] this->model; // 지워라
		//if (this->color != NULL)
		//	delete[] this->color;

		this->model = this->color = NULL;
		setModel(arg.model);
		setColor(arg.color);
		setPrice(arg.price);
	}

	//

	void setModel(const char* model) {
		if (this->model != NULL) // 이 두줄이 왜 있어야 한다고? 문자수가 똑같을 거라는 보장이 없으니까, 
			delete[] this -> model;
		this->model = new char[strlen(model) + 1];
		if (this->model != NULL)
			strcpy_s(this->model, strlen(model) + 1, model);
	}

	void setColor(const char* color) {
		if (this->color != NULL)
			delete[] this->color;
		this->color = new char[strlen(color) + 1];// 여기에 null이 들어왓다는 건 동적할당에 실패한것. 위치값 들어와야 동적할당 성공
		if (this->color != NULL)
			strcpy_s(this->color, strlen(color) + 1, color);
	}

	void setPrice(int price) {
		if (price >= 0)
			this->price = price; // memberfield price에게 price 값 넘기고
		else
			this->price = 0;
	}

	// 출력
	void carInfo() {
		cout << "----- 차 량 정 보 -----" << endl;
		cout << "모델명 : " << this->model << endl;
		cout << "색상   : " << this->color << endl;
		cout << "가격   : " << this->price << " 만원" << endl;
	}


};

int main() {

	Car* pA = new Car("그랜저", "black", 4500);
	Car* pB = new Car(*pA);

	pB->setModel("K7");

	pA->carInfo();
	pB->carInfo();

	delete pA; // 필요 없으면 지워라~
	delete pB;

}
