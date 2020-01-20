/*
	ch08_string.cpp
*/

#include <iostream>

using namespace std;

int main() {

	char word[10];
	cout << "단어 입력 > ";
	cin >> word;
	cout << "word : " << word << endl; 
	cout << endl;
	// c 는 띄어쓰기가 있는 데이터를 입력할 수 없다.

	char stn[50];
	cout << "문장 입력 > ";

	char stn[50];
	cout << "문장 입력 > ";
	cin.ignore(10, '\n'); //10글자까지 무시하다가 \n(=엔터)을 만나면 멈춰라.
	cin.getline(stn, sizeof(stn), '\n');//stn의 값을 50글자까지 저장하지만 중간에 엔터 만나면 거기서 멈춰라.
	cout << "stn : " << stn << endl;

}

//class로부터 만들어진 애가 객체, 그 안에는 필드값도 있지만, 함수도 들어감
//공간에 들어가려면 .을 찍음

//getline함수는 띄어쓰기 처리함: 
// 입력위치를 넘겨줌(stn에.)
// 허용크기를 stn의 크기만큼.

// \n으로 데이터를 구분함. 최대 50글자까지. 실제 허용되는건 49글자.
// 버퍼의 값이 뒤의 타입과 맞으면 가져다 쓰는데, 굿 넘어가면 버퍼에 엔터 남아있으니까 그걸 가져다 씀.


//cin.getline 함수

char stn[50]; 
cout << "문장 입력 > ";
cin.ignore(10, '\n');
cin.getline(stn, sizeof(stn), 'e'); //sizeof(stn)을 5라고 하면 5byte까지 밖에 처리 안됌. -> 4영문자.
cout << "stn : " << stn << endl;

// e 전까지만 처리함. 진행을 어디까지 할건지 알려줌.

// class는 구조체와 달리 함수도 들어가서 더 좋은 거얌.
// 코드를 클래스로 돌릴것.



//-----------------------------

#include <string> //.h랑 다름. 

/*
string class
- cpp에서 문자열 관련 데이터를 편리하게 처리해주는 class 입니다
  > 'string' 헤더파일을 추가해야 함. 

*/


int main() {

	string stn = "cpp";
	cout << "stn : " << stn << endl;

	stn = "수정가능";
	cout << "stn : " << stn << endl;

	stn = "abcde";
	cout << "stn : " << stn << endl;
	cout << "stn[0] : " << stn[0] << endl;
	cout << "stn 크기 : " << stn.capacity() << endl;

}

//문자열을 변수다루듯이 하면 됌


//5개 들어가는데 stn 크기가 15개임. 메모리 공간의 소모가 심함.


int main() {

	string stn = "cpp";
	cout << "stn : " << stn << endl;

	stn = "수정가능";
	cout << "stn : " << stn << endl;

	stn = "abcde";
	cout << "stn : " << stn << endl;
	cout << "stn[0] : " << stn[0] << endl;
	cout << "stn 크기 : " << stn.capacity() << endl;
	stn = "0123456789123456";
	cout << "stn 크기 : " << stn.capacity() << endl;
	// 이렇게 하면, 하나가 오버되는데 16개를 늘려버려서 stn 크기가 31이 됌. 공간소모 심함.

}
