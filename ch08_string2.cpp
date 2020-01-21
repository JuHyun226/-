//ch08_string2_띄어쓰기 문자열입력.cpp

// string 객체에 띄어쓰기 있는 문자열 입력 => getline 함수 사용

int main() {

	string stn;
	cout << "문장입력 > ";
	getline(cin, stn); //cin객체와 입력객체를 같이 넘겨주면 됌.
	cout << stn < endl;
}
//------------------------------------------
or
string str;
cout << "string 입력: " << endl;
cin >> str;
cout << str << endl;

while (getchar() != '\n') {} // 반복문 수행으로 버퍼에 남은 '\n'을 비워주는 동작을 수행했음 -> getline로 문장 입력.
getline(cin, str, '\n'); // b/c '\n'이 나올 때까지 입력받도록 지정 => cin >> str 로 입력받을 때 버퍼에 '\n'이 남아있게 되기에,
								//while문 없이 getline수행시 아무것도 입력하지 않았지만 코드가 바로 넘어가게 됨
cout << str << endl;
//-------------------------------------------------------------


void ShowMessage(string message) {
	cout << message << endl;
}


bool AnswerCheck(string quiz, string answer) { //맞는지 틀린지만 보니까 bool
	if (quiz == answer)
		return true; //맞으면 true값 반환
	return false; //틀리면 false값 반환
}

int main() {

	ShowMessage("즐거운 하루 되세요..");
	
	string quiz = "dog";
	string answer;

	cout << "강아지 영어단어 입력" << endl;
	cout << "힌트: 첫글자(" << quiz[0] << ") > ";
	cin >> answer;

	if (AnswerCheck(quiz, answer)) {
		cout << "정답!" << endl;
	}
	else {
		cout << "틀렸어요" << endl;
	}
}

//실행결과
// Dog --> 틀렸어요, dog --> 정답!

