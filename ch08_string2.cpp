//ch08_string2.cpp

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
