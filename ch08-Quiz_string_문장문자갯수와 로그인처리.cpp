//ch08-Quiz_string_문장문자갯수와 로그인처리.cpp

#include <iostream>	
#include <string>

using namespace std;

string InputString(string message) {
	string value;
	cout << message;
	getline(cin, value);
	return value;
}

char InputChar(string message) {
	char value;
	cout << message;
	cin >> value;
	return value;
}

int SearchCount(string text, char search) {
	int count = 0;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == search)
			++count;
	}
	return count;
}

bool Login(string id, string pw) {
	for (int cnt = 0; cnt < 3; cnt++) { //로그인 시도 3번까지.
		string userId = InputString("ID 입력 > ");
		string userPw = InputString("PW 입력 > ");
		if (userId == id && userPw == pw)
			return true;
	}
	return false;
}

int main() {

	// 문장 하나를 입력받아서 반환하는 함수를 구현하세요
	// - 띄어쓰기 처리 가능
	// 위에 함수를 사용해서 string 객체 하나를 초기화합니다
	// 문자 하나를 입력받아서 반환하는 함수를 구현합니다
	// 위에 함수를 사용해서 문자 변수 1개를 초기화하고, 
	// 해당 문자가 string 객체 안에 몇개 있는지를 구하는 함수를 구현하세요
	string text = InputString("문장 입력 > ");
	cout << text << endl;
	char search = InputChar("검색 문자 입력 > ");
	int count = SearchCount(text, search);
	cout << search << " 문자수 : " << count << endl;

	// 로그인 처리하는 함수를 구현하세요
	// 입력 정보랑 저장된 값이랑 같은지 확인하면 됩니다
	// - 로그인 시도는 3회까지만 가능합니다
	//   Ex> 저장된 ID : test, PW : 1234
	//       ID 입력 > 
	//       PW 입력
	string id = "test";
	string pw = "1234";
	bool run = Login(id, pw);
	if (run) {
		cout << id << "로그인되었습니다" << endl;
	}
	else {
		cout << "아이디나 비번이 잘못되었습니다" << endl;
	}


}

