//ch05_구조체.cpp

//데이터 하나 저장시 변수, 여러개는 배열, 여러 배열까지 다 묶어서 쓰면 구조체
//struct 구조체 만들겠습니다~ data는 구조체 이름

struct Data {
	int a;
	double b;
};

int main() {

	Data value;

	SetData(&value); // 주소(&value) 니까 사용도, 수정도 가능!

		//데이터를 쓰기만 할거면 변수의 값 넘기고, 아니면 주소를 넘길것.
		//SetData(value); 하면 값만 받으니까 수정을 못함
	
	//구조체 Data, 변수 value를 만들면 c였으면 error, b/c 일반 변수가지고 못만듬 그래서 새로 정의 but c+ allows it

	/*c였으면 error
typedefstruct Data {
	int a;
	... 
	해서 새로 정의가 필요 
	*/

}

//--------------------------------------------------

struct Data {
	int a;
	double b;
};

void SetData(Data* arg);
void ShowData(Data arg);

int main() {

	Data value;

	SetData(&value);
	ShowData(value); // 수정해도 좋도록 값 받게 함. 근데 메모리 생각하면 주소넘기는게 나음
	// 크기가 12byte
	// 포인터는 주소로 넘어가면 기본인 4byte. => 포인터로 다루면 크기가 작아짐. 4바이트만 있으면 되니까.
}

void ShowData(Data arg) {
	cout << arg.a << ", " << arg.b << endl;
} //어떤 공간안의 값을 쓸 때는 .을 쓰게 되어있다. java도. c+를 계승했기 때문에.

void SetData(Data* arg) {
	cout << "숫자 입력 > ";
	//1. enter the number
	
	// cin >> (*arg).a; // 참조연산 먼저하라고 괄호를 때리던가
	cin >> arg->a; //이걸(->) 쓰면 됨. 위에께 불편하니까.
	//cin >> *(arg.a); // pointer 변수안에는 member가 없고 주소만 있다. member는 value에 가야 있음.
	// 포인터 연산(간접참조연산) but *arg.a는 error => 포인터보다 멤버참조연산자가 우선

	cout << "실수 입력 > ";
	cin >> arg->b;	// arg가 가리키는 걸 b에게 입력해라


}




