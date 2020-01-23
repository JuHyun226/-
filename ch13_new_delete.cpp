/*
	ch13_new_delete.cpp
*/

// stack 순서 때문에 Main --> FuncA --> FuncB가 실행되었으면 종료될 때는 역순으로 실행되어 종료됨. 앞에것이 종료되지 않았는데 나갈 수 없음.

/*
High adress: stack --> heap --> data -->code : Low adress

- stack: 지역변수 및 매개변수가 저장되는 영역
> 함수 호출시 메모리에 생성되고, 함수종료시 메모리에서 삭제됨
> 프로그램 작성시 모두 결정되고, 프로그램 운용중에는 이용할 수 없다

- Heap: 프로그램 운용 중에 사용자의 필요에 의해 이용할 수 있는 영역
> 동적할당처리과정을 통해 통행생성됨. 변수의 이름이 아닌 주소로 접근해야 하기에 포인터 사용
> 프로그램 종료 전 또는 함수 종료시에도 영역이 사라지지 않아서, 사용하는 부분은 영역 해제(삭제)처리를 해줘야 함

- Data: 전역변수 및 정적변수가 저장되는 영역: 프로그램 전까지 유지됨.

- CODE: 프로그래머가 작성한 언어들을 기계어로 변환하여 보유하고 있는 영역
*/

#include <iostream>

using namespace std;

/*
new 자료형  : cpp 동적 할당 요청 - int면 4바이트 생성해주세요 요청 -> 시작 주소값을 반환함 --> int pointer 변수가 그래서 필요 (*p) 
종료시 지역변수는 함수종료시 스택에서 빠져나가지만, 스택이 만들지 않은 얘(Heap 메모리)는 남는다. 얘는 사용도 삭제도 못해서 memory loss가 됨.
그러니 지우기 전까지는 그 위치를 까먹으면 안됌.

delete 위치 : cpp 동적 할당 해제
*/

void MemoryTest() {

	int value = 10;

	int* p = new int;
	*p = 10;

}

int main() {

	MemoryTest();

}
//--------------------------------------
class Alloc {
public:

	int* Integer() { return new int; }
	double* Floating() { return new double; }
	char* Character() { return new char; }

};

int main() {

	Alloc make;

	int* pA = make.Integer();
	*pA = 10;
	cout << "*pA : " << *pA << endl;

	double* pD = make.Floating(); //MAKE 객체에 FLOATING 메소드 호출
	*pD = 2.2;
	cout << "*pD : " << *pD << endl; // 잘 들어갔나 확인

	char* pC = make.Character();
	*pC = 'A';
	cout << "*pC : " << *pC << endl;


	Data* pob = new Data;
	pob->a = 11;
	pob->b = 3.3;
	pob->info();//pob의 해당 데이터 호출


	delete pob;
	delete pC;
	delete pD; // 필요없으면 지워라.
	delete pA;

}

//-----------동적할당은 안쓸거면 공간을 지워라. 위치 잊으면 지울 수 없다.--------------------------

char* InputString() {
	char data[20];
	cout << "단어 입력 > "; cin >> data;

	char* tmp = new char[strlen(data) + 1]; // heap으로 넘기는 법 => char pointer니까 메모리는 필요한 만큼만 쓰고,
			// 배열에 동적할당할 때는 배열임을 뜻하는 [] 사용, 할당할 바이트 단위 붙이기(데이터 배열에 있는 만큼의 + 1 = strlen + 1 )
	strcypy_s(tmp, strlen(data) + 1, data);
	//지금 데이터 배열은 string class아니니 문자열 함수 따로 써야함.
	return tmp; //위치 반환

	// return data; 는 지역변수의 공간을 사용한것이기에 error. 
}
int Menu(string message) {
	int select;
	cout << message; cin >> select;
	return select;
}

int main() {
	char* word = NULL;

	while (true) {
		int select = Menu("1.입력  2.출력 > ");

		switch (select) {
		case 1: // 입력
			if (word != NULL)
				delete[] word; // null값이 아니면 데이터가 있다는 뜻이니까 지우고 가라! = 사용하지 않는 공간은 지워!
			word = InputString();
			break;
		case 2: // 출력
			cout << word << endl;
			break;
		case 0:
			delete[] word;//배열일 경우에는 대괄호 기호[]필요
			cout << "- end -" << endl;  // word가 잘 알고 있는지 확인해보면 앎.
			return 0;
		default:
			cout << "선택 오류~" << endl;
		}
		
		  
}

// 종료후에도 사용하고 싶으면 heap으로 넘기기
// 그럴려면 char* 필요, 
