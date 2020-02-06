// ch25-Quiz_override.cpp

#include <iostream>	
#include <string>

using namespace std;

// Phone class 를 정의하세요
// - 필드 : 모델명
// - 기능 : 메시지 전송( 10 글자까지 가능 )

class Phone {
public:
	void sendMessage(const string& message) {
		if (message.length() < 11) {
			cout << "- 메시지 전송 완료 -" << endl;
		}
		else {
			cout << "- 10 글자까지 가능합니다 -" << endl;
		}
	}
	Phone(const string& model = "none") :model(model) {}
private:
	string model;
};


// Phone class 를 상속받는 SmartPhone class 를 정의하고 main()에서 테스트 하세요
// - 기능 : 메시지 전송( 50 글자까지 가능 )

class SmartPhone : public Phone {
public:
	void sendMessage(const string& message) {
		if (message.length() < 11) {
			cout << "- 문자 전송 완료 -" << endl;
		}
		else if (message.length() < 51) {
			cout << "- MMS 변환 전송 완료 -" << endl;
		}
		else {
			cout << "- 50 글자 이하로 작성하세요 -" << endl;
		}
	}
	SmartPhone(const string& model = "none") : Phone(model) {}
};


int main() {

	Phone* phone = new Phone("폴더폰");
	phone->sendMessage("0123456789");
	phone->sendMessage("01234567891");
	delete phone;

	SmartPhone* sp = new SmartPhone("LG G5");
	sp->sendMessage("0123456789");
	sp->sendMessage("012345678912");
	sp->sendMessage("012345678912askl;djfkl;asj;dklfjaskl;dfkl;jaskl;jdf;ajlskjdf");
}
