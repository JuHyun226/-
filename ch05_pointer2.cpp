// ch05_pointer2.cpp

/*
#include <stdio.h>

int main()
{
    int num1 = 10;
    char c1 = 'a';
    int *numPtr1 = &num1;
    char *cPtr1 = &c1;

    void *ptr;        // void 포인터 선언

    // 포인터 자료형이 달라도 컴파일 경고가 발생하지 않음
    ptr = numPtr1;    // void 포인터에 int 포인터 저장
    ptr = cPtr1;      // void 포인터에 char 포인터 저장

    // 포인터 자료형이 달라도 컴파일 경고가 발생하지 않음
    numPtr1 = ptr;    // int 포인터에 void 포인터 저장
    cPtr1 = ptr;      // char 포인터에 void 포인터 저장

    return 0;
}
*/

#include <iostream>

using namespace std;


// messageinput에 사용할 메시지를 보냄(데이터입력)
// messageinput의 자료형(매개변수)는 

// 주소를 넘기면 수정권한, 사용권한 둘다 있음. 그러니 값을 수정했던 거.
// 근데 데이터입력 문자열은 상수니까 수정하면 안 됌. 
// 문자열 상수"데이터입력"를 일반 char*로 받으면 안돼고, 싱수니까 수정권한을 const 를 붙혀서 뺏어야함.

int MessageInput(const char* message);

int main() {
	
	char stn[6] = "hello";
	// stn이라는 배열에 hello가 들어가 있는데 배열 출력할 때는 "주소값"을 쓰는 거!
	// 이때 한번만 부여해주는거고 그 뒤부터는 수정해주도록 쓰면 안됌. 배열명은 주소상수이기 때문에.
	// 그래서 함수로서 접근하라는 것. 
	printf("%p\n", stn);  // = cout << &stn << endl; //이 배열의 주소 나옴
	//윗 코드는 stack에 차배열을 만든거고 밑에는 문자열상수의 위치 주소를 가져다가 쓰는 것.


	const char* s = "hello";
	printf("%p\n", s); // 지금 프린트 쓰면 편리한 이유는 문자열상수할때 그냥 s를 쓰면 되니까.
	//s가 가진 게 hello라는 문자열상수가 있는 시작주소임.
	// 널문자 만들때까지 계속 출력하게 됨. 그래서 하나의 공간이 더 출력되는것.

	const char* t = "hello";
	printf("%p\n", t);
	//상수는 한군데 공간을 만들어 놓고 거기꺼 그대로 씀

	int vA = MessageInput("데이터 입력 > ");

}

void MessageInput(const char* message) {

}

// 모든 데이터는 메모리에 올라감, 데이터입력이라는 애도 문자열이니까 배열처리해서올라감
// 문자형 저장은 char형 배열이 만들어지니 거기에 주소를 보냄.
// 이는 수정가능한데 그러면 안되니까 const를 붙혀서 막음

//cout << v (주소: o, 문자열: x)

//--문자열에서는 널문자가 매우 중요. 널값 전까지 세고 스탑하기 때문-----------------


int MessageInput(const char* message);

int main() {

	char stn[] = "hello";
	stn[2] = '\0';
	cout << stn << endl;
// 이러면 문제가 짤림. 왜냐면 중간에 널문자 넣어버렸기 때문.
// 그러나 그 뒤의 데이터는 사라지지 않음. 전체를 바꾼게 아니라 하나만 인덱스로 바꿨기 때문
	cout << sizeof(stn) << endl;
	// 이러면 본래크기 그대로 유지하고 있다. 그러나 출력데이터만 널문자 중간에 나오기 전까지만 나온다는 것.

		int vA = MessageInput("데이터 입력 > ");

}
int MessageInput(const char* message) {
	return 1;
}


// 좀 더 좋은 방식임. 왜냐면 맨처음 만들었던 인풋데이터는 함수 다시 만들어서 새 내용 써야하기 때문--------



int MessageInput(const char* message);

int main() {

	int vA = MessageInput("데이터 입력 > ");
	cout << "vA : " << vA << endl;

	int vB = MessageInput("숫자 입력 > ");
	cout << "vB : " << vB << endl;
	//그때그때 설정해줘서 다른 내용이 나오도록 바꿀 수 잇음

}
int MessageInput(const char* message) {
	int value;
	cout << message;
	cin >> value;
	return value;
}}

// 입력받을 변수 만들고
//메세지 포인터 씀
// 데이터입력이 출력되서
//cin에서 value입력받고,
//해당값을 반환시켜라



//char 배열을 50개 만들기 => 상수는 수정 하면 안돼기에 const로 차단시켜라!

int main() {

	char word[50];
	InputString(word);

}

void InputString(char* stn) {

}

//배열로 넘어갔으니 무조건 포인터로 받아야함. 
// stn을가지고 저 배열에 넣을 수 있게 됨.
