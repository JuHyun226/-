//ch05_pointer3.cpp
//포인터 쓸 때는 어떤 대상을 쓰는지 정확히 알고 있어야 함.
//char 배열을 50개 만들기
#include <iostream>
#include <iomanip>
#include <cstring>
// c에서는 .을 붙혀서 c.헤더파일이었지만 얘는 그렇게 안 씀.
void InputString(char* stn);
void UpperString(char* stn);

int main() {

	char word[50];
	InputString(word);
	cout << word << endl;

	UpperString(word);
	cout << word << endl; // 소문자가 모두 대문자로 바뀜
}

void UpperString(char* stn) {
	for (int i = 0; i < strlen(stn); i++) {
		if (stn[i] >= 'a' && stn[i] <= 'z')
			stn[i] -= 32;
			//소문자인 현재값 -32는 대문자로 변환 가능
	}
}

void InputString(char* stn) {
	cout << "단어 입력 > ";
	cin >> stn;
}


//배열로 넘어갔으니 무조건 포인터로 받아야함. 
// stn을가지고 저 배열에 넣을 수 있게 됨.
//상수 수정 불가!


//---------------------------------------------------------
void UpperString(char* stn) {
	//for (int i = 0; i < strlen(stn); i++) {
	//	if (stn[i] >= 'a' && stn[i] <= 'z')
	//		stn[i] -= 32;
	//}

	cout << *stn << endl;
}

//여기서 *stn 출력하면 문자 하나 나옴. 왜냐면 이 주소가 가리키는 곳에 1바이트 값만 쓰라는 뜻
//포인터 없으면 널문자까지 출력하란 것.

//이렇게 응용 가능--------------------------------------------------
void UpperString(char* stn) {
	

	while (*stn != '\0') {
		if (*stn >= 'a' && *stn <= 'z')
			* stn -= 32;
		++stn; //주소값을 하나 올림 = 다음 인덱스의 주소 //주소는 연산이 되니 ++ 사용가능
	} //근데 얘는 함수를 쓰지 않음.
}

